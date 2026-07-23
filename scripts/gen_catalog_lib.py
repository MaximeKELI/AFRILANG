#!/usr/bin/env python3
"""Shared helpers for stdlib catalog code generation."""

from __future__ import annotations
import json
import os
from typing import Callable

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Version du schéma du catalogue JSON externalisé. À incrémenter en cas de
# changement de format. Doit correspondre à `kComplexCatalogVersion` dans
# include/afrilang/complex_catalog.hpp (garde-fou anti-skew binaire/catalogue).
CATALOG_JSON_VERSION = 1

RESERVED_CPP = {
    "template", "class", "new", "delete", "private", "public", "protected",
    "namespace", "return", "switch", "case", "default", "try", "catch",
    "throw", "while", "for", "if", "else", "do", "struct", "union", "enum",
    "typedef", "using", "virtual", "override", "const", "static", "extern",
    "inline", "operator", "this", "friend", "mutable", "volatile", "register",
    "asm", "goto", "break", "continue", "sizeof", "alignas", "alignof",
    "decltype", "typeid", "export", "module", "import", "concept", "requires",
    "co_await", "co_return", "co_yield", "typename",
}


def cpp_type(t: str) -> str:
    if t == "number":
        return "double"
    if t == "text":
        return "std::string"
    if t == "bool":
        return "bool"
    if t == "list number":
        return "std::vector<double>"
    if t == "list text":
        return "std::vector<std::string>"
    return "auto"


def gen_runtime(modules: list[tuple], ns_prefix: str) -> str:
    parts = [
        "#pragma once",
        "",
        "#include <algorithm>",
        "#include <cctype>",
        "#include <chrono>",
        "#include <cmath>",
        "#include <cstdlib>",
        "#include <iomanip>",
        "#include <map>",
        "#include <numeric>",
        "#include <sstream>",
        "#include <string>",
        "#include <vector>",
        "",
    ]
    for import_name, use_name, funcs in modules:
        assert use_name not in RESERVED_CPP, use_name
        parts.append(f"namespace afrilang::runtime::{ns_prefix}::{use_name} {{")
        for fname, ret, params, body in funcs:
            args = ", ".join(f"{cpp_type(pt)} {pn}" for pn, pt in params)
            rtype = "void" if not ret else cpp_type(ret)
            parts.append(f"inline {rtype} {fname}({args}) {{ {body} }}")
        parts.append("} // namespace")
        parts.append("")
    return "\n".join(parts)


def gen_catalog_cpp(
    modules: list[tuple],
    array_name: str,
    count_name: str,
    find_fn: str,
    is_fn: str,
    header_field: str,
) -> str:
    lines = [
        '#include "afrilang/stdlib_catalog.hpp"',
        "",
        "namespace afrilang {",
        "namespace {",
        "",
    ]
    mod_idx = 0
    for import_name, use_name, funcs in modules:
        lines.append(f"const StdlibParamSpec kMParams_{mod_idx}[] = {{")
        for _fname, _ret, params, _body in funcs:
            for pn, pt in params:
                lines.append(f'    {{"{pn}", "{pt}"}},')
        lines.append("    {nullptr, nullptr}")
        lines.append("};")
        lines.append("")
        lines.append(f"const StdlibFuncSpec kMFuncs_{mod_idx}[] = {{")
        poff = 0
        for fname, ret, params, _body in funcs:
            lines.append(
                '    {"' + fname + '", "' + ret + '", ' + str(len(params)) +
                f', &kMParams_{mod_idx}[{poff}]' + '},'
            )
            poff += len(params)
        lines.append("    {nullptr, nullptr, 0, nullptr}")
        lines.append("};")
        lines.append("")
        mod_idx += 1

    lines.append(f"const StdlibModuleSpec {array_name}[] = {{")
    for i, (import_name, use_name, funcs) in enumerate(modules):
        lines.append(
            f'    {{"{import_name}", "{use_name}", kMFuncs_{i}, '
            f'{len(funcs)}, "{header_field}", false}},'
        )
    lines.append("    {nullptr, nullptr, nullptr, 0, nullptr, false}")
    lines.append("};")
    lines.append("")
    lines.append(f"const std::size_t {count_name} = {len(modules)};")
    lines.append("")
    lines.append("} // namespace")
    lines.append("")
    lines.append(f"const StdlibModuleSpec* {find_fn}(const std::string& name) {{")
    lines.append(f"    for (std::size_t i = 0; i < {count_name}; ++i) {{")
    lines.append(f"        if (name == {array_name}[i].importName || name == {array_name}[i].moduleName)")
    lines.append(f"            return &{array_name}[i];")
    lines.append("    }")
    lines.append("    return nullptr;")
    lines.append("}")
    lines.append("")
    lines.append(f"bool {is_fn}(const std::string& name) {{")
    lines.append(f"    return {find_fn}(name) != nullptr;")
    lines.append("}")
    lines.append("")
    lines.append("} // namespace afrilang")
    return "\n".join(lines)


def gen_catalog_json(
    modules: list[tuple],
    header_field: str,
    version: int = CATALOG_JSON_VERSION,
) -> str:
    """Émet le catalogue sous forme JSON compacte (miroir de StdlibModuleSpec).

    Schéma :
        {"version": N, "runtimeHeader": "...",
         "modules": [{"import": "..", "name": "..",
                      "funcs": [{"n": "..", "r": "..",
                                 "p": [["pn", "pt"], ...]}]}]}
    """
    mods = []
    for import_name, use_name, funcs in modules:
        fl = []
        for fname, ret, params, _body in funcs:
            fl.append({
                "n": fname,
                "r": ret or "",
                "p": [[pn, pt] for pn, pt in params],
            })
        mods.append({"import": import_name, "name": use_name, "funcs": fl})
    doc = {"version": version, "runtimeHeader": header_field, "modules": mods}
    return json.dumps(doc, ensure_ascii=False, separators=(",", ":"))


def gen_afr_stubs(modules: list[tuple], subdir: str) -> None:
    base = os.path.join(ROOT, "stdlib", subdir)
    os.makedirs(base, exist_ok=True)
    header = "// experimental catalog — IDE signatures only (not core runtime)"
    for import_name, use_name, funcs in modules:
        path = os.path.join(base, f"{import_name}.afr")
        lines = [header, f"module {use_name}", ""]
        for fname, ret, params, _ in funcs:
            ps = ", ".join(f"{pn} {pt}" for pn, pt in params)
            if ret:
                lines.append(f"function {fname}({ps}) returns {ret}")
            else:
                lines.append(f"function {fname}({ps})")
            lines.append("end")
            lines.append("")
        lines.append("end")
        lines.append("")
        with open(path, "w", encoding="utf-8") as f:
            f.write("\n".join(lines).rstrip() + "\n")


def gen_docs(modules: list[tuple], title: str, import_prefix: str, out_path: str) -> None:
    lines = [f"# {title}", "", f"**{len(modules)} modules** — `{import_prefix}{{nom}}`", ""]
    for import_name, use_name, funcs in modules:
        lines.append(f"## {import_prefix}{import_name}")
        lines.append("")
        lines.append(f"`import \"{import_prefix}{import_name}\"` · `use {use_name}`")
        lines.append("")
        for fname, ret, params, _ in funcs:
            ps = ", ".join(f"{pn} {pt}" for pn, pt in params)
            sig = f"{fname}({ps})"
            if ret:
                sig += f" → {ret}"
            lines.append(f"- `{sig}`")
        lines.append("")
    with open(os.path.join(ROOT, out_path), "w", encoding="utf-8") as f:
        f.write("\n".join(lines))

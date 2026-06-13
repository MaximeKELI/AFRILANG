# AFRILANG Changelog

## Unreleased

### Language
- **flatMap each** — `flatMap each x in list do return list of ... end`
- **reduce text** — `reduce` naturel sur listes de `text`
- **Listes polymorphes** — `list of Animal` avec `unique_ptr` et sous-types
- **Classes génériques** — `class Box<T>`, `new Box<number>(42)`
- **POO avancée** — `final`, `property`, `destroy`, `super`, `static`, `abstract`, `protected`
- **Lambdas** — `function(x number) returns number ... end` as expression
- **map / filter / reduce** — syntaxe naturelle + `std/collections`
- **Default parameters**, **for from/to/step**, **const**, **maps**, **exceptions**, **interpolation**

### Standard library
- `std/args` — count, at, all (arguments CLI)
- `std/path` — join, basename, dirname, extension, isAbsolute
- `std/collections` — map/filter/reduce/flatMap, sort, reverse, contains, indexOf, sum
- `std/str`, `std/log`, `std/math`, `std/time`, `std/re`, `std/http`, `std/fs`, `std/io`, `std/json`

### Tooling
- **REPL v2** — `:load`, `:type`, `:run`, `:history`, `:paste`
- `afrilang lint`, `afrilang doc`
- Extension VS Code 0.5.0 — coloration POO + list ops

### Examples
- `phase11_demo.afr` — démo complète phase 11
- `polymorphic_list.afr`, `generic_class.afr`, `poo_advanced.afr`, `args_path_demo.afr`

## 0.4.0

Initial POO, natural list ops, VS Code extension prep.

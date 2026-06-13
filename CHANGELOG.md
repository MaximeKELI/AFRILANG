# AFRILANG Changelog

## Unreleased

### Language
- **Maps** — `map of "k" to v`, `empty map text to number`, indexing with `at`
- **Exceptions** — `try` / `catch error e` / `raise`
- **String interpolation** — `"Hello {name}"`
- **for each key, value in map** — iterate maps with two variables

### Standard library
- `std/str` — trim, contains, replace, split, join
- `std/log` — info, warn, error
- `std/math` — abs, floor, ceil, pow, random
- `std/time` — now, formatTimestamp
- `std/re` — match, replace (regex)
- `std/http` — httpPost added

### Tooling
- `afrilang lint` — static analysis entry point
- `afrilang doc` — Markdown documentation generator

### Examples
- `examples/maps.afr`, `examples/exceptions.afr`, `examples/phase9_demo.afr`

## Prior releases
- Generics on functions, enums/match, null-safety, LSP, pkg registry, playground

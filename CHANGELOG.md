# AFRILANG Changelog

## Unreleased

### Language
- **Default parameters** — `function f(x number, y number = 0)`
- **Numeric for loops** — `for i from 1 to 10 do` / `step 2`
- **Constants** — `create const NAME = value`
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
- `std/collections` — sortNumbers, sortText, reverse, contains, indexOf, sum

### Tooling
- `afrilang lint` — static analysis entry point
- `afrilang doc` — Markdown documentation generator

### Examples
- `examples/maps.afr`, `examples/exceptions.afr`, `examples/phase9_demo.afr`
- `examples/defaults.afr`, `examples/phase10_demo.afr`

## Prior releases
- Generics on functions, enums/match, null-safety, LSP, pkg registry, playground

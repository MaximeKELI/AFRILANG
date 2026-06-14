# AFRILANG Changelog

## Unreleased

### Language
- **Syntaxe bilingue FR/EN** — alias français (`dire`, `si`, `fin`, `fonction`, `cas`, `defaut`, …)
- **Modules export/private** — `export function`, `private function`, appel qualifié `Module.fn`
- **Génériques explicites** — `identity<number>(42)`
- **Match avec liaison** — `case Error with msg then`
- **Match en expression** — `create x = match e then case Ok then "ok" end end`
- **Unions taguées** — `union Shape` (alias de `enum` avec payload)
- **Surcharge d'opérateurs** — `operator + (other Vector) returns Vector` dans les classes
- **Interfaces / traits** — vérification de signature, variables `Speakable`, `list of Speakable`
- **Enums dans modules** — `module M` peut contenir `enum`
- **Interfaces graphiques** — fenêtres SDL2, texte, boutons (`open window`, `draw text`, `button ... is clicked`)
- **async / await (complet)** — `returns T or error`, await dans tests, scheduler + thread pool
- **flatMap each** — `flatMap each x in list do return list of ... end`
- **reduce text** — `reduce` naturel sur listes de `text`
- **Listes polymorphes** — `list of Animal` avec `unique_ptr` et sous-types
- **Classes génériques** — `class Box<T>`, `new Box<number>(42)`
- **POO avancée** — `final`, `property`, `destroy`, `super`, `static`, `abstract`, `protected`
- **Lambdas** — `function(x number) returns number ... end` as expression
- **map / filter / reduce** — syntaxe naturelle + `std/collections`
- **Default parameters**, **for from/to/step**, **const**, **maps**, **exceptions**, **interpolation**

### Standard library
- **151 bibliothèques simples** — maths, texte, conversions (`import "std/nom"`)
- **102 bibliothèques moyennes** — stats, listes, dates, URL, finance (`import "std/m/nom"`)
- **210 bibliothèques complexes** — graphes, ML, crypto, simulation (`import "std/c/nom"`)
- `std/ui` — openWindow, drawText, drawButton, showFrame (SDL2)
- `std/async` — sleep(ms) via scheduler (timers)
- `std/http` — httpGetAsync, httpPostAsync (thread pool)
- `std/io` — readFileAsync
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
- `async_demo.afr` — async/await + std/async
- `async_full.afr` — async + Result + tests await + scheduler
- `traits_demo.afr` — interfaces, listes polymorphes, enum en module, match exhaustif
- `gui_demo.afr` — interface graphique SDL2
- `polymorphic_list.afr`, `generic_class.afr`, `poo_advanced.afr`, `args_path_demo.afr`

## 0.4.0

Initial POO, natural list ops, VS Code extension prep.

"""Pages documentation méthodique (testing, wasm, contributing, stdlib, tooling, spec, advanced)."""

from .docs_pages import _page, callout, code, h2, p, table, ul


def testing_page():
    return _page(
        "testing",
        "Tests",
        "Testing",
        "Méthode complète : assert, tests/, afrilang test, --specs, --examples, pkg test, couverture.",
        "Full method: assert, tests/, afrilang test, --specs, --examples, pkg test, coverage.",
        [
            callout("<strong>Objectif</strong> — Valider le langage et votre projet avec des suites reproductibles."),
            h2("1. Anatomie d'un test"),
            code(
                "function double(n number) returns number\n"
                "    return n * 2\n"
                "end\n\n"
                'test "function call"\n'
                "    assert double(21) is equal to 42\n"
                "end"
            ),
            ul(
                [
                    "Les <code>function</code> utilitaires sont <strong>hors</strong> des blocs <code>test</code>",
                    "<code>assert expr</code> où expr est souvent <code>… is equal to …</code>",
                ]
            ),
            h2("2. Modes CLI (méthode)"),
            table(
                ["Commande", "Quoi"],
                [
                    ["<code>afrilang test</code> (dans un projet)", "Découvre <code>tests/**/*.afr</code>"],
                    ["<code>afrilang test --examples .</code>", "Suite demos <code>examples/</code> (CI)"],
                    ["<code>afrilang test --specs .</code>", "<code>tests/specs</code> + <code>tests/stdlib</code>"],
                    ["<code>afrilang pkg test</code>", "Self-install paquet + ses tests"],
                    ["<code>afrilang test --coverage</code>", "Couverture (si supporté)"],
                ],
            ),
            h2("3. Specs compilateur (Testament-style)"),
            p(
                "Depuis la racine du dépôt : <code>afrilang test --specs .</code> — "
                "langage de base, optionnels/Result, stdlib core (<code>str</code>, <code>math</code>, "
                "<code>json</code>, collections)."
            ),
            h2("4. Projet applicatif"),
            code(
                "afrilang init mon_app\n"
                "cd mon_app\n"
                "afrilang pkg add math\n"
                "afrilang pkg install\n"
                "afrilang test",
                "Terminal",
            ),
            h2("5. Checklist avant PR"),
            ul(
                [
                    "<code>afrilang test --specs .</code> vert",
                    "Exemples touchés : <code>afrilang run examples/…</code>",
                    "Si paquet : <code>afrilang pkg test</code>",
                ]
            ),
            callout("Voir aussi <a href=\"/docs/tooling/\">Outils</a> et <a href=\"/docs/contributing/\">Contribuer</a>."),
        ],
        [
            callout("<strong>Goal</strong> — Validate the language and your project with reproducible suites."),
            h2("1. Anatomy of a test"),
            code(
                "function double(n number) returns number\n"
                "    return n * 2\n"
                "end\n\n"
                'test "function call"\n'
                "    assert double(21) is equal to 42\n"
                "end"
            ),
            ul(
                [
                    "Helper <code>function</code>s go <strong>outside</strong> <code>test</code> blocks",
                    "<code>assert expr</code> is often <code>… is equal to …</code>",
                ]
            ),
            h2("2. CLI modes (method)"),
            table(
                ["Command", "What"],
                [
                    ["<code>afrilang test</code> (in a project)", "Discovers <code>tests/**/*.afr</code>"],
                    ["<code>afrilang test --examples .</code>", "Demo suite <code>examples/</code> (CI)"],
                    ["<code>afrilang test --specs .</code>", "<code>tests/specs</code> + <code>tests/stdlib</code>"],
                    ["<code>afrilang pkg test</code>", "Self-install package + its tests"],
                    ["<code>afrilang test --coverage</code>", "Coverage (when supported)"],
                ],
            ),
            h2("3. Compiler specs (Testament-style)"),
            p(
                "From the repo root: <code>afrilang test --specs .</code> — "
                "language basics, optionals/Result, core stdlib."
            ),
            h2("4. Application project"),
            code(
                "afrilang init my_app\n"
                "cd my_app\n"
                "afrilang pkg add math\n"
                "afrilang pkg install\n"
                "afrilang test",
                "Terminal",
            ),
            h2("5. Pre-PR checklist"),
            ul(
                [
                    "<code>afrilang test --specs .</code> green",
                    "Touched examples: <code>afrilang run examples/…</code>",
                    "If package: <code>afrilang pkg test</code>",
                ]
            ),
            callout('See also <a href="/docs/tooling/">Tooling</a> and <a href="/docs/contributing/">Contributing</a>.'),
        ],
    )


def wasm_page():
    return _page(
        "wasm",
        "WASM & JS",
        "WASM & JS",
        "Matrice de compatibilité wasm32, playground JS, demos CI — méthode claire.",
        "wasm32 compatibility matrix, JS playground, CI demos — clear method.",
        [
            callout("<strong>Objectif</strong> — Savoir ce qui tourne en WASM / playground, et ce qui reste natif."),
            h2("1. Cible wasm32"),
            code("afrilang run examples/tier8_demo.afr --target wasm32 --run", "Terminal"),
            p("Nécessite Emscripten (<code>emsdk</code>) dans le PATH."),
            h2("2. Fonctionne en WASM"),
            table(
                ["Domaine", "Contenu"],
                [
                    ["Langage", "variables, fonctions, boucles, if, listes, maps"],
                    ["POO", "classes, héritage, interfaces"],
                    ["Stdlib core", "json, str, math, collections, args, path, log"],
                    ["Async", "sleep / coroutines (Emscripten)"],
                    ["CI", "tier8_demo.afr, tier8_stdlib.afr"],
                ],
            ),
            h2("3. Natif uniquement"),
            table(
                ["Domaine", "Raison"],
                [
                    ["std/ui, SDL2", "pas de fenêtre native navigateur"],
                    ["game2d / game3d", "OpenGL / SDL"],
                    ["http sync, fs fichiers", "sockets / disque"],
                    ["thread, gamenet UDP", "POSIX / réseau"],
                ],
            ),
            h2("4. Playground JS (compile-js)"),
            ul(
                [
                    "Autorisé : say, assign/set, if/while/repeat/for, fonctions + return",
                    "Exclus : imports, classes, async, UI, tests",
                ]
            ),
            h2("5. Recommandation"),
            ul(
                [
                    "Playground / CI WASM : petits programmes ; str/math/json OK",
                    "Jeux, SIG, data science : cible native",
                ]
            ),
            callout("Référence dépôt : <code>docs/WASM_COMPAT.md</code>."),
        ],
        [
            callout("<strong>Goal</strong> — Know what runs under WASM / playground vs native-only."),
            h2("1. wasm32 target"),
            code("afrilang run examples/tier8_demo.afr --target wasm32 --run", "Terminal"),
            p("Requires Emscripten (<code>emsdk</code>) on PATH."),
            h2("2. Works in WASM"),
            table(
                ["Domain", "Content"],
                [
                    ["Language", "variables, functions, loops, if, lists, maps"],
                    ["OOP", "classes, inheritance, interfaces"],
                    ["Core stdlib", "json, str, math, collections, args, path, log"],
                    ["Async", "sleep / coroutines (Emscripten)"],
                    ["CI", "tier8_demo.afr, tier8_stdlib.afr"],
                ],
            ),
            h2("3. Native only"),
            table(
                ["Domain", "Why"],
                [
                    ["std/ui, SDL2", "no native browser window"],
                    ["game2d / game3d", "OpenGL / SDL"],
                    ["sync http, fs files", "sockets / disk"],
                    ["thread, gamenet UDP", "POSIX / network"],
                ],
            ),
            h2("4. JS playground (compile-js)"),
            ul(
                [
                    "Allowed: say, assign/set, if/while/repeat/for, functions + return",
                    "Excluded: imports, classes, async, UI, tests",
                ]
            ),
            h2("5. Recommendation"),
            ul(
                [
                    "Playground / CI WASM: small programs; str/math/json OK",
                    "Games, GIS, data science: native target",
                ]
            ),
            callout("Repo reference: <code>docs/WASM_COMPAT.md</code>."),
        ],
    )


def contributing_page():
    return _page(
        "contributing",
        "Contribuer",
        "Contributing",
        "Méthode contributeur : clone, build, tests, conventions, PR, documentation.",
        "Contributor method: clone, build, tests, conventions, PR, documentation.",
        [
            callout("<strong>Objectif</strong> — Proposer un changement qui passe CI et respecte le parcours produit."),
            h2("1. Préparer l'environnement"),
            ul(
                [
                    "Suivre <a href=\"/docs/getting-started/\">Premiers pas</a>",
                    "Fork + branche thématique",
                    "Lire <code>docs/ROADMAP.md</code> (vagues livrées)",
                ]
            ),
            h2("2. Boucle de validation (obligatoire)"),
            code(
                "cmake --build build -j$(nproc)\n"
                "cd build && ctest --output-on-failure -R compiler_unit_tests\n"
                "cd .. && ./build/afrilang test --specs .\n"
                "# si exemples touchés :\n"
                "./build/afrilang test --examples .",
                "Terminal",
            ),
            h2("3. Conventions code"),
            ul(
                [
                    "C++17/20 aligné sur le style existant",
                    "Stdlib core : runtime + tests avant promesse API",
                    "Catalogues générés = expérimentaux (voir <a href=\"/docs/stdlib/\">Stdlib</a>)",
                    "Pas de secrets dans les commits",
                ]
            ),
            h2("4. Documentation"),
            ul(
                [
                    "Guide site : <code>web/core/content/docs_*.py</code> (FR + EN)",
                    "Référence dépôt : <code>docs/LANGUAGE.md</code>, <code>PKG.md</code>, …",
                    "Toute page web doit rester bilingue",
                ]
            ),
            h2("5. PR"),
            ul(
                [
                    "Résumé : pourquoi + parcours utilisateur impacté",
                    "Checklist tests dans la description",
                    "CI verte (build, unit, examples/specs selon le changement)",
                ]
            ),
            callout("Licence MIT — issues et PR sur GitHub MaximeKELI/AFRILANG."),
        ],
        [
            callout("<strong>Goal</strong> — Propose a change that passes CI and respects the product path."),
            h2("1. Prepare the environment"),
            ul(
                [
                    'Follow <a href="/docs/getting-started/">Getting started</a>',
                    "Fork + topical branch",
                    "Read <code>docs/ROADMAP.md</code>",
                ]
            ),
            h2("2. Validation loop (required)"),
            code(
                "cmake --build build -j$(nproc)\n"
                "cd build && ctest --output-on-failure -R compiler_unit_tests\n"
                "cd .. && ./build/afrilang test --specs .\n"
                "./build/afrilang test --examples .",
                "Terminal",
            ),
            h2("3. Code conventions"),
            ul(
                [
                    "C++17/20 matching existing style",
                    "Core stdlib: runtime + tests before API promises",
                    "Generated catalogs = experimental",
                    "No secrets in commits",
                ]
            ),
            h2("4. Documentation"),
            ul(
                [
                    "Site guide: <code>web/core/content/docs_*.py</code> (FR + EN)",
                    "Repo reference: <code>docs/LANGUAGE.md</code>, <code>PKG.md</code>, …",
                    "Every web page must stay bilingual",
                ]
            ),
            h2("5. PR"),
            ul(
                [
                    "Summary: why + impacted user journey",
                    "Test checklist in the description",
                    "Green CI",
                ]
            ),
            callout("MIT license — issues and PRs on GitHub MaximeKELI/AFRILANG."),
        ],
    )


def stdlib_page():
    return _page(
        "stdlib",
        "Bibliothèque standard",
        "Standard library",
        "Méthode : core stabilisé vs catalogues générés, imports, API prioritaire, navigation.",
        "Method: stabilized core vs generated catalogs, imports, priority API, browsing.",
        [
            callout(
                "<strong>Règle d'or</strong> — Préférez les modules <strong>core</strong> "
                "(runtime C++ réel). Les catalogues générés sont expérimentaux."
            ),
            h2("1. Deux couches"),
            table(
                ["Couche", "Où", "Garantie"],
                [
                    ["Core", "<code>runtime/*.hpp</code> + inject registry", "API 1.x, tests <code>--specs</code>"],
                    ["Généré", "<code>stdlib/</code>, m/, c/", "Signatures IDE, pas de profondeur promise"],
                ],
            ),
            h2("2. Core prioritaire (Vague 3)"),
            table(
                ["Module", "Import", "Rôle"],
                [
                    ["str", '<code>import "std/str"</code>', "trim, contains, replace, split, join"],
                    ["math", '<code>import "std/math"</code>', "abs, floor, ceil, pow, random"],
                    ["json", '<code>import "std/json"</code>', "parse, stringify, getString/Number"],
                    ["io / fs / http / path / log / async / …", "voir CORE_STDLIB.md", "I/O, réseau, temps, …"],
                ],
            ),
            h2("3. Exemple méthodique"),
            code(
                'import "std/str"\n'
                'import "std/math"\n'
                "use str\n"
                "use math\n\n"
                'say trim("  hello  ")\n'
                "say abs(0 - 4)\n"
                "say pow(2, 10)"
            ),
            h2("4. Naviguer"),
            ul(
                [
                    '<a href="/stdlib/">/stdlib/</a> — core par défaut, <code>?experimental=1</code> pour tout',
                    "<code>docs/STDLIB_API.md</code>, <code>CORE_STDLIB.md</code>, catalogues SIMPLE/MEDIUM/COMPLEX",
                ]
            ),
            h2("5. WASM"),
            p("str / math / json / collections OK — détails : <a href=\"/docs/wasm/\">WASM</a>."),
        ],
        [
            callout(
                "<strong>Golden rule</strong> — Prefer <strong>core</strong> modules "
                "(real C++ runtime). Generated catalogs are experimental."
            ),
            h2("1. Two layers"),
            table(
                ["Layer", "Where", "Guarantee"],
                [
                    ["Core", "<code>runtime/*.hpp</code> + registry inject", "1.x API, <code>--specs</code> tests"],
                    ["Generated", "<code>stdlib/</code>, m/, c/", "IDE signatures, no depth promise"],
                ],
            ),
            h2("2. Priority core (Wave 3)"),
            table(
                ["Module", "Import", "Role"],
                [
                    ["str", '<code>import "std/str"</code>', "trim, contains, replace, split, join"],
                    ["math", '<code>import "std/math"</code>', "abs, floor, ceil, pow, random"],
                    ["json", '<code>import "std/json"</code>', "parse, stringify, getString/Number"],
                    ["io / fs / http / path / log / async / …", "see CORE_STDLIB.md", "I/O, network, time, …"],
                ],
            ),
            h2("3. Methodical example"),
            code(
                'import "std/str"\n'
                'import "std/math"\n'
                "use str\n"
                "use math\n\n"
                'say trim("  hello  ")\n'
                "say abs(0 - 4)\n"
                "say pow(2, 10)"
            ),
            h2("4. Browse"),
            ul(
                [
                    '<a href="/stdlib/">/stdlib/</a> — core by default, <code>?experimental=1</code> for all',
                    "<code>docs/STDLIB_API.md</code>, <code>CORE_STDLIB.md</code>",
                ]
            ),
            h2("5. WASM"),
            p('str / math / json / collections OK — details: <a href="/docs/wasm/">WASM</a>.'),
        ],
    )


def tooling_page():
    return _page(
        "tooling",
        "Outils",
        "Tooling",
        "CLI, LSP, REPL, IDE, cibles de compilation, variables d'environnement — guide méthodique.",
        "CLI, LSP, REPL, IDE, build targets, environment variables — methodical guide.",
        [
            callout("<strong>Objectif</strong> — Maîtriser la toolchain quotidienne."),
            h2("1. CLI (carte)"),
            table(
                ["Commande", "Rôle"],
                [
                    ["<code>run</code> / <code>build</code> / <code>check</code>", "Compiler / vérifier"],
                    ["<code>test</code> [--examples|--specs|--coverage]", "Suites de tests"],
                    ["<code>fmt</code> / <code>lint</code> / <code>doc</code>", "Qualité & docs"],
                    ["<code>repl</code> / <code>lsp</code> / <code>debug</code>", "Interactif & IDE"],
                    ["<code>init</code> / <code>pkg …</code>", "Projet & paquets"],
                    ["<code>serve</code> / <code>benchmark</code>", "Playground local / perf"],
                ],
            ),
            h2("2. LSP (méthode IDE)"),
            ul(
                [
                    "Installer l'extension AFRILANG (VS Code / Cursor / Open VSX)",
                    "Configurer <code>afrilang.serverPath</code> si besoin",
                    "Ouvrir un fichier <code>.afr</code> (pas le binaire compilé)",
                    "Diagnostics, hover (core vs experimental), complétion, formatage",
                ]
            ),
            h2("3. REPL v2"),
            table(
                ["Commande", "Action"],
                [
                    ["<code>:load file.afr</code>", "Charger"],
                    ["<code>:type expr</code>", "Type"],
                    ["<code>:run</code> / <code>:reset</code> / <code>:quit</code>", "Exécuter / reset / quitter"],
                ],
            ),
            h2("4. Cibles"),
            code(
                "afrilang build --target linux-x64\n"
                "afrilang build --target linux-arm64\n"
                "afrilang run file.afr --target wasm32 --run"
            ),
            h2("5. Variables d'environnement"),
            table(
                ["Variable", "Effet"],
                [
                    ["<code>AFRILANG_HOME</code> / <code>AFRILANG_ROOT</code>", "Racine dépôt (stdlib, packages)"],
                    ["<code>AFRILANG_LOCALE=fr|en</code>", "Locale messages d'erreur"],
                    ["<code>AFRILANG_REGISTRY_URL</code>", "Index distant pkg sync"],
                    ["<code>AFRILANG_REGISTRY_TOKEN</code>", "Publish distant"],
                ],
            ),
            callout('Tests détaillés : <a href="/docs/testing/">Tests</a> · WASM : <a href="/docs/wasm/">WASM</a>'),
        ],
        [
            callout("<strong>Goal</strong> — Master the day-to-day toolchain."),
            h2("1. CLI (map)"),
            table(
                ["Command", "Role"],
                [
                    ["<code>run</code> / <code>build</code> / <code>check</code>", "Compile / verify"],
                    ["<code>test</code> [--examples|--specs|--coverage]", "Test suites"],
                    ["<code>fmt</code> / <code>lint</code> / <code>doc</code>", "Quality & docs"],
                    ["<code>repl</code> / <code>lsp</code> / <code>debug</code>", "Interactive & IDE"],
                    ["<code>init</code> / <code>pkg …</code>", "Project & packages"],
                    ["<code>serve</code> / <code>benchmark</code>", "Local playground / perf"],
                ],
            ),
            h2("2. LSP (IDE method)"),
            ul(
                [
                    "Install the AFRILANG extension (VS Code / Cursor / Open VSX)",
                    "Set <code>afrilang.serverPath</code> if needed",
                    "Open a <code>.afr</code> file (not the compiled binary)",
                    "Diagnostics, hover (core vs experimental), completion, formatting",
                ]
            ),
            h2("3. REPL v2"),
            table(
                ["Command", "Action"],
                [
                    ["<code>:load file.afr</code>", "Load"],
                    ["<code>:type expr</code>", "Type"],
                    ["<code>:run</code> / <code>:reset</code> / <code>:quit</code>", "Run / reset / quit"],
                ],
            ),
            h2("4. Targets"),
            code(
                "afrilang build --target linux-x64\n"
                "afrilang build --target linux-arm64\n"
                "afrilang run file.afr --target wasm32 --run"
            ),
            h2("5. Environment variables"),
            table(
                ["Variable", "Effect"],
                [
                    ["<code>AFRILANG_HOME</code> / <code>AFRILANG_ROOT</code>", "Repo root (stdlib, packages)"],
                    ["<code>AFRILANG_LOCALE=fr|en</code>", "Error message locale"],
                    ["<code>AFRILANG_REGISTRY_URL</code>", "Remote index for pkg sync"],
                    ["<code>AFRILANG_REGISTRY_TOKEN</code>", "Remote publish"],
                ],
            ),
            callout('Detailed tests: <a href="/docs/testing/">Testing</a> · WASM: <a href="/docs/wasm/">WASM</a>'),
        ],
    )


def spec_page():
    return _page(
        "spec",
        "Référence",
        "Reference",
        "Spécification 1.0 condensée et méthodique — types, POO, null-safety, codes d'erreur.",
        "Condensed methodical 1.0 specification — types, OOP, null-safety, error codes.",
        [
            callout(
                "<strong>Source canonique</strong> — <code>docs/LANGUAGE.md</code> dans le dépôt. "
                "Cette page en extrait la carte mentale."
            ),
            h2("1. Types → C++"),
            table(
                ["AFRILANG", "C++"],
                [
                    ["number", "double"],
                    ["text", "std::string"],
                    ["bool", "bool"],
                    ["list of T", "std::vector&lt;T&gt;"],
                    ["map K to V", "std::unordered_map"],
                    ["T?", "std::optional&lt;T&gt;"],
                    ["T or error", "AfrResult_T"],
                ],
            ),
            h2("2. Null-safety (méthode)"),
            code(
                "create nickname text? = nothing\n"
                "if nickname is defined then\n"
                "    say nickname\n"
                "else\n"
                '    say "no nickname"\n'
                "end"
            ),
            p("Pas de <code>none</code> / <code>is some</code> — utiliser <code>nothing</code> / <code>is defined</code>."),
            h2("3. POO (carte)"),
            ul(
                [
                    "class / extends / implements / interface",
                    "public|private|protected field, static, abstract, final",
                    "init constructeur, destroy destructeur, property",
                    "new Classe(args), this, super",
                ]
            ),
            h2("4. Pipeline compilateur"),
            p("Lex → Parse → Semantic → Codegen C++ → g++ → binaire (+ optionnel run)."),
            h2("5. Encodage"),
            p("Sources UTF-8. Localisation erreurs : <code>AFRILANG_LOCALE=fr|en</code>."),
            callout(
                "Pages liées : "
                '<a href="/docs/types/">Types</a>, '
                '<a href="/docs/oop/">POO</a>, '
                '<a href="/docs/pattern-matching/">Pattern matching</a>.'
            ),
        ],
        [
            callout(
                "<strong>Canonical source</strong> — <code>docs/LANGUAGE.md</code> in the repo. "
                "This page extracts the mental map."
            ),
            h2("1. Types → C++"),
            table(
                ["AFRILANG", "C++"],
                [
                    ["number", "double"],
                    ["text", "std::string"],
                    ["bool", "bool"],
                    ["list of T", "std::vector&lt;T&gt;"],
                    ["map K to V", "std::unordered_map"],
                    ["T?", "std::optional&lt;T&gt;"],
                    ["T or error", "AfrResult_T"],
                ],
            ),
            h2("2. Null-safety (method)"),
            code(
                "create nickname text? = nothing\n"
                "if nickname is defined then\n"
                "    say nickname\n"
                "else\n"
                '    say "no nickname"\n'
                "end"
            ),
            p("No <code>none</code> / <code>is some</code> — use <code>nothing</code> / <code>is defined</code>."),
            h2("3. OOP (map)"),
            ul(
                [
                    "class / extends / implements / interface",
                    "public|private|protected field, static, abstract, final",
                    "init constructor, destroy destructor, property",
                    "new Class(args), this, super",
                ]
            ),
            h2("4. Compiler pipeline"),
            p("Lex → Parse → Semantic → C++ codegen → g++ → binary (+ optional run)."),
            h2("5. Encoding"),
            p("UTF-8 sources. Error locale: <code>AFRILANG_LOCALE=fr|en</code>."),
            callout(
                "Related: "
                '<a href="/docs/types/">Types</a>, '
                '<a href="/docs/oop/">OOP</a>, '
                '<a href="/docs/pattern-matching/">Pattern matching</a>.'
            ),
        ],
    )


def advanced_page():
    return _page(
        "advanced",
        "FFI",
        "FFI",
        "Interopérabilité C / externe : déclarations extern, limites, bonnes pratiques.",
        "C / external interop: extern declarations, limits, best practices.",
        [
            callout(
                "<strong>Note</strong> — Les tests ont leur page dédiée : "
                '<a href="/docs/testing/">Tests</a>. Ici : FFI uniquement.'
            ),
            h2("1. Objectif"),
            p("Appeler du code C/C++ existant depuis AFRILANG via des déclarations <code>extern</code>."),
            h2("2. Méthode"),
            ul(
                [
                    "Déclarer la signature côté AFRILANG",
                    "Lier la bibliothèque native au moment du build",
                    "Tester avec un exemple minimal avant d'intégrer la production",
                ]
            ),
            h2("3. Exemple"),
            p("Voir <code>examples/ffi.afr</code> et la section FFI de <code>docs/LANGUAGE.md</code>."),
            h2("4. Précautions"),
            ul(
                [
                    "Pas de gestion mémoire automatique au-delà du modèle AFRILANG",
                    "Aligner types (number ↔ double, text ↔ string/C string selon binding)",
                    "Documenter les préconditions C côté commentaire / README paquet",
                ]
            ),
            callout('<strong>Suite :</strong> <a href="/docs/testing/">Tests →</a>'),
        ],
        [
            callout(
                "<strong>Note</strong> — Testing has its own page: "
                '<a href="/docs/testing/">Testing</a>. Here: FFI only.'
            ),
            h2("1. Goal"),
            p("Call existing C/C++ from AFRILANG via <code>extern</code> declarations."),
            h2("2. Method"),
            ul(
                [
                    "Declare the signature on the AFRILANG side",
                    "Link the native library at build time",
                    "Test with a minimal example before production integration",
                ]
            ),
            h2("3. Example"),
            p("See <code>examples/ffi.afr</code> and the FFI section of <code>docs/LANGUAGE.md</code>."),
            h2("4. Caveats"),
            ul(
                [
                    "No automatic memory management beyond the AFRILANG model",
                    "Align types carefully",
                    "Document C preconditions in package README",
                ]
            ),
            callout('<strong>Next:</strong> <a href="/docs/testing/">Testing →</a>'),
        ],
    )

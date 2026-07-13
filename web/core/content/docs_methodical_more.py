"""Pages documentation méthodique (testing, wasm, contributing, stdlib, tooling, spec, advanced)."""

from .docs_pages import _page, callout, code, h2, p, table, ul


def testing_page():
    return _page(
        "testing",
        "Tests",
        "Testing",
        "Comprendre ce qu’est un test AFRILANG, puis choisir la bonne commande CLI.",
        "Understand what an AFRILANG test is, then pick the right CLI command.",
        [
            callout(
                "<strong>En une phrase</strong> — Un test affirme une propriété "
                "(<code>assert …</code>) ; la CLI choisit <em>quelle</em> suite lancer."
            ),
            h2("1. Anatomie d’un test"),
            p(
                "Un bloc <code>test \"libellé\" … end</code> regroupe des assertions. "
                "Si une assertion est fausse, la suite échoue avec un message clair. "
                "Les fonctions utilitaires (<code>double</code> ci-dessous) doivent être "
                "déclarées <strong>en dehors</strong> du bloc test : "
                "le parseur n’accepte pas correctement les helpers imbriqués dans <code>test</code>."
            ),
            p(
                "L’assertion la plus courante compare deux valeurs avec "
                "<code>is equal to</code>. Vous pouvez aussi tester des booléens "
                "ou des propriétés (<code>is defined</code>, <code>is error</code>)."
            ),
            code(
                "function double(n number) returns number\n"
                "    return n * 2\n"
                "end\n\n"
                'test "function call"\n'
                "    assert double(21) is equal to 42\n"
                "end"
            ),
            h2("2. Modes CLI — que lance chaque commande ?"),
            p(
                "Selon que vous validez le langage, un projet applicatif, ou un paquet, "
                "la commande change. Mémorisez la carte suivante plutôt que d’improviser."
            ),
            table(
                ["Commande", "Quand l’utiliser", "Quoi"],
                [
                    [
                        "<code>afrilang test</code>",
                        "Dans un projet <code>init</code>",
                        "Découvre <code>tests/**/*.afr</code>",
                    ],
                    [
                        "<code>afrilang test --examples .</code>",
                        "CI / dépôt langage",
                        "Suite demos <code>examples/</code>",
                    ],
                    [
                        "<code>afrilang test --specs .</code>",
                        "Changer le compilateur / stdlib core",
                        "<code>tests/specs</code> + <code>tests/stdlib</code>",
                    ],
                    [
                        "<code>afrilang pkg test</code>",
                        "Développer un paquet",
                        "Self-install + tests du paquet",
                    ],
                    [
                        "<code>afrilang test --coverage</code>",
                        "Mesurer ce qui est exercé",
                        "Couverture (si supporté)",
                    ],
                ],
            ),
            h2("3. Specs compilateur (Testament-style)"),
            p(
                "Depuis la racine du dépôt AFRILANG, "
                "<code>afrilang test --specs .</code> exécute une batterie courte mais "
                "exigeante : langage de base, optionnels/Result, modules core "
                "(<code>str</code>, <code>math</code>, <code>json</code>, collections). "
                "C’est le filet de sécurité avant une PR sur le compilateur."
            ),
            h2("4. Projet applicatif"),
            p(
                "Après <code>afrilang init</code>, placez vos fichiers sous <code>tests/</code>, "
                "installez les deps si besoin, puis lancez simplement <code>afrilang test</code>. "
                "Pas besoin de <code>--specs</code> sauf si vous travaillez sur le dépôt langage."
            ),
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
                    "<code>afrilang test --specs .</code> vert (si vous touchez langage/stdlib)",
                    "Exemples touchés : <code>afrilang run examples/…</code>",
                    "Si paquet : <code>afrilang pkg test</code>",
                ]
            ),
            callout(
                'Voir aussi <a href="/docs/tooling/">Outils</a> et '
                '<a href="/docs/contributing/">Contribuer</a>.'
            ),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — A test asserts a property "
                "(<code>assert …</code>); the CLI chooses <em>which</em> suite to run."
            ),
            h2("1. Anatomy of a test"),
            p(
                "A <code>test \"label\" … end</code> block holds assertions. "
                "Helper <code>function</code>s must live <strong>outside</strong> the test block."
            ),
            p(
                "The most common assert compares with <code>is equal to</code>. "
                "You can also check booleans or properties "
                "(<code>is defined</code>, <code>is error</code>)."
            ),
            code(
                "function double(n number) returns number\n"
                "    return n * 2\n"
                "end\n\n"
                'test "function call"\n'
                "    assert double(21) is equal to 42\n"
                "end"
            ),
            h2("2. CLI modes — what each command runs"),
            p(
                "Language validation, app project, or package: pick the right command."
            ),
            table(
                ["Command", "When", "What"],
                [
                    [
                        "<code>afrilang test</code>",
                        "Inside an <code>init</code> project",
                        "Discovers <code>tests/**/*.afr</code>",
                    ],
                    [
                        "<code>afrilang test --examples .</code>",
                        "CI / language repo",
                        "Demo suite <code>examples/</code>",
                    ],
                    [
                        "<code>afrilang test --specs .</code>",
                        "Compiler / core stdlib changes",
                        "<code>tests/specs</code> + <code>tests/stdlib</code>",
                    ],
                    [
                        "<code>afrilang pkg test</code>",
                        "Developing a package",
                        "Self-install + package tests",
                    ],
                    [
                        "<code>afrilang test --coverage</code>",
                        "Measure exercised code",
                        "Coverage (when supported)",
                    ],
                ],
            ),
            h2("3. Compiler specs (Testament-style)"),
            p(
                "From the AFRILANG repo root, <code>afrilang test --specs .</code> runs "
                "language basics, optionals/Result, and core stdlib — the PR safety net."
            ),
            h2("4. Application project"),
            p(
                "After <code>afrilang init</code>, put files under <code>tests/</code> "
                "and run <code>afrilang test</code>."
            ),
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
                    "<code>afrilang test --specs .</code> green (if touching language/stdlib)",
                    "Touched examples: <code>afrilang run examples/…</code>",
                    "If package: <code>afrilang pkg test</code>",
                ]
            ),
            callout(
                'See also <a href="/docs/tooling/">Tooling</a> and '
                '<a href="/docs/contributing/">Contributing</a>.'
            ),
        ],
    )


def wasm_page():
    return _page(
        "wasm",
        "WASM & JS",
        "WASM & JS",
        "Ce qui tourne en wasm32 / playground, ce qui reste natif — et pourquoi.",
        "What runs under wasm32 / playground vs native — and why.",
        [
            callout(
                "<strong>En une phrase</strong> — WASM et le playground sont un "
                "<em>sous-ensemble</em> volontaire : idéal pour apprendre et CI légère, "
                "pas pour SDL ni I/O disque synchrone."
            ),
            h2("1. Cible wasm32"),
            p(
                "Avec <code>--target wasm32</code>, le pipeline produit du WebAssembly "
                "via Emscripten au lieu d’un binaire Linux. "
                "<code>emsdk</code> / <code>emcc</code> doivent être dans le PATH. "
                "Sans Emscripten, la commande échoue clairement."
            ),
            code(
                "afrilang run examples/tier8_demo.afr --target wasm32 --run",
                "Terminal",
            ),
            h2("2. Ce qui fonctionne en WASM"),
            p(
                "Le cœur du langage (variables, fonctions, boucles, POO) et la stdlib "
                "core légère (json, str, math, collections…) sont conçus pour passer. "
                "L’async <code>sleep</code> s’appuie sur le runtime Emscripten. "
                "Les demos CI <code>tier8_*.afr</code> documentent ce contrat."
            ),
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
            h2("3. Natif uniquement — pourquoi"),
            p(
                "Une fenêtre SDL2, OpenGL, des sockets bloquants ou des threads POSIX "
                "supposent un OS de bureau. Le navigateur (et wasm32 « simple ») "
                "n’offrent pas ces primitives telles quelles. "
                "Ce n’est pas un bug temporaire : c’est une frontière de plateforme."
            ),
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
            p(
                "Le playground du site compile un sous-ensemble encore plus petit vers JS "
                "pour une démo instantanée dans le navigateur : "
                "affichage, variables, conditions, boucles, fonctions. "
                "Pas d’imports stdlib, pas de classes, pas d’async, pas de tests. "
                "Pour ces besoins, passez au compilateur natif ou à wasm32."
            ),
            ul(
                [
                    "Autorisé : say, assign/set, if/while/repeat/for, fonctions + return",
                    "Exclus : imports, classes, async, UI, tests",
                ]
            ),
            h2("5. Recommandation pratique"),
            ul(
                [
                    "Apprendre / CI légère : playground ou WASM + str/math/json",
                    "Jeux, SIG, data science lourde : cible native",
                ]
            ),
            callout("Référence dépôt : <code>docs/WASM_COMPAT.md</code>."),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — WASM and the playground are a "
                "<em>deliberate subset</em>: great for learning and light CI, "
                "not for SDL or sync disk I/O."
            ),
            h2("1. wasm32 target"),
            p(
                "<code>--target wasm32</code> builds WebAssembly via Emscripten. "
                "<code>emsdk</code> / <code>emcc</code> must be on PATH."
            ),
            code(
                "afrilang run examples/tier8_demo.afr --target wasm32 --run",
                "Terminal",
            ),
            h2("2. What works in WASM"),
            p(
                "Core language + light core stdlib are in scope. "
                "Async sleep uses the Emscripten runtime. "
                "CI demos <code>tier8_*.afr</code> document the contract."
            ),
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
            h2("3. Native only — why"),
            p(
                "SDL windows, OpenGL, blocking sockets, and POSIX threads assume a desktop OS. "
                "That is a platform boundary, not a temporary bug."
            ),
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
            p(
                "The site playground compiles an even smaller subset to JS for instant demos. "
                "No stdlib imports, classes, async, UI, or tests."
            ),
            ul(
                [
                    "Allowed: say, assign/set, if/while/repeat/for, functions + return",
                    "Excluded: imports, classes, async, UI, tests",
                ]
            ),
            h2("5. Practical recommendation"),
            ul(
                [
                    "Learning / light CI: playground or WASM + str/math/json",
                    "Games, GIS, heavy data science: native target",
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
            callout(
                "<strong>Objectif</strong> — Proposer un changement qui passe CI et "
                "respecte le parcours produit (pas une rustine isolée)."
            ),
            h2("1. Préparer l’environnement"),
            p(
                "Commencez comme un utilisateur : suivez "
                '<a href="/docs/getting-started/">Premiers pas</a>, '
                "forkez, créez une branche thématique. "
                "Lisez <code>docs/ROADMAP.md</code> pour savoir ce qui est déjà livré "
                "et ce qui est prévu — évite les PR hors scope."
            ),
            ul(
                [
                    'Suivre <a href="/docs/getting-started/">Premiers pas</a>',
                    "Fork + branche thématique",
                    "Lire <code>docs/ROADMAP.md</code> (vagues livrées)",
                ]
            ),
            h2("2. Boucle de validation (obligatoire)"),
            p(
                "Avant d’ouvrir la PR : rebuild, unit tests C++, specs langage. "
                "Si vous avez touché des demos, lancez aussi <code>--examples</code>. "
                "Un patch « qui compile chez moi » sans specs est insuffisant."
            ),
            code(
                "cmake --build build -j$(nproc)\n"
                "cd build && ctest --output-on-failure -R compiler_unit_tests\n"
                "cd .. && ./build/afrilang test --specs .\n"
                "# si exemples touchés :\n"
                "./build/afrilang test --examples .",
                "Terminal",
            ),
            h2("3. Conventions code"),
            p(
                "Alignez-vous sur le style C++ existant. "
                "Pour la stdlib core : runtime + tests avant de promettre une API. "
                "Les catalogues générés restent expérimentaux "
                '(voir <a href="/docs/stdlib/">Stdlib</a>). '
                "Aucun secret dans les commits."
            ),
            ul(
                [
                    "C++17/20 aligné sur le style existant",
                    "Stdlib core : runtime + tests avant promesse API",
                    "Catalogues générés = expérimentaux",
                    "Pas de secrets dans les commits",
                ]
            ),
            h2("4. Documentation"),
            p(
                "Le guide web est bilingue (dicts Python sous "
                "<code>web/core/content/docs_*.py</code>). "
                "Toute page ajoutée ou modifiée doit rester FR + EN. "
                "Les fichiers <code>docs/*.md</code> du dépôt restent la référence longue."
            ),
            ul(
                [
                    "Guide site : <code>web/core/content/docs_*.py</code> (FR + EN)",
                    "Référence dépôt : <code>docs/LANGUAGE.md</code>, <code>PKG.md</code>, …",
                    "Toute page web doit rester bilingue",
                ]
            ),
            h2("5. PR"),
            p(
                "Expliquez le <em>pourquoi</em> et le parcours utilisateur impacté "
                "(pas seulement la liste des fichiers). "
                "Joignez une checklist de tests. Attendez la CI verte."
            ),
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
            callout(
                "<strong>Goal</strong> — Propose a change that passes CI and respects "
                "the product path (not an isolated patch)."
            ),
            h2("1. Prepare the environment"),
            p(
                "Start like a user: follow Getting started, fork, topical branch. "
                "Read <code>docs/ROADMAP.md</code> to stay in scope."
            ),
            ul(
                [
                    'Follow <a href="/docs/getting-started/">Getting started</a>',
                    "Fork + topical branch",
                    "Read <code>docs/ROADMAP.md</code>",
                ]
            ),
            h2("2. Validation loop (required)"),
            p(
                "Rebuild, C++ unit tests, language specs. "
                "If you touched demos, also run <code>--examples</code>."
            ),
            code(
                "cmake --build build -j$(nproc)\n"
                "cd build && ctest --output-on-failure -R compiler_unit_tests\n"
                "cd .. && ./build/afrilang test --specs .\n"
                "./build/afrilang test --examples .",
                "Terminal",
            ),
            h2("3. Code conventions"),
            p(
                "Match existing C++ style. Core stdlib needs runtime + tests before API promises. "
                "Generated catalogs stay experimental. No secrets in commits."
            ),
            ul(
                [
                    "C++17/20 matching existing style",
                    "Core stdlib: runtime + tests before API promises",
                    "Generated catalogs = experimental",
                    "No secrets in commits",
                ]
            ),
            h2("4. Documentation"),
            p(
                "The site guide is bilingual Python dicts under "
                "<code>web/core/content/docs_*.py</code>. "
                "Repo <code>docs/*.md</code> files remain the long reference."
            ),
            ul(
                [
                    "Site guide: <code>web/core/content/docs_*.py</code> (FR + EN)",
                    "Repo reference: <code>docs/LANGUAGE.md</code>, <code>PKG.md</code>, …",
                    "Every web page must stay bilingual",
                ]
            ),
            h2("5. PR"),
            p(
                "Explain <em>why</em> and the impacted user journey. "
                "Include a test checklist. Wait for green CI."
            ),
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
        "Core stabilisé vs catalogues générés — comment choisir et importer.",
        "Stabilized core vs generated catalogs — how to choose and import.",
        [
            callout(
                "<strong>Règle d’or</strong> — Préférez les modules <strong>core</strong> "
                "(runtime C++ réel, tests <code>--specs</code>). "
                "Les catalogues générés sont expérimentaux : utiles pour explorer, "
                "pas pour promettre une API 1.x."
            ),
            h2("1. Deux couches — pourquoi cette distinction ?"),
            p(
                "Le dépôt contient des milliers d’entrées de catalogue pour l’IDE et "
                "l’exploration. Seule une partie a un runtime C++ solide et des specs. "
                "Si vous construisez une appli, ancrez-vous sur le core : "
                "moins de surprises à la compilation et en WASM."
            ),
            table(
                ["Couche", "Où", "Garantie"],
                [
                    ["Core", "<code>runtime/*.hpp</code> + inject registry", "API 1.x, tests <code>--specs</code>"],
                    ["Généré", "<code>stdlib/</code>, m/, c/", "Signatures IDE, pas de profondeur promise"],
                ],
            ),
            h2("2. Core prioritaire"),
            p(
                "Commencez par <code>str</code>, <code>math</code>, <code>json</code> : "
                "ils couvrent la majorité des demos et des specs. "
                "Étendez ensuite vers io / fs / http / path / log / async selon le besoin, "
                "en vérifiant la page WASM si vous ciblez le navigateur."
            ),
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
            p(
                "Deux gestes : <code>import</code> (où trouver le module) puis "
                "<code>use</code> (amener les symboles dans la portée). "
                "Ensuite appelez les fonctions comme d’habitude."
            ),
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
            p(
                "Le site <a href=\"/stdlib/\">/stdlib/</a> montre le core par défaut. "
                "Ajoutez <code>?experimental=1</code> pour voir les catalogues. "
                "Dans le dépôt : <code>docs/STDLIB_API.md</code>, <code>CORE_STDLIB.md</code>."
            ),
            h2("5. WASM"),
            p(
                "str / math / json / collections sont le trio sûr. "
                'Détails et limites : <a href="/docs/wasm/">WASM</a>.'
            ),
        ],
        [
            callout(
                "<strong>Golden rule</strong> — Prefer <strong>core</strong> modules "
                "(real C++ runtime, <code>--specs</code> tests). "
                "Generated catalogs are experimental."
            ),
            h2("1. Two layers — why?"),
            p(
                "Thousands of catalog entries help the IDE; only a subset has a solid "
                "C++ runtime and specs. Anchor apps on core for fewer surprises."
            ),
            table(
                ["Layer", "Where", "Guarantee"],
                [
                    ["Core", "<code>runtime/*.hpp</code> + registry inject", "1.x API, <code>--specs</code> tests"],
                    ["Generated", "<code>stdlib/</code>, m/, c/", "IDE signatures, no depth promise"],
                ],
            ),
            h2("2. Priority core"),
            p(
                "Start with <code>str</code>, <code>math</code>, <code>json</code>. "
                "Extend to io / fs / http / … as needed; check WASM if targeting the browser."
            ),
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
            p(
                "Two steps: <code>import</code> (where) then <code>use</code> (bring symbols into scope)."
            ),
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
            p(
                '<a href="/stdlib/">/stdlib/</a> shows core by default; '
                "<code>?experimental=1</code> reveals catalogs."
            ),
            h2("5. WASM"),
            p(
                'str / math / json / collections are the safe trio — '
                '<a href="/docs/wasm/">WASM</a>.'
            ),
        ],
    )


def tooling_page():
    return _page(
        "tooling",
        "Outils",
        "Tooling",
        "CLI, LSP, REPL, IDE, cibles, variables d’environnement — à quoi sert chaque pièce.",
        "CLI, LSP, REPL, IDE, targets, env vars — what each piece is for.",
        [
            callout(
                "<strong>Objectif</strong> — Savoir quel outil ouvrir selon la tâche "
                "(écrire, vérifier, déboguer, cibler une plateforme)."
            ),
            h2("1. CLI — carte mentale"),
            p(
                "La commande <code>afrilang</code> est le hub. "
                "<code>run</code> compile et exécute ; <code>build</code> s’arrête au binaire ; "
                "<code>check</code> vérifie sans forcément produire un artefact. "
                "Les sous-commandes <code>test</code>, <code>pkg</code>, <code>fmt</code>, "
                "<code>lsp</code> couvrent le reste du flux quotidien."
            ),
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
            p(
                "L’extension VS Code / Cursor parle au serveur <code>afrilang lsp</code>. "
                "Ouvrez toujours un fichier source <code>*.afr</code> — "
                "pas le binaire compilé (sinon pas de coloration ni de bouton Run). "
                "Le hover distingue modules core et expérimentaux."
            ),
            ul(
                [
                    "Installer l’extension AFRILANG (VS Code / Cursor / Open VSX)",
                    "Configurer <code>afrilang.serverPath</code> si besoin",
                    "Ouvrir un fichier <code>.afr</code> (pas le binaire compilé)",
                    "Diagnostics, hover (core vs experimental), complétion, formatage",
                ]
            ),
            h2("3. REPL v2"),
            p(
                "Le REPL sert à expérimenter une expression sans créer un fichier. "
                "Chargez un fichier avec <code>:load</code>, inspectez un type avec "
                "<code>:type</code>, exécutez avec <code>:run</code>."
            ),
            table(
                ["Commande", "Action"],
                [
                    ["<code>:load file.afr</code>", "Charger"],
                    ["<code>:type expr</code>", "Type"],
                    ["<code>:run</code> / <code>:reset</code> / <code>:quit</code>", "Exécuter / reset / quitter"],
                ],
            ),
            h2("4. Cibles"),
            p(
                "Par défaut vous construisez pour la machine hôte. "
                "Passez <code>--target</code> pour cross-compiler (arm64, wasm32…). "
                "Chaque cible a ses prérequis (Emscripten pour wasm, etc.)."
            ),
            code(
                "afrilang build --target linux-x64\n"
                "afrilang build --target linux-arm64\n"
                "afrilang run file.afr --target wasm32 --run"
            ),
            h2("5. Variables d’environnement"),
            p(
                "Ces variables évitent de hardcoder des chemins dans chaque commande. "
                "Sans <code>AFRILANG_HOME</code>, la stdlib est invisible."
            ),
            table(
                ["Variable", "Effet"],
                [
                    ["<code>AFRILANG_HOME</code> / <code>AFRILANG_ROOT</code>", "Racine dépôt (stdlib, packages)"],
                    ["<code>AFRILANG_LOCALE=fr|en</code>", "Locale messages d’erreur"],
                    ["<code>AFRILANG_REGISTRY_URL</code>", "Index distant pkg sync"],
                    ["<code>AFRILANG_REGISTRY_TOKEN</code>", "Publish distant"],
                ],
            ),
            callout(
                'Tests détaillés : <a href="/docs/testing/">Tests</a> · '
                'WASM : <a href="/docs/wasm/">WASM</a>'
            ),
        ],
        [
            callout(
                "<strong>Goal</strong> — Know which tool to open for write / check / debug / target."
            ),
            h2("1. CLI — mental map"),
            p(
                "<code>run</code> compiles and executes; <code>build</code> stops at the binary; "
                "<code>check</code> verifies. <code>test</code>, <code>pkg</code>, <code>fmt</code>, "
                "<code>lsp</code> cover the rest of the daily flow."
            ),
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
            p(
                "Always open a <code>*.afr</code> source file — not the compiled binary. "
                "Hover distinguishes core vs experimental modules."
            ),
            ul(
                [
                    "Install the AFRILANG extension (VS Code / Cursor / Open VSX)",
                    "Set <code>afrilang.serverPath</code> if needed",
                    "Open a <code>.afr</code> file (not the compiled binary)",
                    "Diagnostics, hover (core vs experimental), completion, formatting",
                ]
            ),
            h2("3. REPL v2"),
            p(
                "Experiment without a file: <code>:load</code>, <code>:type</code>, <code>:run</code>."
            ),
            table(
                ["Command", "Action"],
                [
                    ["<code>:load file.afr</code>", "Load"],
                    ["<code>:type expr</code>", "Type"],
                    ["<code>:run</code> / <code>:reset</code> / <code>:quit</code>", "Run / reset / quit"],
                ],
            ),
            h2("4. Targets"),
            p(
                "Default builds for the host. Pass <code>--target</code> to cross-compile "
                "(arm64, wasm32…). Each target has prerequisites."
            ),
            code(
                "afrilang build --target linux-x64\n"
                "afrilang build --target linux-arm64\n"
                "afrilang run file.afr --target wasm32 --run"
            ),
            h2("5. Environment variables"),
            p(
                "Without <code>AFRILANG_HOME</code>, the stdlib is invisible."
            ),
            table(
                ["Variable", "Effect"],
                [
                    ["<code>AFRILANG_HOME</code> / <code>AFRILANG_ROOT</code>", "Repo root (stdlib, packages)"],
                    ["<code>AFRILANG_LOCALE=fr|en</code>", "Error message locale"],
                    ["<code>AFRILANG_REGISTRY_URL</code>", "Remote index for pkg sync"],
                    ["<code>AFRILANG_REGISTRY_TOKEN</code>", "Remote publish"],
                ],
            ),
            callout(
                'Detailed tests: <a href="/docs/testing/">Testing</a> · '
                'WASM: <a href="/docs/wasm/">WASM</a>'
            ),
        ],
    )


def spec_page():
    return _page(
        "spec",
        "Référence",
        "Reference",
        "Carte mentale de la spécification 1.0 — types, null-safety, POO, pipeline.",
        "Mental map of the 1.0 spec — types, null-safety, OOP, pipeline.",
        [
            callout(
                "<strong>Source canonique</strong> — <code>docs/LANGUAGE.md</code> dans le dépôt. "
                "Cette page en extrait la carte mentale avec des explications courtes."
            ),
            h2("1. Types → C++"),
            p(
                "Chaque type AFRILANG a une traduction C++ stable. "
                "Cela explique pourquoi <code>number</code> accepte des décimales, "
                "et pourquoi les listes se comportent comme des vecteurs."
            ),
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
            p(
                "Pour « une valeur ou rien », utilisez un optionnel. "
                "Initialisez avec <code>nothing</code>, testez avec <code>is defined</code> "
                "avant lecture. "
                "Pas de <code>none</code> / <code>is some</code> — ce n’est pas la grammaire AFRILANG."
            ),
            code(
                "create nickname text? = nothing\n"
                "if nickname is defined then\n"
                "    say nickname\n"
                "else\n"
                '    say "no nickname"\n'
                "end"
            ),
            h2("3. POO (carte)"),
            p(
                "Les mots-clés ci-dessous couvrent le modèle objet complet. "
                "Détails et exemples : page <a href=\"/docs/oop/\">POO</a>."
            ),
            ul(
                [
                    "class / extends / implements / interface",
                    "public|private|protected field, static, abstract, final",
                    "init constructeur, destroy destructeur, property",
                    "new Classe(args), this, super",
                ]
            ),
            h2("4. Pipeline compilateur"),
            p(
                "Lexique → parse → sémantique → génération C++ → <code>g++</code> → binaire "
                "(puis exécution optionnelle). "
                "Comprendre cette chaîne aide à lire les messages d’erreur "
                "(étape lexicale vs sémantique vs linker)."
            ),
            h2("5. Encodage"),
            p(
                "Sources UTF-8. Localisation des messages d’erreur : "
                "<code>AFRILANG_LOCALE=fr|en</code>."
            ),
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
                "This page extracts the mental map with short explanations."
            ),
            h2("1. Types → C++"),
            p(
                "Each AFRILANG type has a stable C++ mapping — why <code>number</code> "
                "accepts decimals, and lists behave like vectors."
            ),
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
            p(
                "Use optionals for “value or none”: <code>nothing</code> + "
                "<code>is defined</code>. No <code>none</code> / <code>is some</code>."
            ),
            code(
                "create nickname text? = nothing\n"
                "if nickname is defined then\n"
                "    say nickname\n"
                "else\n"
                '    say "no nickname"\n'
                "end"
            ),
            h2("3. OOP (map)"),
            p(
                'Full details on the <a href="/docs/oop/">OOP</a> page.'
            ),
            ul(
                [
                    "class / extends / implements / interface",
                    "public|private|protected field, static, abstract, final",
                    "init constructor, destroy destructor, property",
                    "new Class(args), this, super",
                ]
            ),
            h2("4. Compiler pipeline"),
            p(
                "Lex → Parse → Semantic → C++ codegen → g++ → binary (+ optional run). "
                "Helps interpret error stages."
            ),
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
        "Interopérabilité C / externe : pourquoi, comment, précautions.",
        "C / external interop: why, how, caveats.",
        [
            callout(
                "<strong>Note</strong> — Les tests ont leur page dédiée : "
                '<a href="/docs/testing/">Tests</a>. Ici : FFI uniquement.'
            ),
            h2("1. Objectif"),
            p(
                "Beaucoup de bibliothèques utiles existent déjà en C/C++. "
                "Le FFI (Foreign Function Interface) permet d’appeler ces fonctions "
                "depuis AFRILANG via des déclarations <code>extern</code>, "
                "sans tout réécrire."
            ),
            h2("2. Méthode"),
            p(
                "Déclarez la signature côté AFRILANG (types alignés), "
                "liez la bibliothèque native au build, "
                "puis validez avec un exemple minimal "
                "(une seule fonction exportée) avant d’intégrer le reste."
            ),
            ul(
                [
                    "Déclarer la signature côté AFRILANG",
                    "Lier la bibliothèque native au moment du build",
                    "Tester avec un exemple minimal avant d’intégrer la production",
                ]
            ),
            h2("3. Exemple"),
            p(
                "Reportez-vous à <code>examples/ffi.afr</code> et à la section FFI de "
                "<code>docs/LANGUAGE.md</code> pour la syntaxe exacte de votre version."
            ),
            h2("4. Précautions"),
            p(
                "Le modèle mémoire C n’est pas géré automatiquement comme les objets AFRILANG. "
                "Alignez les types (number ↔ double, text ↔ chaîne C selon le binding) "
                "et documentez les préconditions dans le README du paquet."
            ),
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
            p(
                "Call existing C/C++ from AFRILANG via <code>extern</code> "
                "instead of rewriting libraries."
            ),
            h2("2. Method"),
            p(
                "Declare the AFRILANG signature, link the native library at build time, "
                "validate with a minimal example first."
            ),
            ul(
                [
                    "Declare the signature on the AFRILANG side",
                    "Link the native library at build time",
                    "Test with a minimal example before production integration",
                ]
            ),
            h2("3. Example"),
            p(
                "See <code>examples/ffi.afr</code> and the FFI section of "
                "<code>docs/LANGUAGE.md</code>."
            ),
            h2("4. Caveats"),
            p(
                "C memory is not managed like AFRILANG objects. Align types carefully "
                "and document C preconditions in the package README."
            ),
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

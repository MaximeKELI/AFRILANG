"""Pages documentation méthodique (suite)."""

from .docs_pages import _page, callout, code, h2, h3, p, table, ul


def exceptions_page():
    fr_try = (
        "try\n"
        "    raise \"something failed\"\n"
        "catch error e\n"
        "    say e\n"
        "end"
    )
    fr_result = (
        "function divide(a number, b number) returns number or error\n"
        "    if b is equal to 0 then\n"
        "        return error \"Division par zero\"\n"
        "    end\n"
        "    return a / b\n"
        "end\n\n"
        "create ok = divide(10, 2)\n"
        "if ok is error then\n"
        "    say ok.message\n"
        "else\n"
        "    say ok.value\n"
        "end"
    )
    en_result = fr_result.replace("Division par zero", "Division by zero")
    return _page(
        "exceptions",
        "Exceptions",
        "Exceptions",
        "try / catch / raise, et quand préférer Result (T or error).",
        "try / catch / raise, and when to prefer Result (T or error).",
        [
            callout("<strong>Objectif</strong> — Distinguer erreurs récupérables (Result) et exceptions."),
            h2("1. try / catch / raise"),
            code(fr_try),
            h2("2. Result (recommandé pour l'API)"),
            code(fr_result),
            h2("3. Méthode : quand utiliser quoi ?"),
            table(
                ["Situation", "Mécanisme"],
                [
                    ["Erreur attendue (parse, I/O métier)", "<code>T or error</code> + <code>is error</code>"],
                    ["Bug / état impossible", "<code>raise</code> / assert"],
                    ["Tests", "<code>assert … is equal to …</code>"],
                ],
            ),
            h2("4. Erreurs fréquentes"),
            ul(
                [
                    "Il n'y a pas de <code>is ok</code> — tester <code>(r is error) is equal to false</code>.",
                    "Les fonctions Result se déclarent hors des blocs <code>test</code>.",
                ]
            ),
            callout("Exemple : <code>examples/result.afr</code>, <code>examples/exceptions.afr</code>"),
        ],
        [
            callout("<strong>Goal</strong> — Distinguish recoverable errors (Result) from exceptions."),
            h2("1. try / catch / raise"),
            code(fr_try),
            h2("2. Result (recommended for APIs)"),
            code(en_result),
            h2("3. Method: when to use what?"),
            table(
                ["Situation", "Mechanism"],
                [
                    ["Expected failure (parse, domain I/O)", "<code>T or error</code> + <code>is error</code>"],
                    ["Bug / impossible state", "<code>raise</code> / assert"],
                    ["Tests", "<code>assert … is equal to …</code>"],
                ],
            ),
            h2("4. Common errors"),
            ul(
                [
                    "There is no <code>is ok</code> — use <code>(r is error) is equal to false</code>.",
                    "Result helpers must be declared outside <code>test</code> blocks.",
                ]
            ),
            callout("Examples: <code>examples/result.afr</code>, <code>examples/exceptions.afr</code>"),
        ],
    )


def modules_page():
    mod = (
        "module math_utils\n\n"
        "export function square(n number) returns number\n"
        "    return n * n\n"
        "end\n\n"
        "function helper(n number) returns number\n"
        "    return n + 1\n"
        "end\n"
        "end"
    )
    imp = (
        'import "std/str"\n'
        "use str\n\n"
        'import "pkg/math/math.afr"\n'
        "use math\n\n"
        'say trim("  hi  ")\n'
        "say abs(0 - 3)"
    )
    return _page(
        "modules",
        "Modules",
        "Modules",
        "Organisation du code : module, export, import, use, chemins std/ et pkg/.",
        "Code organization: module, export, import, use, std/ and pkg/ paths.",
        [
            callout("<strong>Objectif</strong> — Découper un programme en modules réutilisables."),
            h2("1. Déclarer un module"),
            code(mod),
            p("<code>export</code> rend la fonction visible hors module. Sans export = privée."),
            h2("2. Importer"),
            code(imp),
            h2("3. Chemins d'import (méthode)"),
            table(
                ["Préfixe", "Signification"],
                [
                    ["<code>std/…</code>", "Bibliothèque standard (core ou catalogue)"],
                    ["<code>std/m/…</code>", "Catalogue medium (souvent expérimental)"],
                    ["<code>std/c/…</code>", "Catalogue complex / ultra"],
                    ["<code>pkg/name/…</code>", "Paquet installé (vendor / registry)"],
                    ["fichier relatif", "Module projet local"],
                ],
            ),
            h2("4. use"),
            p("<code>use nom</code> importe les symboles exportés dans la portée courante."),
            callout("Exemples : <code>modules.afr</code>, <code>pkg_demo.afr</code>"),
        ],
        [
            callout("<strong>Goal</strong> — Split a program into reusable modules."),
            h2("1. Declare a module"),
            code(mod),
            p("<code>export</code> makes the function visible outside. No export = private."),
            h2("2. Import"),
            code(imp),
            h2("3. Import paths (method)"),
            table(
                ["Prefix", "Meaning"],
                [
                    ["<code>std/…</code>", "Standard library (core or catalog)"],
                    ["<code>std/m/…</code>", "Medium catalog (often experimental)"],
                    ["<code>std/c/…</code>", "Complex / ultra catalog"],
                    ["<code>pkg/name/…</code>", "Installed package (vendor / registry)"],
                    ["relative file", "Local project module"],
                ],
            ),
            h2("4. use"),
            p("<code>use name</code> brings exported symbols into scope."),
            callout("Examples: <code>modules.afr</code>, <code>pkg_demo.afr</code>"),
        ],
    )


def async_page():
    sample = (
        'import "std/async"\n'
        "use async\n\n"
        "async function delayedValue(ms number) returns number or error\n"
        "    await sleep(ms)\n"
        "    return 42\n"
        "end"
    )
    return _page(
        "async",
        "Async / await",
        "Async / await",
        "Coroutines C++20 : async function, await, std/async, limites WASM.",
        "C++20 coroutines: async function, await, std/async, WASM limits.",
        [
            callout("<strong>Objectif</strong> — Écrire des tâches non bloquantes avec <code>await</code>."),
            h2("1. Prérequis"),
            ul(["Compilateur C++20", "Runtime async activé", "Pour WASM : Emscripten (sous-ensemble)"]),
            h2("2. async function"),
            code(sample),
            h2("3. await"),
            p("Seul un contexte <code>async</code> peut <code>await</code>."),
            h2("4. Limites"),
            ul(
                [
                    "GUI SDL et threads POSIX : natif seulement",
                    "WASM : sleep / coroutines Emscripten OK ; sockets sync non",
                ]
            ),
            callout('<strong>Suite WASM :</strong> <a href="/docs/wasm/">Compatibilité WASM →</a>'),
        ],
        [
            callout("<strong>Goal</strong> — Write non-blocking tasks with <code>await</code>."),
            h2("1. Prerequisites"),
            ul(["C++20 compiler", "Async runtime enabled", "For WASM: Emscripten (subset)"]),
            h2("2. async function"),
            code(sample),
            h2("3. await"),
            p("Only an <code>async</code> context can <code>await</code>."),
            h2("4. Limits"),
            ul(
                [
                    "SDL GUI and POSIX threads: native only",
                    "WASM: sleep / Emscripten coroutines OK; sync sockets no",
                ]
            ),
            callout('<strong>Next WASM:</strong> <a href="/docs/wasm/">WASM compatibility →</a>'),
        ],
    )


def gui_page():
    return _page(
        "gui",
        "Interfaces graphiques",
        "Graphical UI",
        "std/ui (SDL2) : fenêtres, boutons, boucle d'événements — natif uniquement.",
        "std/ui (SDL2): windows, buttons, event loop — native only.",
        [
            callout("<strong>Objectif</strong> — Ouvrir une fenêtre SDL2 et réagir aux événements."),
            h2("1. Prérequis système"),
            code("sudo apt-get install -y libsdl2-dev libsdl2-ttf-dev", "Terminal"),
            h2("2. Module"),
            code('import "std/ui"\nuse ui'),
            h2("3. Méthode"),
            ul(
                [
                    "Créer la fenêtre",
                    "Boucle d'événements (clavier / souris / fermeture)",
                    "Dessiner / rafraîchir",
                    "Quitter proprement",
                ]
            ),
            p("Demos : <code>gui_demo.afr</code>, packs game2d / game3d."),
            h2("4. Hors portée WASM"),
            p("Pas de SDL2 dans le navigateur. Voir <a href=\"/docs/wasm/\">WASM</a>."),
        ],
        [
            callout("<strong>Goal</strong> — Open an SDL2 window and handle events."),
            h2("1. System prerequisites"),
            code("sudo apt-get install -y libsdl2-dev libsdl2-ttf-dev", "Terminal"),
            h2("2. Module"),
            code('import "std/ui"\nuse ui'),
            h2("3. Method"),
            ul(
                [
                    "Create the window",
                    "Event loop (keyboard / mouse / close)",
                    "Draw / refresh",
                    "Clean shutdown",
                ]
            ),
            p("Demos: <code>gui_demo.afr</code>, game2d / game3d packs."),
            h2("4. Out of scope for WASM"),
            p('No SDL2 in the browser. See <a href="/docs/wasm/">WASM</a>.'),
        ],
    )


def packages_page():
    return _page(
        "package-manager",
        "Paquets",
        "Packages",
        "Guide méthodique du gestionnaire (style Nimble/Shards) : toml, lock, deps, publish.",
        "Methodical package manager guide (Nimble/Shards-style): toml, lock, deps, publish.",
        [
            callout("<strong>Objectif</strong> — Créer, dépendre, installer, tester et publier un paquet."),
            h2("1. Fichiers projet"),
            table(
                ["Fichier", "Rôle"],
                [
                    ["<code>afrilang.toml</code>", "Métadonnées + <code>[dependencies]</code>"],
                    ["<code>afrilang.lock</code>", "Versions exactes (source de vérité pour install)"],
                    ["<code>vendor/</code>", "Copies locales des paquets"],
                    ["<code>manifest.toml</code>", "Métadonnées d'une bibliothèque"],
                    ["<code>packages/index.json</code>", "Index local"],
                    ["<code>packages/remote-index.json</code>", "Index distant (<code>pkg sync</code>)"],
                ],
            ),
            h2("2. Créer"),
            code(
                "afrilang init mon_app\n"
                "afrilang init mon_lib --lib\n"
                "afrilang pkg init mon_lib\n"
                "cd mon_lib && afrilang pkg test\n"
                "afrilang doc .",
                "Terminal",
            ),
            h2("3. Dépendances — registre"),
            code('[dependencies]\nmath = "0.1.0"\nstrings = "^0.1.0"', "afrilang.toml"),
            code(
                "afrilang pkg sync\n"
                "afrilang pkg add math\n"
                "afrilang pkg install\n"
                "afrilang pkg update",
                "Terminal",
            ),
            h2("4. Semver"),
            table(
                ["Range", "Signification"],
                [
                    ["<code>1.2.3</code>", "<code>&gt;= 1.2.3</code> (compat historique)"],
                    ["<code>^1.2.3</code>", "<code>&gt;= 1.2.3</code> et <code>&lt; 2.0.0</code>"],
                    ["<code>~1.2.3</code>", "<code>&gt;= 1.2.3</code> et <code>&lt; 1.3.0</code>"],
                ],
            ),
            h2("5. Git / path"),
            code('mylib = { git = "https://github.com/org/mylib.git", tag = "v0.1.0" }', "toml"),
            code('mylib = { path = "../mylib" }', "toml"),
            code(
                "afrilang pkg add mylib --git https://github.com/org/mylib.git --tag v0.1.0\n"
                "afrilang pkg add mylib --path ../mylib",
                "Terminal",
            ),
            h2("6. Install vs update"),
            ul(
                [
                    "<code>pkg install</code> — si lock présent, installe exactement le lock ; sinon résout et écrit le lock",
                    "<code>pkg update</code> — re-résout depuis les ranges du toml, réécrit le lock",
                    "Transitivité : deps des <code>manifest.toml</code> résolues récursivement ; conflit = erreur",
                ]
            ),
            h2("7. Publier"),
            code("afrilang pkg publish ./mon_lib", "Local"),
            code(
                "export AFRILANG_PACKAGE_GIT_URL=https://github.com/vous/mon_lib\n"
                "export AFRILANG_REGISTRY_TOKEN=...\n"
                "afrilang pkg publish ./mon_lib --remote",
                "Distant",
            ),
            h2("8. Import"),
            code('import "pkg/math/math.afr"\nuse math'),
            callout('Référence dépôt : <code>docs/PKG.md</code>. Index exemple : <code>packages/remote-index.example.json</code>.'),
        ],
        [
            callout("<strong>Goal</strong> — Create, depend, install, test and publish a package."),
            h2("1. Project files"),
            table(
                ["File", "Role"],
                [
                    ["<code>afrilang.toml</code>", "Metadata + <code>[dependencies]</code>"],
                    ["<code>afrilang.lock</code>", "Exact versions (source of truth for install)"],
                    ["<code>vendor/</code>", "Local package copies"],
                    ["<code>manifest.toml</code>", "Library metadata"],
                    ["<code>packages/index.json</code>", "Local index"],
                    ["<code>packages/remote-index.json</code>", "Remote index (<code>pkg sync</code>)"],
                ],
            ),
            h2("2. Create"),
            code(
                "afrilang init my_app\n"
                "afrilang init my_lib --lib\n"
                "afrilang pkg init my_lib\n"
                "cd my_lib && afrilang pkg test\n"
                "afrilang doc .",
                "Terminal",
            ),
            h2("3. Dependencies — registry"),
            code('[dependencies]\nmath = "0.1.0"\nstrings = "^0.1.0"', "afrilang.toml"),
            code(
                "afrilang pkg sync\n"
                "afrilang pkg add math\n"
                "afrilang pkg install\n"
                "afrilang pkg update",
                "Terminal",
            ),
            h2("4. Semver"),
            table(
                ["Range", "Meaning"],
                [
                    ["<code>1.2.3</code>", "<code>&gt;= 1.2.3</code> (historical compat)"],
                    ["<code>^1.2.3</code>", "<code>&gt;= 1.2.3</code> and <code>&lt; 2.0.0</code>"],
                    ["<code>~1.2.3</code>", "<code>&gt;= 1.2.3</code> and <code>&lt; 1.3.0</code>"],
                ],
            ),
            h2("5. Git / path"),
            code('mylib = { git = "https://github.com/org/mylib.git", tag = "v0.1.0" }', "toml"),
            code('mylib = { path = "../mylib" }', "toml"),
            h2("6. Install vs update"),
            ul(
                [
                    "<code>pkg install</code> — if lock exists, install exactly; else resolve and write lock",
                    "<code>pkg update</code> — re-resolve from toml ranges, rewrite lock",
                    "Transitive deps resolved recursively; conflict = error",
                ]
            ),
            h2("7. Publish"),
            code("afrilang pkg publish ./my_lib", "Local"),
            code(
                "export AFRILANG_PACKAGE_GIT_URL=https://github.com/you/my_lib\n"
                "afrilang pkg publish ./my_lib --remote",
                "Remote",
            ),
            h2("8. Import"),
            code('import "pkg/math/math.afr"\nuse math'),
            callout("Repo reference: <code>docs/PKG.md</code>."),
        ],
    )

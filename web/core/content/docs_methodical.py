"""Documentation méthodique détaillée — remplace/enrichit les pages du guide."""

from .docs_pages import _page, callout, code, h2, p, table, ul
from .docs_methodical_extra import (
    async_page,
    exceptions_page,
    gui_page,
    modules_page,
    packages_page,
)
from .docs_methodical_more import (
    advanced_page,
    contributing_page,
    spec_page,
    stdlib_page,
    testing_page,
    tooling_page,
    wasm_page,
)


def register_methodical_documentation(pages):
    """Remplace les pages clés et ajoute testing / wasm / contributing."""
    pages['overview'] = _overview()
    pages['getting-started'] = _getting_started()
    pages['exceptions'] = exceptions_page()
    pages['modules'] = modules_page()
    pages['async'] = async_page()
    pages['gui'] = gui_page()
    pages['package-manager'] = packages_page()
    pages['stdlib'] = stdlib_page()
    pages['tooling'] = tooling_page()
    pages['spec'] = spec_page()
    pages['advanced'] = advanced_page()
    pages['testing'] = testing_page()
    pages['wasm'] = wasm_page()
    pages['contributing'] = contributing_page()


def _overview():
    return _page(
        'overview',
        'Documentation AFRILANG', 'AFRILANG Documentation',
        'Guide officiel méthodique : de l’installation à la production, '
        'page par page, dans un ordre d’apprentissage clair.',
        'Official methodical guide: from install to production, '
        'page by page, in a clear learning order.',
        [
            callout(
                '<strong>Comment lire cette doc</strong> — Suivez les étapes numérotées. '
                'Chaque page : objectif → prérequis → procédure → exemples → erreurs fréquentes → suite.'
            ),
            h2('1. Qu’est-ce qu’AFRILANG ?'),
            p(
                'AFRILANG est un langage <strong>orienté objet</strong> à '
                '<strong>syntaxe naturelle</strong> (mots-clés français ou anglais). '
                'Le compilateur <strong>transpile vers C++17</strong>, puis invoque '
                '<code>g++</code> pour produire un <strong>binaire natif</strong> '
                '(pas de VM ni d’interpréteur).'
            ),
            table(['Concept', 'Équivalent'], [
                ['Fichier source', '<code>.afr</code>'],
                ['Compilation', '<code>afrilang run</code> / <code>build</code>'],
                ['Cible', 'natif (x64, ARM) ou <code>wasm32</code>'],
                ['Paquets', '<code>afrilang.toml</code> + <code>pkg</code>'],
                ['Stdlib', '<code>import "std/…"</code>'],
            ]),
            h2('2. Parcours d’apprentissage (méthode)'),
            p('Suivez cet ordre. Ne sautez pas les étapes 1–4 si vous débutez.'),
            table(['Étape', 'Page', 'Vous savez…'], [
                ['1', '<a href="/docs/getting-started/">Premiers pas</a>', 'Installer et lancer <code>hello.afr</code>'],
                ['2', '<a href="/docs/syntax/">Syntaxe</a>', 'Variables, if, boucles, listes, fonctions'],
                ['3', '<a href="/docs/types/">Types</a>', 'number/text/bool, optionnels, Result'],
                ['4', '<a href="/docs/functional/">Lambdas</a>', 'map / filter / reduce naturels'],
                ['5', '<a href="/docs/oop/">POO</a>', 'Classes, héritage, interfaces'],
                ['6', '<a href="/docs/pattern-matching/">Pattern matching</a>', 'Enums, unions, match'],
                ['7', '<a href="/docs/modules/">Modules</a>', 'import / use / export'],
                ['8', '<a href="/docs/exceptions/">Exceptions</a> + Result', 'Erreurs contrôlées'],
                ['9', '<a href="/docs/async/">Async</a>', 'await, sleep, I/O async'],
                ['10', '<a href="/docs/stdlib/">Stdlib</a>', 'Core vs expérimental'],
                ['11', '<a href="/docs/package-manager/">Paquets</a>', 'toml, lock, publish'],
                ['12', '<a href="/docs/testing/">Tests</a>', '<code>test</code>, <code>--specs</code>'],
                ['13', '<a href="/docs/tooling/">Outils</a> + <a href="/docs/wasm/">WASM</a>', 'LSP, IDE, cibles'],
                ['14', '<a href="/docs/contributing/">Contribuer</a>', 'PR, conventions, CI'],
            ]),
            h2('3. Trois façons de pratiquer'),
            ul([
                '<strong>Playground</strong> — <a href="/playground/">/playground/</a> (sans installer)',
                '<strong>Tutoriel</strong> — <a href="/tutorial/">/tutorial/</a> (7 leçons guidées)',
                '<strong>Exemples CI</strong> — <a href="/examples/">/examples/</a> + dossier <code>examples/</code>',
            ]),
            h2('4. Principes du langage (à retenir)'),
            ul([
                'Tout bloc se ferme par <code>end</code> (ou <code>fin</code>).',
                'Comparaisons en mots : <code>is equal to</code>, <code>is greater than</code>.',
                'Optionnel = <code>T?</code> + <code>nothing</code> + <code>is defined</code> (pas <code>none</code>/<code>is some</code>).',
                'Result = <code>T or error</code> + <code>is error</code> + <code>.value</code> / <code>.message</code>.',
                'Les fonctions de test se déclarent <strong>hors</strong> des blocs <code>test</code>.',
            ]),
            callout(
                '<strong>Suite immédiate :</strong> '
                '<a href="/docs/getting-started/">Premiers pas →</a>',
                'info',
            ),
        ],
        [
            callout(
                '<strong>How to read this docs</strong> — Follow the numbered steps. '
                'Each page: goal → prerequisites → procedure → examples → common errors → next.'
            ),
            h2('1. What is AFRILANG?'),
            p(
                'AFRILANG is an <strong>object-oriented</strong> language with '
                '<strong>natural-language syntax</strong> (French or English keywords). '
                'The compiler <strong>transpiles to C++17</strong>, then runs '
                '<code>g++</code> to produce a <strong>native binary</strong> '
                '(no VM, no interpreter).'
            ),
            table(['Concept', 'Equivalent'], [
                ['Source file', '<code>.afr</code>'],
                ['Build', '<code>afrilang run</code> / <code>build</code>'],
                ['Target', 'native (x64, ARM) or <code>wasm32</code>'],
                ['Packages', '<code>afrilang.toml</code> + <code>pkg</code>'],
                ['Stdlib', '<code>import "std/…"</code>'],
            ]),
            h2('2. Learning path (method)'),
            p('Follow this order. Do not skip steps 1–4 if you are new.'),
            table(['Step', 'Page', 'You can…'], [
                ['1', '<a href="/docs/getting-started/">Getting started</a>', 'Install and run <code>hello.afr</code>'],
                ['2', '<a href="/docs/syntax/">Syntax</a>', 'Variables, if, loops, lists, functions'],
                ['3', '<a href="/docs/types/">Types</a>', 'number/text/bool, optionals, Result'],
                ['4', '<a href="/docs/functional/">Lambdas</a>', 'Natural map / filter / reduce'],
                ['5', '<a href="/docs/oop/">OOP</a>', 'Classes, inheritance, interfaces'],
                ['6', '<a href="/docs/pattern-matching/">Pattern matching</a>', 'Enums, unions, match'],
                ['7', '<a href="/docs/modules/">Modules</a>', 'import / use / export'],
                ['8', '<a href="/docs/exceptions/">Exceptions</a> + Result', 'Controlled errors'],
                ['9', '<a href="/docs/async/">Async</a>', 'await, sleep, async I/O'],
                ['10', '<a href="/docs/stdlib/">Stdlib</a>', 'Core vs experimental'],
                ['11', '<a href="/docs/package-manager/">Packages</a>', 'toml, lock, publish'],
                ['12', '<a href="/docs/testing/">Testing</a>', '<code>test</code>, <code>--specs</code>'],
                ['13', '<a href="/docs/tooling/">Tooling</a> + <a href="/docs/wasm/">WASM</a>', 'LSP, IDE, targets'],
                ['14', '<a href="/docs/contributing/">Contributing</a>', 'PRs, conventions, CI'],
            ]),
            h2('3. Three ways to practice'),
            ul([
                '<strong>Playground</strong> — <a href="/playground/">/playground/</a> (no install)',
                '<strong>Tutorial</strong> — <a href="/tutorial/">/tutorial/</a> (7 guided lessons)',
                '<strong>CI examples</strong> — <a href="/examples/">/examples/</a> + <code>examples/</code>',
            ]),
            h2('4. Language principles (memorize)'),
            ul([
                'Every block ends with <code>end</code> (or <code>fin</code>).',
                'Comparisons in words: <code>is equal to</code>, <code>is greater than</code>.',
                'Optional = <code>T?</code> + <code>nothing</code> + <code>is defined</code> (not <code>none</code>/<code>is some</code>).',
                'Result = <code>T or error</code> + <code>is error</code> + <code>.value</code> / <code>.message</code>.',
                'Test helper functions are declared <strong>outside</strong> <code>test</code> blocks.',
            ]),
            callout(
                '<strong>Next:</strong> '
                '<a href="/docs/getting-started/">Getting started →</a>',
                'info',
            ),
        ],
    )


def _getting_started():
    return _page(
        'getting-started',
        'Premiers pas', 'Getting started',
        'Installation méthodique du compilateur, premier programme, projet, PATH, vérification.',
        'Methodical compiler install, first program, project, PATH, verification.',
        [
            callout('<strong>Objectif</strong> — À la fin : <code>afrilang --version</code> fonctionne et '
                    '<code>hello.afr</code> s’exécute.'),
            h2('Étape 0 — Prérequis'),
            table(['Outil', 'Minimum', 'Pourquoi'], [
                ['Linux', 'Ubuntu/Debian recommandés', 'Toolchain CI de référence'],
                ['Git', '2.x', 'Cloner le dépôt'],
                ['CMake', '≥ 3.16', 'Build du compilateur'],
                ['g++', 'C++17 (C++20 pour async)', 'Compilation du runtime'],
                ['Optionnel', 'Emscripten, SDL2, sqlite3-dev', 'WASM / GUI / demos ultra'],
            ]),
            code('sudo apt-get update\nsudo apt-get install -y git cmake g++ build-essential', 'Terminal'),
            h2('Étape 1 — Installer le compilateur (sources)'),
            code('''git clone https://github.com/MaximeKELI/AFRILANG.git
cd AFRILANG
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
./build/afrilang --version''', 'Terminal'),
            p('Le binaire est <code>build/afrilang</code>. La racine du repo sert de '
              '<code>AFRILANG_HOME</code> (stdlib, packages, runtime).'),
            h2('Étape 2 — Mettre dans le PATH'),
            code('''mkdir -p ~/.local/bin
cp build/afrilang ~/.local/bin/
echo 'export AFRILANG_HOME="$HOME/AFRILANG"' >> ~/.bashrc
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
afrilang --version''', 'Terminal'),
            h2('Étape 3 — Alternative : page Télécharger'),
            p('Binaire précompilé (si disponible) : <a href="/download/">/download/</a>. '
              'Configurez quand même <code>AFRILANG_HOME</code> vers un clone du dépôt '
              '(stdlib + packages).'),
            h2('Étape 4 — Premier fichier'),
            code('''say "Bonjour depuis AFRILANG!"
repeat 3 times
    say "Hello"
end''', 'hello.afr'),
            code('afrilang run hello.afr', 'Terminal'),
            p('Le compilateur génère du C++, compile avec <code>g++</code>, puis exécute le binaire.'),
            h2('Étape 5 — Créer un projet'),
            code('''afrilang init mon_app
cd mon_app
afrilang run src/main.afr
afrilang test''', 'Terminal'),
            ul([
                '<code>afrilang.toml</code> — métadonnées + dépendances',
                '<code>src/main.afr</code> — point d’entrée',
                '<code>tests/</code> — fichiers <code>*.afr</code> de test',
                '<code>afrilang init mon_lib --lib</code> — scaffold bibliothèque',
            ]),
            h2('Étape 6 — Checklist de validation'),
            ul([
                '<code>afrilang --version</code> affiche 1.x',
                '<code>afrilang run examples/hello.afr</code> (depuis le dépôt) réussit',
                '<code>echo $AFRILANG_HOME</code> pointe vers le clone',
                'Extension VS Code/Cursor installée (optionnel) : voir Outils',
            ]),
            h2('Erreurs fréquentes'),
            table(['Symptôme', 'Cause', 'Remède'], [
                ['<code>commande introuvable</code>', 'Pas dans PATH', 'Copier vers <code>~/.local/bin</code>'],
                ['stdlib introuvable', '<code>AFRILANG_HOME</code> absent', 'Exporter la variable'],
                ['échec g++', 'toolchain manquante', 'Installer <code>build-essential</code>'],
            ]),
            callout('<strong>Suite :</strong> <a href="/docs/syntax/">Syntaxe de base →</a>'),
        ],
        [
            callout('<strong>Goal</strong> — By the end: <code>afrilang --version</code> works and '
                    '<code>hello.afr</code> runs.'),
            h2('Step 0 — Prerequisites'),
            table(['Tool', 'Minimum', 'Why'], [
                ['Linux', 'Ubuntu/Debian recommended', 'CI reference toolchain'],
                ['Git', '2.x', 'Clone the repo'],
                ['CMake', '≥ 3.16', 'Build the compiler'],
                ['g++', 'C++17 (C++20 for async)', 'Compile the runtime'],
                ['Optional', 'Emscripten, SDL2, sqlite3-dev', 'WASM / GUI / ultra demos'],
            ]),
            code('sudo apt-get update\nsudo apt-get install -y git cmake g++ build-essential', 'Terminal'),
            h2('Step 1 — Install the compiler (from source)'),
            code('''git clone https://github.com/MaximeKELI/AFRILANG.git
cd AFRILANG
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
./build/afrilang --version''', 'Terminal'),
            p('The binary is <code>build/afrilang</code>. The repo root is '
              '<code>AFRILANG_HOME</code> (stdlib, packages, runtime).'),
            h2('Step 2 — Put it on PATH'),
            code('''mkdir -p ~/.local/bin
cp build/afrilang ~/.local/bin/
echo 'export AFRILANG_HOME="$HOME/AFRILANG"' >> ~/.bashrc
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
afrilang --version''', 'Terminal'),
            h2('Step 3 — Alternative: Download page'),
            p('Prebuilt binary (when available): <a href="/download/">/download/</a>. '
              'Still set <code>AFRILANG_HOME</code> to a clone of the repo '
              '(stdlib + packages).'),
            h2('Step 4 — First file'),
            code('''say "Hello from AFRILANG!"
repeat 3 times
    say "Hello"
end''', 'hello.afr'),
            code('afrilang run hello.afr', 'Terminal'),
            p('The compiler emits C++, builds with <code>g++</code>, then runs the binary.'),
            h2('Step 5 — Create a project'),
            code('''afrilang init my_app
cd my_app
afrilang run src/main.afr
afrilang test''', 'Terminal'),
            ul([
                '<code>afrilang.toml</code> — metadata + dependencies',
                '<code>src/main.afr</code> — entry point',
                '<code>tests/</code> — <code>*.afr</code> test files',
                '<code>afrilang init my_lib --lib</code> — library scaffold',
            ]),
            h2('Step 6 — Validation checklist'),
            ul([
                '<code>afrilang --version</code> prints 1.x',
                '<code>afrilang run examples/hello.afr</code> (from the repo) succeeds',
                '<code>echo $AFRILANG_HOME</code> points at the clone',
                'VS Code/Cursor extension installed (optional): see Tooling',
            ]),
            h2('Common errors'),
            table(['Symptom', 'Cause', 'Fix'], [
                ['command not found', 'Not on PATH', 'Copy to <code>~/.local/bin</code>'],
                ['stdlib missing', 'No <code>AFRILANG_HOME</code>', 'Export the variable'],
                ['g++ failure', 'Missing toolchain', 'Install <code>build-essential</code>'],
            ]),
            callout('<strong>Next:</strong> <a href="/docs/syntax/">Basic syntax →</a>'),
        ],
    )

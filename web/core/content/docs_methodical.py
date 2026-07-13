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
from .docs_prose import enrich_language_pages_with_prose


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
    enrich_language_pages_with_prose(pages)


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
            callout(
                '<strong>Objectif</strong> — À la fin de cette page : '
                '<code>afrilang --version</code> répond, et un fichier <code>hello.afr</code> '
                's’exécute sur votre machine. Lisez chaque paragraphe <em>avant</em> de coller '
                'les commandes : le code montre ; le texte explique pourquoi.'
            ),
            h2('Étape 0 — Prérequis'),
            p(
                'AFRILANG ne s’exécute pas dans une machine virtuelle : le compilateur produit '
                'du C++, puis <code>g++</code> fabrique un binaire. '
                'Il vous faut donc une machine Linux avec une toolchain C++ classique. '
                'Les paquets optionnels (SDL2, Emscripten, sqlite) ne sont nécessaires '
                'que si vous touchez GUI, WASM ou certaines demos « ultra ».'
            ),
            table(['Outil', 'Minimum', 'Pourquoi'], [
                ['Linux', 'Ubuntu/Debian recommandés', 'Toolchain CI de référence'],
                ['Git', '2.x', 'Cloner le dépôt'],
                ['CMake', '≥ 3.16', 'Build du compilateur'],
                ['g++', 'C++17 (C++20 pour async)', 'Compilation du runtime'],
                ['Optionnel', 'Emscripten, SDL2, sqlite3-dev', 'WASM / GUI / demos ultra'],
            ]),
            p('Sur Debian/Ubuntu, installez d’abord les outils de base :'),
            code('sudo apt-get update\nsudo apt-get install -y git cmake g++ build-essential', 'Terminal'),
            h2('Étape 1 — Installer le compilateur (sources)'),
            p(
                'La méthode la plus fiable est de compiler depuis le dépôt GitHub. '
                'Après le build, le binaire se trouve dans <code>build/afrilang</code>. '
                'La <strong>racine du clone</strong> doit rester accessible : '
                'c’est elle qui fournit la stdlib, les packages et le runtime '
                '(via <code>AFRILANG_HOME</code> à l’étape suivante).'
            ),
            code('''git clone https://github.com/MaximeKELI/AFRILANG.git
cd AFRILANG
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
./build/afrilang --version''', 'Terminal'),
            h2('Étape 2 — Mettre dans le PATH'),
            p(
                'Sans PATH, vous devez taper le chemin complet à chaque fois. '
                'Sans <code>AFRILANG_HOME</code>, le compilateur ne trouve pas la stdlib '
                '(erreur du type « module introuvable »). '
                'Les deux exports ci-dessous résolvent ces deux problèmes. '
                'Adaptez le chemin si votre clone n’est pas dans <code>$HOME/AFRILANG</code>.'
            ),
            code('''mkdir -p ~/.local/bin
cp build/afrilang ~/.local/bin/
echo 'export AFRILANG_HOME="$HOME/AFRILANG"' >> ~/.bashrc
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
afrilang --version''', 'Terminal'),
            h2('Étape 3 — Alternative : page Télécharger'),
            p(
                'Si un binaire précompilé est proposé sur '
                '<a href="/download/">/download/</a>, vous pouvez l’utiliser. '
                'Gardez quand même un clone du dépôt pour <code>AFRILANG_HOME</code> : '
                'le binaire seul ne contient pas toute la stdlib.'
            ),
            h2('Étape 4 — Premier fichier'),
            p(
                'Créez un fichier texte <code>hello.afr</code>. '
                '<code>say</code> affiche une ligne. '
                '<code>repeat 3 times … end</code> répète un bloc trois fois. '
                'Puis lancez <code>afrilang run</code> : le compilateur transpile en C++, '
                'appelle <code>g++</code>, et exécute le programme résultant. '
                'Vous ne voyez pas le C++ sauf si vous demandez un build sans run.'
            ),
            code('''say "Bonjour depuis AFRILANG!"
repeat 3 times
    say "Hello"
end''', 'hello.afr'),
            code('afrilang run hello.afr', 'Terminal'),
            h2('Étape 5 — Créer un projet'),
            p(
                '<code>afrilang init</code> prépare une structure standard : '
                'métadonnées (<code>afrilang.toml</code>), point d’entrée '
                '(<code>src/main.afr</code>), dossier de tests. '
                'C’est le format attendu par <code>pkg</code> et <code>afrilang test</code>. '
                'Pour une bibliothèque publiable, ajoutez <code>--lib</code>.'
            ),
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
            p('Cochez mentalement chaque point avant de passer à la syntaxe :'),
            ul([
                '<code>afrilang --version</code> affiche 1.x',
                '<code>afrilang run examples/hello.afr</code> (depuis le dépôt) réussit',
                '<code>echo $AFRILANG_HOME</code> pointe vers le clone',
                'Extension VS Code/Cursor installée (optionnel) : voir Outils',
            ]),
            h2('Erreurs fréquentes'),
            p(
                'La plupart des blocages d’installation se réduisent à trois causes : '
                'commande absente du PATH, stdlib introuvable, ou compilateur C++ manquant.'
            ),
            table(['Symptôme', 'Cause', 'Remède'], [
                ['<code>commande introuvable</code>', 'Pas dans PATH', 'Copier vers <code>~/.local/bin</code>'],
                ['stdlib introuvable', '<code>AFRILANG_HOME</code> absent', 'Exporter la variable'],
                ['échec g++', 'toolchain manquante', 'Installer <code>build-essential</code>'],
            ]),
            callout('<strong>Suite :</strong> <a href="/docs/syntax/">Syntaxe de base →</a>'),
        ],
        [
            callout(
                '<strong>Goal</strong> — By the end: <code>afrilang --version</code> works and '
                '<code>hello.afr</code> runs. Read each paragraph <em>before</em> pasting commands.'
            ),
            h2('Step 0 — Prerequisites'),
            p(
                'AFRILANG has no VM: the compiler emits C++, then <code>g++</code> builds a binary. '
                'You need a Linux box with a normal C++ toolchain. '
                'Optional packages (SDL2, Emscripten, sqlite) are only for GUI / WASM / some demos.'
            ),
            table(['Tool', 'Minimum', 'Why'], [
                ['Linux', 'Ubuntu/Debian recommended', 'CI reference toolchain'],
                ['Git', '2.x', 'Clone the repo'],
                ['CMake', '≥ 3.16', 'Build the compiler'],
                ['g++', 'C++17 (C++20 for async)', 'Compile the runtime'],
                ['Optional', 'Emscripten, SDL2, sqlite3-dev', 'WASM / GUI / ultra demos'],
            ]),
            p('On Debian/Ubuntu, install the basics first:'),
            code('sudo apt-get update\nsudo apt-get install -y git cmake g++ build-essential', 'Terminal'),
            h2('Step 1 — Install the compiler (from source)'),
            p(
                'The most reliable path is building from the GitHub repo. '
                'The binary lands in <code>build/afrilang</code>. '
                'Keep the <strong>clone root</strong> available: it provides stdlib, packages, '
                'and runtime via <code>AFRILANG_HOME</code> next.'
            ),
            code('''git clone https://github.com/MaximeKELI/AFRILANG.git
cd AFRILANG
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
./build/afrilang --version''', 'Terminal'),
            h2('Step 2 — Put it on PATH'),
            p(
                'Without PATH you type the full path every time. '
                'Without <code>AFRILANG_HOME</code> the compiler cannot find the stdlib. '
                'Adapt the path if your clone is not under <code>$HOME/AFRILANG</code>.'
            ),
            code('''mkdir -p ~/.local/bin
cp build/afrilang ~/.local/bin/
echo 'export AFRILANG_HOME="$HOME/AFRILANG"' >> ~/.bashrc
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
afrilang --version''', 'Terminal'),
            h2('Step 3 — Alternative: Download page'),
            p(
                'If a prebuilt binary is on <a href="/download/">/download/</a>, you may use it. '
                'Still keep a repo clone for <code>AFRILANG_HOME</code>.'
            ),
            h2('Step 4 — First file'),
            p(
                'Create <code>hello.afr</code>. <code>say</code> prints a line; '
                '<code>repeat … end</code> repeats a block. '
                '<code>afrilang run</code> transpiles to C++, runs <code>g++</code>, then executes.'
            ),
            code('''say "Hello from AFRILANG!"
repeat 3 times
    say "Hello"
end''', 'hello.afr'),
            code('afrilang run hello.afr', 'Terminal'),
            h2('Step 5 — Create a project'),
            p(
                '<code>afrilang init</code> scaffolds metadata, entry point, and tests — '
                'the layout expected by <code>pkg</code> and <code>afrilang test</code>. '
                'Use <code>--lib</code> for a publishable library.'
            ),
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
            p('Check each point before moving on to syntax:'),
            ul([
                '<code>afrilang --version</code> prints 1.x',
                '<code>afrilang run examples/hello.afr</code> (from the repo) succeeds',
                '<code>echo $AFRILANG_HOME</code> points at the clone',
                'VS Code/Cursor extension installed (optional): see Tooling',
            ]),
            h2('Common errors'),
            p('Most install blockers are PATH, missing <code>AFRILANG_HOME</code>, or no C++ toolchain.'),
            table(['Symptom', 'Cause', 'Fix'], [
                ['command not found', 'Not on PATH', 'Copy to <code>~/.local/bin</code>'],
                ['stdlib missing', 'No <code>AFRILANG_HOME</code>', 'Export the variable'],
                ['g++ failure', 'Missing toolchain', 'Install <code>build-essential</code>'],
            ]),
            callout('<strong>Next:</strong> <a href="/docs/syntax/">Basic syntax →</a>'),
        ],
    )

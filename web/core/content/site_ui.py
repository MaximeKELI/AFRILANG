"""UI strings FR/EN — site officiel AFRILANG."""

UI = {
    'fr': {
        'nav_language': 'Le langage',
        'nav_docs': 'Documentation',
        'nav_ecosystem': 'Écosystème',
        'nav_packages': 'Paquets',
        'nav_playground': 'Playground',
        'nav_tutorial': 'Tutoriel',
        'nav_examples': 'Exemples',
        'nav_stdlib': 'Stdlib',
        'nav_download': 'Télécharger',
        'nav_community': 'Communauté',
        'nav_api': 'API',
        'nav_github': 'GitHub',
        'nav_start': 'Commencer',
        'nav_theme_light': 'Mode clair',
        'nav_theme_dark': 'Mode sombre',
        'nav_version_label': 'Langage · v',
        'skip_link': 'Aller au contenu principal',
        'footer_learn': 'Apprendre',
        'footer_reference': 'Référence',
        'footer_community': 'Communauté',
        'footer_versions': 'Versions',
        'footer_lang': 'Langage',
        'footer_compiler': 'Compilateur',
        'footer_tagline': 'Codez en phrases, déployez en natif.',
        'footer_desc': (
            'Langage orienté objet à syntaxe naturelle. Transpile vers C++17 '
            'et compile en binaire natif. Open source, licence MIT.'
        ),
        'cookie_text': 'Ce site utilise des cookies de session pour la langue et le playground.',
        'cookie_accept': 'Accepter',
        'cookie_decline': 'Refuser',
        'meta_default': (
            'AFRILANG — langage orienté objet à syntaxe naturelle, transpile vers C++17, '
            'bibliothèque standard riche, outils LSP et playground.'
        ),
        'home': {
            'title': 'AFRILANG — Codez en phrases, déployez en natif',
            'badge': 'Open source · MIT',
            'hero_h1_a': 'Codez en',
            'hero_h1_b': 'langage naturel',
            'hero_h1_c': 'compilez en natif.',
            'hero_lead': (
                'AFRILANG est un langage orienté objet à syntaxe lisible qui transpile vers C++17. '
                'Classes, génériques, pattern matching, async/await — avec une bibliothèque standard '
                'et une toolchain complète.'
            ),
            'hero_compat': 'Compatible français et anglais · LSP · REPL · WASM · cross-compilation',
            'btn_start': 'Commencer',
            'btn_try': 'Essayer en ligne',
            'btn_tutorial': 'Tutoriel interactif',
            'stat_examples': 'Exemples officiels',
            'stat_stdlib': 'Modules stdlib',
            'stat_packages': 'Paquets certifiés',
            'stat_targets': 'Cibles (x64, ARM, WASM)',
            'why_label': 'Pourquoi AFRILANG',
            'why_title': 'Lisible comme une phrase, performant comme du C++',
            'why_desc': (
                "Conçu pour l'apprentissage et la production : syntaxe naturelle, erreurs explicites, "
                'outils modernes et écosystème open source africain.'
            ),
            'feat_natural_title': 'Syntaxe naturelle',
            'feat_natural': (
                '<code>if age is greater than 18 then</code> au lieu de symboles cryptiques. '
                'Mots-clés en français (<code>dire</code>, <code>si</code>, <code>fin</code>) ou en anglais.'
            ),
            'feat_perf_title': 'Performance native',
            'feat_perf': (
                'Transpilation vers C++17 puis compilation <code>g++</code>. Binaires natifs, '
                'cross-compilation linux-x64, linux-arm64 et wasm32.'
            ),
            'feat_modern_title': 'Moderne et complet',
            'feat_modern': (
                'POO, génériques, enums, match, traits, async/await, Result, null-safety, '
                "surcharge d'opérateurs et FFI."
            ),
            'feat_stdlib_title': 'Stdlib massive',
            'feat_stdlib': (
                'I/O, JSON, HTTP, collections, graphes, stats, crypto, finance, NLP… '
                'Plus de 460 modules via <code>import "std/…"</code>.'
            ),
            'feat_tools_title': 'Toolchain intégrée',
            'feat_tools': (
                'CLI (<code>build</code>, <code>test</code>, <code>fmt</code>, <code>lint</code>), '
                'LSP 1.1, REPL, debug adapter, extension VS Code/Cursor, playground web.'
            ),
            'feat_africa_title': 'Open source africain',
            'feat_africa': (
                'Projet communautaire MIT. Gestionnaire de paquets, registre officiel '
                'et documentation complète pour contribuer.'
            ),
            'example_label': 'Exemple rapide',
            'example_title': 'De la phrase au binaire en une commande',
            'example_desc': (
                'Installez le compilateur, écrivez un fichier <code>.afr</code>, exécutez-le. '
                'Le pipeline transpile vers C++ puis invoque <code>g++</code> automatiquement.'
            ),
            'packages_label': 'Écosystème',
            'packages_title': 'Paquets certifiés',
            'packages_all': 'Voir tout →',
            'packages_empty': 'Registre vide — lancez <code>python manage.py sync_packages</code>',
            'cta_title': 'Prêt à écrire votre premier programme ?',
            'cta_desc': 'Documentation détaillée, playground interactif et extension IDE — tout est là.',
            'cta_guide': 'Guide de démarrage',
            'cta_lang': 'Découvrir le langage',
            'cta_play': 'Playground',
            'cta_tutorial': 'Tutoriel interactif',
        },
        'tutorial_page': {
            'title': 'Tutoriel AFRILANG',
            'label': 'Apprendre',
            'h1': 'Tutoriel interactif',
            'lead': '7 leçons guidées — de Hello World à la POO et au pattern matching.',
            'sidebar': 'Parcours',
            'step_label': 'Étape',
            'objectives': 'Objectifs',
            'code_title': 'Code de la leçon',
            'copy': 'Copier',
            'try_playground': 'Essayer dans le playground',
            'challenge': 'Défi',
            'prev': 'Précédent',
            'next': 'Suivant',
            'overview': 'Vue d\'ensemble',
            'mark_done': 'Marquer comme terminé',
            'finish': 'Installer le compilateur',
            'read_doc': 'Lire la documentation →',
            'start': 'Commencer le tutoriel',
            'completed': 'terminées',
        },
        'language_page': {
            'title': 'Le langage AFRILANG',
            'meta': 'Présentation d\'AFRILANG : syntaxe naturelle bilingue, transpilation C++, POO, génériques, async.',
            'label': 'AFRILANG {version}',
            'h1': 'Un langage qui se lit, un compilateur qui livre',
            'lead': (
                'AFRILANG combine la lisibilité du langage naturel avec la rigueur d\'un compilateur moderne. '
                'Vous écrivez des programmes qui ressemblent à des phrases ; le compilateur les transforme '
                'en C++17 optimisé, puis en exécutables natifs.'
            ),
        },
        'download': {
            'title': 'Télécharger AFRILANG',
            'h1': 'Installer le compilateur',
            'lead': 'Binaire précompilé, script d\'installation ou compilation depuis les sources.',
            'binary_title': 'Binaire précompilé',
            'binary_lead': 'Téléchargez le compilateur compilé sur ce serveur (Linux x64).',
            'binary_download': 'Télécharger',
            'binary_none': 'Aucun binaire disponible sur ce serveur — compilez depuis les sources ou consultez GitHub Releases.',
            'binary_sha256': 'SHA256',
            'binary_size': 'Taille',
            'install_title': 'Installation rapide',
            'install_lead': 'Script bash — clone, compile et installe dans ~/.local/afrilang',
            'github_title': 'GitHub Releases',
            'github_lead': 'Versions officielles et artefacts CI sur GitHub.',
            'github_btn': 'Voir les releases',
            'requirements': 'Prérequis',
            'build': 'Compilation depuis les sources',
            'verify': 'Vérification',
            'ide': 'Extension IDE',
        },
        'community': {
            'title': 'Communauté AFRILANG',
            'h1': 'Rejoindre la communauté',
            'lead': 'Contribuer, signaler des bugs, publier des paquets et participer au projet open source.',
        },
        'api_page': {
            'title': 'API REST — Playground',
            'h1': 'API HTTP du playground',
            'lead': 'Endpoints JSON pour exécuter, formater et lister les paquets AFRILANG.',
            'run_desc': 'Exécute du source AFRILANG (compilation native).',
            'fmt_desc': 'Formate le source et renvoie le code formaté.',
            'pkg_desc': 'Liste tous les paquets du registre.',
        },
        'explore': {
            'title': 'Écosystème AFRILANG',
            'label': 'Écosystème complet',
            'h1': 'Tout ce qui compose AFRILANG',
            'lead': 'Langage, compilateur, stdlib, paquets, WASM, LSP, debug et CI.',
            'empty': 'Données non chargées — exécutez python manage.py seed_data',
            'btn_tools': 'Documentation outils',
            'btn_packages': 'Registre de paquets',
        },
        'packages_page': {
            'title': 'Paquets AFRILANG',
            'label': 'Gestionnaire de paquets',
            'h1': 'Registre officiel',
            'lead': 'Paquets certifiés (★) avec vérification SHA256.',
            'search': 'Rechercher un paquet…',
            'filter': 'Filtrer',
            'empty': 'Aucun paquet trouvé.',
            'usage_title': 'Utiliser un paquet',
        },
        'playground_page': {
            'title': 'Playground AFRILANG',
            'label': 'Essayer en ligne',
            'h1': 'Playground AFRILANG',
            'lead': 'Écrivez du code, exécutez-le, vérifiez-le ou formatez-le en direct.',
            'example': 'Exemple',
            'run': 'Run',
            'run_browser': 'Browser',
            'wasm': 'WASM in browser',
            'format': 'Format',
            'check': 'Check',
            'share': 'Partager',
            'copy_output': 'Copier',
            'output': 'Sortie',
            'output_hint': 'Cliquez sur Run pour exécuter votre code.',
            'help': 'Consultez la syntaxe de base ou les premiers pas.',
            'shortcut_run': 'Ctrl+Entrée pour exécuter',
            'wasm_hint': 'Exécution instantanée dans le navigateur — sans charge serveur pour les programmes simples.',
        },
        'examples_page': {
            'title': 'Exemples AFRILANG',
            'label': 'Galerie',
            'h1': 'Exemples officiels',
            'lead': 'Programmes du dépôt examples/ — ouvrez-les dans le playground en un clic.',
            'search': 'Rechercher un exemple…',
            'filter': 'Filtrer',
            'empty': 'Aucun exemple — lancez python manage.py sync_examples',
            'try_btn': 'Essayer',
        },
        'stdlib_page': {
            'title': 'Bibliothèque standard',
            'label': 'Stdlib',
            'h1': 'Navigateur stdlib',
            'lead': 'Parcourez les modules de la bibliothèque standard AFRILANG.',
            'search': 'Rechercher un module…',
            'filter': 'Filtrer',
            'empty': 'Aucun module — lancez python manage.py sync_stdlib',
            'count_label': 'modules',
            'exports': 'Fonctions',
            'try_playground': 'Playground',
        },
        'releases_page': {
            'title': 'Versions AFRILANG',
            'label': 'Changelog',
            'h1': 'Historique des versions',
            'lead': 'Notes de version et nouveautés du compilateur et de la stdlib.',
            'empty': 'Aucune release — lancez python manage.py sync_releases',
        },
        'docs_search_page': {
            'title': 'Recherche documentation',
            'h1': 'Rechercher dans la doc',
            'search': 'Mot-clé…',
            'filter': 'Rechercher',
            'hint': 'Entrez au moins 2 caractères pour lancer la recherche.',
            'min_chars': 'Entrez au moins 2 caractères.',
            'results_label': 'résultat(s)',
            'empty': 'Aucun résultat pour cette requête.',
        },
    },
    'en': {
        'nav_language': 'Language',
        'nav_docs': 'Documentation',
        'nav_ecosystem': 'Ecosystem',
        'nav_packages': 'Packages',
        'nav_playground': 'Playground',
        'nav_tutorial': 'Tutorial',
        'nav_examples': 'Examples',
        'nav_stdlib': 'Stdlib',
        'nav_download': 'Download',
        'nav_community': 'Community',
        'nav_api': 'API',
        'nav_github': 'GitHub',
        'nav_start': 'Get started',
        'nav_theme_light': 'Light mode',
        'nav_theme_dark': 'Dark mode',
        'nav_version_label': 'Language · v',
        'skip_link': 'Skip to main content',
        'footer_learn': 'Learn',
        'footer_reference': 'Reference',
        'footer_community': 'Community',
        'footer_versions': 'Versions',
        'footer_lang': 'Language',
        'footer_compiler': 'Compiler',
        'footer_tagline': 'Code in sentences. Ship native binaries.',
        'footer_desc': (
            'Object-oriented language with natural-language syntax. Transpiles to C++17 '
            'and compiles to native binaries. Open source, MIT license.'
        ),
        'cookie_text': 'This site uses session cookies for language preference and the playground.',
        'cookie_accept': 'Accept',
        'cookie_decline': 'Decline',
        'meta_default': (
            'AFRILANG — natural-syntax OOP language transpiling to C++17, '
            'rich standard library, LSP tooling and web playground.'
        ),
        'home': {
            'title': 'AFRILANG — Code in sentences, ship native binaries',
            'badge': 'Open source · MIT',
            'hero_h1_a': 'Code in',
            'hero_h1_b': 'natural language',
            'hero_h1_c': 'compile to native.',
            'hero_lead': (
                'AFRILANG is a readable object-oriented language that transpiles to C++17. '
                'Classes, generics, pattern matching, async/await — with a standard library '
                'and a full developer toolchain.'
            ),
            'hero_compat': 'French & English syntax · LSP · REPL · WASM · cross-compilation',
            'btn_start': 'Get started',
            'btn_try': 'Try online',
            'btn_tutorial': 'Interactive tutorial',
            'stat_examples': 'Official examples',
            'stat_stdlib': 'Stdlib modules',
            'stat_packages': 'Certified packages',
            'stat_targets': 'Targets (x64, ARM, WASM)',
            'why_label': 'Why AFRILANG',
            'why_title': 'Readable like prose, fast like C++',
            'why_desc': (
                'Built for learning and production: natural syntax, clear errors, '
                'modern tooling and an African open-source ecosystem.'
            ),
            'feat_natural_title': 'Natural syntax',
            'feat_natural': (
                '<code>if age is greater than 18 then</code> instead of cryptic symbols. '
                'French keywords (<code>dire</code>, <code>si</code>, <code>fin</code>) or English.'
            ),
            'feat_perf_title': 'Native performance',
            'feat_perf': (
                'Transpilation to C++17 then <code>g++</code>. Native binaries, '
                'cross-compilation for linux-x64, linux-arm64 and wasm32.'
            ),
            'feat_modern_title': 'Modern & complete',
            'feat_modern': (
                'OOP, generics, enums, match, traits, async/await, Result, null-safety, '
                'operator overloading and FFI.'
            ),
            'feat_stdlib_title': 'Massive stdlib',
            'feat_stdlib': (
                'I/O, JSON, HTTP, collections, graphs, stats, crypto, finance, NLP… '
                '460+ modules via <code>import "std/…"</code>.'
            ),
            'feat_tools_title': 'Integrated toolchain',
            'feat_tools': (
                'CLI (<code>build</code>, <code>test</code>, <code>fmt</code>, <code>lint</code>), '
                'LSP 1.1, REPL, debug adapter, VS Code/Cursor extension, web playground.'
            ),
            'feat_africa_title': 'African open source',
            'feat_africa': (
                'Community MIT project. Package manager, official registry '
                'and full documentation to contribute.'
            ),
            'example_label': 'Quick example',
            'example_title': 'From sentence to binary in one command',
            'example_desc': (
                'Install the compiler, write a <code>.afr</code> file, run it. '
                'The pipeline transpiles to C++ and invokes <code>g++</code> automatically.'
            ),
            'packages_label': 'Ecosystem',
            'packages_title': 'Certified packages',
            'packages_all': 'View all →',
            'packages_empty': 'Empty registry — run <code>python manage.py sync_packages</code>',
            'cta_title': 'Ready to write your first program?',
            'cta_desc': 'Detailed docs, interactive playground and IDE extension — all included.',
            'cta_guide': 'Getting started guide',
            'cta_lang': 'Discover the language',
            'cta_play': 'Playground',
            'cta_tutorial': 'Interactive tutorial',
        },
        'tutorial_page': {
            'title': 'AFRILANG Tutorial',
            'label': 'Learn',
            'h1': 'Interactive tutorial',
            'lead': '7 guided lessons — from Hello World to OOP and pattern matching.',
            'sidebar': 'Path',
            'step_label': 'Step',
            'objectives': 'Objectives',
            'code_title': 'Lesson code',
            'copy': 'Copy',
            'try_playground': 'Try in playground',
            'challenge': 'Challenge',
            'prev': 'Previous',
            'next': 'Next',
            'overview': 'Overview',
            'mark_done': 'Mark as done',
            'finish': 'Install compiler',
            'read_doc': 'Read the docs →',
            'start': 'Start tutorial',
            'completed': 'completed',
        },
        'language_page': {
            'title': 'The AFRILANG language',
            'meta': 'AFRILANG overview: bilingual natural syntax, C++ transpilation, OOP, generics, async.',
            'label': 'AFRILANG {version}',
            'h1': 'A language you can read, a compiler that delivers',
            'lead': (
                'AFRILANG combines natural-language readability with a modern compiler. '
                'You write programs that read like sentences; the compiler transforms them '
                'into optimized C++17, then native executables.'
            ),
        },
        'download': {
            'title': 'Download AFRILANG',
            'h1': 'Install the compiler',
            'lead': 'Pre-built binary, install script or build from source.',
            'binary_title': 'Pre-built binary',
            'binary_lead': 'Download the compiler built on this server (Linux x64).',
            'binary_download': 'Download',
            'binary_none': 'No binary on this server — build from source or check GitHub Releases.',
            'binary_sha256': 'SHA256',
            'binary_size': 'Size',
            'install_title': 'Quick install',
            'install_lead': 'Bash script — clones, builds and installs to ~/.local/afrilang',
            'github_title': 'GitHub Releases',
            'github_lead': 'Official versions and CI artifacts on GitHub.',
            'github_btn': 'View releases',
            'requirements': 'Requirements',
            'build': 'Build from source',
            'verify': 'Verify',
            'ide': 'IDE extension',
        },
        'community': {
            'title': 'AFRILANG Community',
            'h1': 'Join the community',
            'lead': 'Contribute, report bugs, publish packages and participate in the open-source project.',
        },
        'api_page': {
            'title': 'REST API — Playground',
            'h1': 'Playground HTTP API',
            'lead': 'JSON endpoints to run, format and list AFRILANG packages.',
            'run_desc': 'Run AFRILANG source (native compilation).',
            'fmt_desc': 'Format source and return formatted code.',
            'pkg_desc': 'List all registry packages.',
        },
        'explore': {
            'title': 'AFRILANG Ecosystem',
            'label': 'Full ecosystem',
            'h1': 'Everything that makes AFRILANG',
            'lead': 'Language, compiler, stdlib, packages, WASM, LSP, debug and CI.',
            'empty': 'No data — run python manage.py seed_data',
            'btn_tools': 'Tooling docs',
            'btn_packages': 'Package registry',
        },
        'packages_page': {
            'title': 'AFRILANG Packages',
            'label': 'Package manager',
            'h1': 'Official registry',
            'lead': 'Certified packages (★) with SHA256 verification.',
            'search': 'Search packages…',
            'filter': 'Filter',
            'empty': 'No packages found.',
            'usage_title': 'Use a package',
        },
        'playground_page': {
            'title': 'AFRILANG Playground',
            'label': 'Try online',
            'h1': 'AFRILANG Playground',
            'lead': 'Write code, run, check or format it live.',
            'example': 'Example',
            'run': 'Run',
            'run_browser': 'Browser',
            'wasm': 'WASM in browser',
            'format': 'Format',
            'check': 'Check',
            'share': 'Share',
            'copy_output': 'Copy',
            'output': 'Output',
            'output_hint': 'Click Run to execute your code.',
            'help': 'See basic syntax or getting started.',
            'shortcut_run': 'Ctrl+Enter to run',
            'wasm_hint': 'Instant in-browser execution — no server load for simple programs.',
        },
        'examples_page': {
            'title': 'AFRILANG Examples',
            'label': 'Gallery',
            'h1': 'Official examples',
            'lead': 'Programs from the examples/ directory — open them in the playground in one click.',
            'search': 'Search examples…',
            'filter': 'Filter',
            'empty': 'No examples — run python manage.py sync_examples',
            'try_btn': 'Try it',
        },
        'stdlib_page': {
            'title': 'Standard library',
            'label': 'Stdlib',
            'h1': 'Stdlib browser',
            'lead': 'Browse all AFRILANG standard library modules.',
            'search': 'Search modules…',
            'filter': 'Filter',
            'empty': 'No modules — run python manage.py sync_stdlib',
            'count_label': 'modules',
            'exports': 'Functions',
            'try_playground': 'Playground',
        },
        'releases_page': {
            'title': 'AFRILANG Releases',
            'label': 'Changelog',
            'h1': 'Release history',
            'lead': 'Version notes and compiler/stdlib updates.',
            'empty': 'No releases — run python manage.py sync_releases',
        },
        'docs_search_page': {
            'title': 'Documentation search',
            'h1': 'Search documentation',
            'search': 'Keyword…',
            'filter': 'Search',
            'hint': 'Enter at least 2 characters to search.',
            'min_chars': 'Enter at least 2 characters.',
            'results_label': 'result(s)',
            'empty': 'No results for this query.',
        },
    },
}


def get_ui(lang):
    code = (lang or 'fr')[:2]
    return UI.get(code, UI['fr'])

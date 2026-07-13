"""Pages documentation méthodique (suite) — avec explications littérales."""

from .docs_pages import _page, callout, code, h2, p, table, ul


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
        "Comprendre la différence entre une erreur métier attendue et une exception, "
        "puis choisir le bon outil.",
        "Understand expected domain errors vs exceptions, then pick the right tool.",
        [
            callout(
                "<strong>En une phrase</strong> — Result = « ça peut échouer normalement ». "
                "Exception = « quelque chose d’anormal s’est produit »."
            ),
            h2("1. Le problème à résoudre"),
            p(
                "Dans un programme réel, beaucoup d’opérations peuvent échouer : fichier absent, "
                "division par zéro, texte non numérique, serveur injoignable. "
                "Si on ignore ces cas, le programme plante ou produit des résultats faux. "
                "AFRILANG offre deux styles complémentaires pour les traiter."
            ),
            h2("2. try / catch / raise — l’exception"),
            p(
                "Une <strong>exception</strong> interrompt le flux normal. "
                "<code>raise</code> signale un problème. "
                "Le premier <code>catch</code> qui entoure cet appel récupère le message. "
                "C’est utile pour des erreurs rares ou pour remonter un échec à travers "
                "plusieurs couches sans propager un Result à chaque fonction."
            ),
            p(
                "Dans l’exemple ci-dessous, le bloc <code>try</code> tente une opération ; "
                "si <code>raise</code> est exécuté, le contrôle saute directement dans "
                "<code>catch</code>, et la variable <code>e</code> contient le message d’erreur."
            ),
            code(fr_try),
            h2("3. Result — l’échec prévu dans le type"),
            p(
                "Quand l’échec fait partie du contrat d’une fonction (parse, division, recherche), "
                "préférez un type <code>T or error</code>. "
                "La fonction <em>retourne</em> soit une valeur, soit une erreur : "
                "l’appelant est obligé d’y penser. C’est plus explicite qu’une exception "
                "« surprise » plus bas dans la pile."
            ),
            p(
                "Lecture du résultat : testez <code>is error</code>. "
                "S’il y a erreur, lisez <code>.message</code>. "
                "Sinon, lisez <code>.value</code>. "
                "Il n’existe pas de mot-clé <code>is ok</code> : on nie l’erreur "
                "(<code>(r is error) is equal to false</code>) ou on utilise un <code>if / else</code>."
            ),
            code(fr_result),
            h2("4. Comment choisir ? (méthode)"),
            p(
                "Demandez-vous : « Est-ce qu’un utilisateur ou un fichier mal formé peut "
                "provoquer cet échec dans un usage normal ? » "
                "Si oui → Result. "
                "Si non (invariant cassé, bug interne) → exception ou assert de test."
            ),
            table(
                ["Situation", "Mécanisme", "Pourquoi"],
                [
                    [
                        "Erreur attendue (parse, I/O métier)",
                        "<code>T or error</code>",
                        "Fait partie de l’API ; l’appelant doit réagir",
                    ],
                    [
                        "Bug / état impossible",
                        "<code>raise</code>",
                        "Ne devrait jamais arriver en usage correct",
                    ],
                    [
                        "Vérification dans un test",
                        "<code>assert …</code>",
                        "Échoue la suite si la propriété est fausse",
                    ],
                ],
            ),
            h2("5. Pièges fréquents"),
            ul(
                [
                    "Oublier de tester <code>is error</code> avant d’accéder à <code>.value</code>",
                    "Déclarer une fonction Result <em>à l’intérieur</em> d’un bloc <code>test</code> (interdit / mal parsé)",
                    "Confondre « pas de valeur » (optionnel <code>nothing</code>) et « erreur » (Result)",
                ]
            ),
            callout(
                "Pour pratiquer : ouvrez <code>examples/result.afr</code> et "
                "<code>examples/exceptions.afr</code>, puis relancez-les avec "
                "<code>afrilang run</code>."
            ),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — Result = “failure is normal”. "
                "Exception = “something abnormal happened”."
            ),
            h2("1. The problem"),
            p(
                "Real programs fail often: missing files, division by zero, bad input. "
                "AFRILANG gives two complementary styles to handle that."
            ),
            h2("2. try / catch / raise — exceptions"),
            p(
                "An <strong>exception</strong> interrupts normal flow. "
                "<code>raise</code> signals a problem; the nearest <code>catch</code> receives it. "
                "Useful for rare failures or bubbling an error without threading Result everywhere."
            ),
            p(
                "Below, if <code>raise</code> runs, control jumps to <code>catch</code> "
                "and <code>e</code> holds the message."
            ),
            code(fr_try),
            h2("3. Result — expected failure in the type"),
            p(
                "When failure is part of a function’s contract, prefer <code>T or error</code>. "
                "The function <em>returns</em> either a value or an error, so callers must handle it."
            ),
            p(
                "Check <code>is error</code>. On error read <code>.message</code>; otherwise "
                "<code>.value</code>. There is no <code>is ok</code> keyword."
            ),
            code(en_result),
            h2("4. How to choose (method)"),
            p(
                "Ask: “Can a normal user or bad file cause this in regular use?” "
                "Yes → Result. No (broken invariant) → exception / test assert."
            ),
            table(
                ["Situation", "Mechanism", "Why"],
                [
                    ["Expected failure", "<code>T or error</code>", "Part of the API"],
                    ["Bug / impossible state", "<code>raise</code>", "Should never happen"],
                    ["Test property", "<code>assert …</code>", "Fails the suite if false"],
                ],
            ),
            h2("5. Common pitfalls"),
            ul(
                [
                    "Reading <code>.value</code> before checking <code>is error</code>",
                    "Declaring Result helpers inside a <code>test</code> block",
                    "Confusing optional <code>nothing</code> with Result errors",
                ]
            ),
            callout("Practice with <code>examples/result.afr</code> and <code>examples/exceptions.afr</code>."),
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
        "Pourquoi découper le code, ce que font import/use/export, et comment lire un chemin.",
        "Why split code, what import/use/export do, and how to read a path.",
        [
            callout(
                "<strong>En une phrase</strong> — Un module est une boîte nommée : "
                "ce qui est <code>export</code> sort de la boîte ; le reste reste privé."
            ),
            h2("1. Pourquoi des modules ?"),
            p(
                "Sans modules, tout le code vit dans un seul fichier : difficile à relire, "
                "à tester, à partager. Un module regroupe des fonctions (et parfois classes) "
                "autour d’un thème — math, UI, parsing — et décide ce qui est public."
            ),
            p(
                "AFRILANG distingue clairement <strong>visibilité</strong> "
                "(export vs privé) et <strong>chargement</strong> "
                "(<code>import</code> d’un chemin, puis <code>use</code> pour amener les symboles)."
            ),
            h2("2. Déclarer : public vs privé"),
            p(
                "Dans l’exemple, <code>square</code> est exportée : d’autres fichiers peuvent "
                "l’appeler après import. <code>helper</code> n’est pas exportée : "
                "elle n’existe que pour l’implémentation interne du module. "
                "C’est ainsi que l’on cache les détails et que l’on stabilise une petite API."
            ),
            code(mod),
            h2("3. Importer : deux gestes"),
            p(
                "<code>import \"…\"</code> dit au compilateur <em>où</em> trouver le module "
                "(fichier ou stdlib/paquet). "
                "<code>use nom</code> dit <em>quels symboles</em> entrer dans la portée courante. "
                "Sans <code>use</code>, vous n’avez en général pas accès direct à <code>trim</code> "
                "même après import — d’où les deux lignes."
            ),
            code(imp),
            h2("4. Lire un chemin d’import"),
            p(
                "Le préfixe du chemin indique la provenance. "
                "Ce n’est pas qu’une convention de dossier : le compilateur résout "
                "<code>std/</code> via le registre stdlib (et <code>AFRILANG_HOME</code>), "
                "et <code>pkg/</code> via les paquets installés / vendor."
            ),
            table(
                ["Préfixe", "Signification", "À retenir"],
                [
                    ["<code>std/…</code>", "Bibliothèque standard", "Préférer le <strong>core</strong>"],
                    ["<code>std/m/…</code>", "Catalogue medium", "Souvent expérimental"],
                    ["<code>std/c/…</code>", "Catalogue complex / ultra", "Lourd ; tester en natif"],
                    ["<code>pkg/name/…</code>", "Paquet installé", "Après <code>pkg install</code>"],
                    ["relatif", "Fichier du projet", "Pour vos propres modules"],
                ],
            ),
            h2("5. Bonnes pratiques"),
            ul(
                [
                    "Exporter peu : une petite surface API est plus facile à faire évoluer",
                    "Un module = une responsabilité (évitez le « fourre-tout »)",
                    "Documenter les imports dans le README du paquet",
                ]
            ),
            callout("Exemples concrets : <code>modules.afr</code>, <code>pkg_demo.afr</code>."),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — A module is a named box: "
                "<code>export</code> leaves the box; everything else stays private."
            ),
            h2("1. Why modules?"),
            p(
                "Without modules, everything lives in one file. A module groups related "
                "functions and decides what is public."
            ),
            p(
                "AFRILANG separates <strong>visibility</strong> (export vs private) from "
                "<strong>loading</strong> (<code>import</code> a path, then <code>use</code>)."
            ),
            h2("2. Declare: public vs private"),
            p(
                "Below, <code>square</code> is exported; <code>helper</code> is internal only. "
                "That is how you hide details and keep a small stable API."
            ),
            code(mod),
            h2("3. Import: two steps"),
            p(
                "<code>import</code> tells the compiler <em>where</em> the module is. "
                "<code>use</code> brings exported symbols into scope."
            ),
            code(imp),
            h2("4. Reading an import path"),
            p(
                "The path prefix is the origin: <code>std/</code> via the stdlib registry, "
                "<code>pkg/</code> via installed packages."
            ),
            table(
                ["Prefix", "Meaning", "Remember"],
                [
                    ["<code>std/…</code>", "Standard library", "Prefer <strong>core</strong>"],
                    ["<code>std/m/…</code>", "Medium catalog", "Often experimental"],
                    ["<code>std/c/…</code>", "Complex / ultra", "Heavy; test native"],
                    ["<code>pkg/name/…</code>", "Installed package", "After <code>pkg install</code>"],
                    ["relative", "Project file", "Your own modules"],
                ],
            ),
            h2("5. Best practices"),
            ul(
                [
                    "Export little: a small API evolves more safely",
                    "One module = one responsibility",
                    "Document imports in the package README",
                ]
            ),
            callout("Concrete examples: <code>modules.afr</code>, <code>pkg_demo.afr</code>."),
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
        "Comprendre ce qu’est une coroutine, ce que fait await, et ce qui marche hors du natif.",
        "Understand coroutines, what await does, and what works outside native.",
        [
            callout(
                "<strong>En une phrase</strong> — <code>async</code> dit « cette fonction peut "
                "patienter » ; <code>await</code> dit « patiente ici sans bloquer tout le programme »."
            ),
            h2("1. Le problème"),
            p(
                "Attendre une temporisation, une réponse réseau ou une I/O peut prendre du temps. "
                "Si le programme « dort » de façon bloquante, plus rien d’autre ne tourne "
                "(interface figée, autres tâches en attente). "
                "Les coroutines permettent de suspendre une fonction et de reprendre plus tard."
            ),
            h2("2. async function"),
            p(
                "Marquer une fonction <code>async</code> indique qu’elle peut contenir des "
                "<code>await</code>. Sous le capot, AFRILANG s’appuie sur des coroutines C++20. "
                "Il faut donc une toolchain C++20 pour ces programmes."
            ),
            p(
                "Dans l’exemple, <code>delayedValue</code> attend <code>ms</code> millisecondes "
                "via <code>sleep</code>, puis renvoie 42. Pendant l’attente, d’autres coroutines "
                "pourraient progresser (selon le runtime)."
            ),
            code(sample),
            h2("3. Règles à retenir"),
            ul(
                [
                    "On ne peut <code>await</code> que dans un contexte <code>async</code>",
                    "Le résultat peut être un Result (<code>T or error</code>) : gérez l’erreur",
                    "Commencez simple (sleep) avant l’I/O réseau async",
                ]
            ),
            h2("4. Limites importantes"),
            p(
                "Tout n’est pas portable. Les fenêtres SDL, les threads POSIX et beaucoup "
                "d’I/O synchrones restent <strong>natifs</strong>. "
                "En WASM, un sous-ensemble (dont sleep Emscripten) fonctionne ; "
                "les sockets sync et l’UI native non."
            ),
            callout(
                'Détail des cibles : <a href="/docs/wasm/">WASM &amp; JS</a>. '
                "Demos : <code>async_demo.afr</code>, <code>async_full.afr</code>."
            ),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — <code>async</code> means “this function may wait”; "
                "<code>await</code> means “wait here without freezing everything”."
            ),
            h2("1. The problem"),
            p(
                "Sleeping or waiting for I/O can take time. Blocking sleep freezes the program. "
                "Coroutines suspend and resume later."
            ),
            h2("2. async function"),
            p(
                "An <code>async</code> function may contain <code>await</code>. "
                "AFRILANG uses C++20 coroutines, so you need a C++20 toolchain."
            ),
            p(
                "Below, <code>delayedValue</code> waits <code>ms</code> milliseconds via "
                "<code>sleep</code>, then returns 42."
            ),
            code(sample),
            h2("3. Rules"),
            ul(
                [
                    "You can only <code>await</code> inside <code>async</code>",
                    "Results may be <code>T or error</code>: handle errors",
                    "Start with sleep before async networking",
                ]
            ),
            h2("4. Important limits"),
            p(
                "SDL windows, POSIX threads, and much sync I/O stay <strong>native</strong>. "
                "WASM supports a subset (including Emscripten sleep)."
            ),
            callout(
                'Target details: <a href="/docs/wasm/">WASM &amp; JS</a>. '
                "Demos: <code>async_demo.afr</code>, <code>async_full.afr</code>."
            ),
        ],
    )


def gui_page():
    return _page(
        "gui",
        "Interfaces graphiques",
        "Graphical UI",
        "Ce qu’est une boucle d’événements, pourquoi SDL2, et pourquoi ce n’est pas le navigateur.",
        "What an event loop is, why SDL2, and why this is not the browser.",
        [
            callout(
                "<strong>En une phrase</strong> — Une GUI native écoute en boucle clavier/souris/"
                "fermeture, redessine, jusqu’à ce que l’utilisateur quitte."
            ),
            h2("1. Modèle mental"),
            p(
                "Contrairement à une page web où le navigateur gère déjà les événements, "
                "un programme SDL2 <strong>possède</strong> la fenêtre. "
                "Votre code doit : ouvrir la fenêtre, entrer dans une boucle, "
                "traiter chaque événement, mettre à jour l’affichage, puis fermer proprement."
            ),
            p(
                "Si la boucle s’arrête, la fenêtre disparaît. "
                "Si vous ne traitez pas l’événement « fermer », l’utilisateur a l’impression "
                "que l’appli est bloquée."
            ),
            h2("2. Prérequis système"),
            p(
                "Il faut les bibliothèques de développement SDL2 (et souvent SDL_ttf pour le texte). "
                "Sans elles, la compilation C++ échoue avec un message du type "
                "<code>SDL.h: No such file</code>."
            ),
            code("sudo apt-get install -y libsdl2-dev libsdl2-ttf-dev", "Terminal"),
            h2("3. Dans AFRILANG"),
            p(
                "Le module <code>std/ui</code> encapsule ces opérations. "
                "Importez-le, puis suivez la méthode : créer → boucler → dessiner → quitter. "
                "Les jeux 2D/3D ajoutent encore OpenGL / logique de scène "
                "(modules <code>game2d</code> / <code>game3d</code>)."
            ),
            code('import "std/ui"\nuse ui'),
            h2("4. Pourquoi pas dans le playground web ?"),
            p(
                "Le playground navigateur et la cible wasm32 n’offrent pas une fenêtre SDL native. "
                "Pour apprendre la GUI, travaillez en <strong>natif</strong>. "
                "Pour le web, restez sur le sous-ensemble JS / wasm sans UI."
            ),
            callout(
                'Voir <a href="/docs/wasm/">WASM</a> et les demos <code>gui_demo.afr</code>.'
            ),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — A native GUI loops on keyboard/mouse/close, "
                "redraws, until the user quits."
            ),
            h2("1. Mental model"),
            p(
                "Unlike a web page, an SDL2 program <strong>owns</strong> the window. "
                "Your code must open it, loop on events, redraw, and shut down cleanly."
            ),
            h2("2. System prerequisites"),
            p(
                "Install SDL2 development libraries or C++ compilation fails looking for headers."
            ),
            code("sudo apt-get install -y libsdl2-dev libsdl2-ttf-dev", "Terminal"),
            h2("3. In AFRILANG"),
            p(
                "<code>std/ui</code> wraps these operations. Method: create → loop → draw → quit. "
                "2D/3D games add OpenGL / scene logic."
            ),
            code('import "std/ui"\nuse ui'),
            h2("4. Why not in the web playground?"),
            p(
                "Browser playground / wasm32 have no native SDL window. "
                "Learn GUI on <strong>native</strong> builds."
            ),
            callout('See <a href="/docs/wasm/">WASM</a> and <code>gui_demo.afr</code>.'),
        ],
    )


def packages_page():
    return _page(
        "package-manager",
        "Paquets",
        "Packages",
        "Comprendre le rôle de chaque fichier, puis le cycle ajouter → installer → verrouiller → publier.",
        "Understand each file’s role, then the add → install → lock → publish cycle.",
        [
            callout(
                "<strong>En une phrase</strong> — Le <code>toml</code> exprime ce que vous "
                "<em>voulez</em> ; le <code>lock</code> fixe ce qui est <em>vraiment</em> installé."
            ),
            h2("1. Pourquoi un gestionnaire de paquets ?"),
            p(
                "Réécrire la même bibliothèque math / strings dans chaque projet est une perte "
                "de temps. Les paquets AFRILANG permettent de déclarer une dépendance, "
                "de l’installer de façon reproductible, et de la partager "
                "(registre local ou distant, modèle proche de Nimble / Shards)."
            ),
            h2("2. Les fichiers — rôles littéraux"),
            p(
                "<code>afrilang.toml</code> est la fiche d’identité du projet et la liste "
                "des dépendances avec leurs contraintes de version. "
                "<code>afrilang.lock</code> est la photo exacte des versions résolues : "
                "deux machines qui partagent le même lock installent les mêmes bits. "
                "<code>vendor/</code> contient les copies locales. "
                "<code>manifest.toml</code> décrit une <em>bibliothèque</em> publiable."
            ),
            table(
                ["Fichier", "Question à laquelle il répond"],
                [
                    ["<code>afrilang.toml</code>", "De quoi mon projet a besoin ?"],
                    ["<code>afrilang.lock</code>", "Quelles versions exactes ai-je choisi ?"],
                    ["<code>vendor/</code>", "Où est le code des deps sur le disque ?"],
                    ["<code>manifest.toml</code>", "Comment décrire ma lib pour les autres ?"],
                    ["index local / remote", "Où chercher les paquets connus ?"],
                ],
            ),
            h2("3. Cycle de travail recommandé"),
            p(
                "Créez le projet ou la lib, déclarez les deps (version, git ou path), "
                "synchronisez l’index distant si besoin, installez, écrivez du code qui "
                "<code>import</code> le paquet, testez, puis publiez quand l’API est stable."
            ),
            code(
                "afrilang init mon_app\n"
                "afrilang pkg add math\n"
                "afrilang pkg install\n"
                "afrilang test",
                "Terminal",
            ),
            h2("4. Semver en langage courant"),
            p(
                "Une version <code>1.2.3</code> dit : majeur.mineur.patch. "
                "<code>^1.2.3</code> autorise des mises à jour qui restent compatibles "
                "avec la même majeure (&lt; 2.0.0). "
                "<code>~1.2.3</code> reste plus serré (&lt; 1.3.0). "
                "En cas de conflit entre deux contraintes incompatibles sur le même nom, "
                "l’install échoue avec une erreur claire — c’est voulu."
            ),
            h2("5. install vs update"),
            p(
                "<code>pkg install</code> privilégie le lock s’il existe : reproductibilité. "
                "<code>pkg update</code> relit les plages du toml, recalcule, réécrit le lock : "
                "évolution contrôlée. Utilisez update quand vous voulez monter de version "
                "volontairement, pas à chaque build CI."
            ),
            h2("6. Publier"),
            p(
                "En local, <code>pkg publish</code> enregistre le paquet dans l’index machine. "
                "En distant, <code>--remote</code> produit une recette "
                "(<code>registry-entry.json</code>) et peut POST si un token est configuré. "
                "Sans URL git du paquet, la recette distante est incomplète."
            ),
            code(
                "export AFRILANG_PACKAGE_GIT_URL=https://github.com/vous/mon_lib\n"
                "afrilang pkg publish ./mon_lib --remote",
                "Distant",
            ),
            h2("7. Importer après install"),
            p(
                "Une fois vendored, le code s’importe comme un module projet, "
                "avec le préfixe <code>pkg/</code>. Pensez à <code>use</code> ensuite."
            ),
            code('import "pkg/math/math.afr"\nuse math'),
            callout(
                "Référence longue dans le dépôt : <code>docs/PKG.md</code>. "
                "Exemple d’index : <code>packages/remote-index.example.json</code>."
            ),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — The toml is what you <em>want</em>; "
                "the lock is what is <em>actually</em> installed."
            ),
            h2("1. Why a package manager?"),
            p(
                "Packages let you declare dependencies, install them reproducibly, "
                "and share them (local or remote registry — Nimble/Shards-like)."
            ),
            h2("2. Files — literal roles"),
            p(
                "<code>afrilang.toml</code> is identity + dependency ranges. "
                "<code>afrilang.lock</code> is the exact resolved snapshot. "
                "<code>vendor/</code> holds local copies. "
                "<code>manifest.toml</code> describes a publishable library."
            ),
            table(
                ["File", "Question it answers"],
                [
                    ["<code>afrilang.toml</code>", "What does my project need?"],
                    ["<code>afrilang.lock</code>", "Which exact versions did I pick?"],
                    ["<code>vendor/</code>", "Where is dependency code on disk?"],
                    ["<code>manifest.toml</code>", "How do I describe my lib?"],
                    ["local / remote index", "Where are known packages listed?"],
                ],
            ),
            h2("3. Recommended workflow"),
            p(
                "Create → declare deps → sync remote index if needed → install → "
                "import in code → test → publish when API is stable."
            ),
            code(
                "afrilang init my_app\n"
                "afrilang pkg add math\n"
                "afrilang pkg install\n"
                "afrilang test",
                "Terminal",
            ),
            h2("4. Semver in plain language"),
            p(
                "<code>^1.2.3</code> allows compatible updates within major 1. "
                "<code>~1.2.3</code> is tighter. Incompatible constraints on the same name fail loudly."
            ),
            h2("5. install vs update"),
            p(
                "<code>install</code> prefers the lock (reproducibility). "
                "<code>update</code> re-resolves from toml ranges (intentional upgrades)."
            ),
            h2("6. Publish"),
            p(
                "Local publish registers on the machine. "
                "<code>--remote</code> writes a recipe and may POST with a token."
            ),
            h2("7. Import after install"),
            code('import "pkg/math/math.afr"\nuse math'),
            callout("Longer reference: <code>docs/PKG.md</code>."),
        ],
    )

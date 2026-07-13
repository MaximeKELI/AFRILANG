"""Enrichissement prose : explications littérales FR/EN autour du code (pages langage)."""

from .docs_pages import callout, code, h2, p, table, ul


def enrich_language_pages_with_prose(pages):
    """Remplace les pages langage par des versions avec prose + exemples."""
    pages["syntax"] = _syntax_page()
    pages["types"] = _types_page()
    pages["oop"] = _oop_page()
    pages["functional"] = _functional_page()
    pages["pattern-matching"] = _pattern_page()


def _page(slug, title_fr, title_en, lead_fr, lead_en, fr_blocks, en_blocks):
    from .docs_pages import _page as make

    return make(slug, title_fr, title_en, lead_fr, lead_en, fr_blocks, en_blocks)


def _syntax_page():
    return _page(
        "syntax",
        "Syntaxe de base",
        "Basic syntax",
        "Lire et écrire du AFRILANG : variables, E/S, conditions, boucles, listes, maps, fonctions.",
        "Read and write AFRILANG: variables, I/O, conditionals, loops, lists, maps, functions.",
        [
            callout(
                "<strong>En une phrase</strong> — La syntaxe se lit comme une phrase : "
                "chaque bloc se ferme par <code>end</code>, les comparaisons sont en mots."
            ),
            h2("1. Affichage et entrée"),
            p(
                "Pour afficher du texte à l’écran, utilisez <code>say</code> (ou <code>dire</code>). "
                "Pour poser une question à l’utilisateur et stocker la réponse, "
                "<code>ask … into …</code>. "
                "Les chaînes entre guillemets peuvent contenir une interpolation "
                "<code>{nom}</code> : la valeur de la variable est insérée dans le texte."
            ),
            code('say "Hello"\nask "Name?" into name\nsay "Hi, {name}!"'),
            h2("2. Variables"),
            p(
                "<code>create</code> déclare une nouvelle variable. "
                "Vous pouvez laisser le type être déduit (<code>create x = 42</code>) "
                "ou l’écrire (<code>create name text = \"…\"</code>). "
                "<code>create const</code> crée une constante : on ne la modifie plus ensuite. "
                "Pour changer une variable déjà créée, utilisez <code>set</code> "
                "(pas un second <code>create</code> du même nom)."
            ),
            code(
                "create x = 42\n"
                'create name text = "AFRILANG"\n'
                "create const MAX = 100\n"
                "set x = x + 1"
            ),
            h2("3. Conditions"),
            p(
                "Un <code>if</code> teste une condition écrite en mots naturels "
                "(<code>is greater than</code>, <code>is equal to</code>, …). "
                "Le mot <code>then</code> ouvre le bloc « vrai ». "
                "Optionnellement, <code>else</code> ouvre le bloc « sinon ». "
                "Tout se termine par <code>end</code>. "
                "Sans <code>end</code>, le parseur ne sait pas où s’arrête la branche."
            ),
            code(
                "if age is greater than 18 then\n"
                '    say "Adult"\n'
                "else\n"
                '    say "Minor"\n'
                "end"
            ),
            h2("4. Boucles"),
            p(
                "Trois formes courantes : "
                "<code>repeat N times</code> (répéter un nombre fixe), "
                "<code>while … do</code> (tant qu’une condition est vraie), "
                "<code>for each … in … do</code> (parcourir une liste). "
                "Comme toujours, fermez avec <code>end</code>. "
                "Pour une plage numérique, voir aussi <code>for i from … to …</code> plus bas."
            ),
            code(
                "repeat 5 times\n"
                '    say "tick"\n'
                "end\n\n"
                "while count is less than 10 do\n"
                "    set count = count + 1\n"
                "end\n\n"
                "for each item in nums do\n"
                "    say item\n"
                "end"
            ),
            h2("5. Listes"),
            p(
                "Une liste se crée avec <code>list of …</code>. "
                "L’accès se fait par <code>at</code> (index à partir de 0). "
                "<code>add … to …</code> ajoute un élément. "
                "Pour transformer tous les éléments, préférez "
                "<code>map each … with …</code> plutôt qu’une boucle manuelle "
                "(voir aussi la page Lambdas)."
            ),
            code(
                "create nums = list of 1, 2, 3\n"
                "say nums at 0\n"
                "add 4 to nums\n"
                "create doubled = map each n in nums with n * 2"
            ),
            h2("6. Fonctions"),
            p(
                "Une fonction a un nom, des paramètres typés, et souvent un type de retour "
                "(<code>returns …</code>). Le corps calcule puis <code>return</code> une valeur. "
                "Appelez-la comme en math : <code>add(2, 3)</code>. "
                "Les fonctions utilitaires pour les tests doivent rester "
                "<strong>hors</strong> des blocs <code>test</code>."
            ),
            code(
                "function add(a number, b number) returns number\n"
                "    return a + b\n"
                "end\n\n"
                "say add(2, 3)"
            ),
            h2("7. Maps (dictionnaires)"),
            p(
                "Une map associe des clés à des valeurs. "
                "Créez-la avec <code>map of … to …</code>, lisez avec <code>at</code>, "
                "écrivez avec <code>set … at … = …</code>. "
                "Vous pouvez parcourir paires clé/valeur avec <code>for each key, value in …</code>."
            ),
            code(
                'create m = map of "a" to 1, "b" to 2\n'
                'say m at "a"\n'
                'set m at "c" = 3\n'
                "for each key, value in m do\n"
                "    say key\n"
                "    say value\n"
                "end"
            ),
            h2("8. Boucle numérique for"),
            p(
                "<code>for i from A to B do</code> fait varier <code>i</code> de A à B inclus. "
                "Ajoutez <code>step</code> pour avancer de plus d’un "
                "(par ex. seulement les pairs)."
            ),
            code(
                "for i from 1 to 10 do\n"
                "    say i\n"
                "end\n\n"
                "for n from 0 to 10 step 2 do\n"
                "    say n\n"
                "end"
            ),
            h2("9. Interpolation"),
            p(
                "Dans une chaîne, <code>{variable}</code> est remplacé par la valeur "
                "au moment de l’affichage. Utile pour les messages sans concaténer à la main."
            ),
            code('create name = "World"\nsay "Hello {name}!"'),
            h2("10. Alias français"),
            p(
                "Les mêmes idées existent en français. "
                "Restez cohérent dans un fichier (tout EN ou tout FR) pour la lisibilité."
            ),
            table(
                ["Anglais", "Français"],
                [
                    ["<code>say</code>", "<code>dire</code>"],
                    ["<code>ask</code>", "<code>demander</code>"],
                    ["<code>create</code>", "<code>creer</code>"],
                    ["<code>set</code>", "<code>definir</code>"],
                    ["<code>if/then/else/end</code>", "<code>si/alors/sinon/fin</code>"],
                    ["<code>while/do</code>", "<code>tantque/faire</code>"],
                    ["<code>repeat/times</code>", "<code>repeter/fois</code>"],
                    ["<code>function</code>", "<code>fonction</code>"],
                    ["<code>number/text/bool</code>", "<code>nombre/texte/booleen</code>"],
                ],
            ),
            callout(
                '<strong>Suite :</strong> <a href="/docs/types/">Système de types →</a>'
            ),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — Syntax reads like a sentence: "
                "every block ends with <code>end</code>; comparisons use words."
            ),
            h2("1. Output and input"),
            p(
                "Use <code>say</code> to print. Use <code>ask … into …</code> to prompt "
                "and store the answer. Strings may interpolate <code>{name}</code>."
            ),
            code('say "Hello"\nask "Name?" into name\nsay "Hi, {name}!"'),
            h2("2. Variables"),
            p(
                "<code>create</code> declares a variable (type inferred or explicit). "
                "<code>create const</code> makes a constant. "
                "Change an existing variable with <code>set</code>."
            ),
            code(
                "create x = 42\n"
                'create name text = "AFRILANG"\n'
                "create const MAX = 100\n"
                "set x = x + 1"
            ),
            h2("3. Conditionals"),
            p(
                "<code>if</code> uses natural comparisons (<code>is greater than</code>, …). "
                "<code>then</code> / optional <code>else</code> / always <code>end</code>."
            ),
            code(
                "if age is greater than 18 then\n"
                '    say "Adult"\n'
                "else\n"
                '    say "Minor"\n'
                "end"
            ),
            h2("4. Loops"),
            p(
                "<code>repeat N times</code>, <code>while … do</code>, "
                "<code>for each … in … do</code> — all closed with <code>end</code>."
            ),
            code(
                "repeat 5 times\n"
                '    say "tick"\n'
                "end\n\n"
                "while count is less than 10 do\n"
                "    set count = count + 1\n"
                "end\n\n"
                "for each item in nums do\n"
                "    say item\n"
                "end"
            ),
            h2("5. Lists"),
            p(
                "Build with <code>list of</code>, index with <code>at</code>, "
                "append with <code>add … to …</code>, transform with <code>map each</code>."
            ),
            code(
                "create nums = list of 1, 2, 3\n"
                "say nums at 0\n"
                "add 4 to nums\n"
                "create doubled = map each n in nums with n * 2"
            ),
            h2("6. Functions"),
            p(
                "Typed parameters, optional <code>returns</code>, body ends with "
                "<code>return</code>. Keep test helpers <strong>outside</strong> "
                "<code>test</code> blocks."
            ),
            code(
                "function add(a number, b number) returns number\n"
                "    return a + b\n"
                "end\n\n"
                "say add(2, 3)"
            ),
            h2("7. Maps"),
            p(
                "Key/value maps via <code>map of … to …</code>, "
                "read with <code>at</code>, write with <code>set … at …</code>."
            ),
            code(
                'create m = map of "a" to 1, "b" to 2\n'
                'say m at "a"\n'
                'set m at "c" = 3\n'
                "for each key, value in m do\n"
                "    say key\n"
                "    say value\n"
                "end"
            ),
            h2("8. Numeric for"),
            p(
                "<code>for i from A to B</code> inclusive; optional <code>step</code>."
            ),
            code(
                "for i from 1 to 10 do\n"
                "    say i\n"
                "end\n\n"
                "for n from 0 to 10 step 2 do\n"
                "    say n\n"
                "end"
            ),
            h2("9. Interpolation"),
            p("Inside a string, <code>{variable}</code> is replaced at print time."),
            code('create name = "World"\nsay "Hello {name}!"'),
            h2("10. French aliases"),
            p("Same ideas exist in French — stay consistent inside one file."),
            table(
                ["English", "French"],
                [
                    ["<code>say</code>", "<code>dire</code>"],
                    ["<code>ask</code>", "<code>demander</code>"],
                    ["<code>create</code>", "<code>creer</code>"],
                    ["<code>set</code>", "<code>definir</code>"],
                    ["<code>if/then/else/end</code>", "<code>si/alors/sinon/fin</code>"],
                    ["<code>while/do</code>", "<code>tantque/faire</code>"],
                    ["<code>repeat/times</code>", "<code>repeter/fois</code>"],
                    ["<code>function</code>", "<code>fonction</code>"],
                    ["<code>number/text/bool</code>", "<code>nombre/texte/booleen</code>"],
                ],
            ),
            callout('<strong>Next:</strong> <a href="/docs/types/">Type system →</a>'),
        ],
    )


def _types_page():
    return _page(
        "types",
        "Système de types",
        "Type system",
        "Pourquoi des types, primitives, collections, optionnels, Result, génériques.",
        "Why types, primitives, collections, optionals, Result, generics.",
        [
            callout(
                "<strong>En une phrase</strong> — Le compilateur connaît le type de chaque "
                "valeur avant l’exécution : moins d’erreurs tardives, du C++ efficace."
            ),
            h2("1. Pourquoi des types explicites ?"),
            p(
                "AFRILANG est <strong>statiquement typé</strong>. "
                "Passer un texte là où un nombre est attendu est une erreur de compilation, "
                "pas une surprise à l’exécution. "
                "Sous le capot, les types AFRILANG se traduisent en types C++ familiers."
            ),
            h2("2. Types primitifs"),
            p(
                "<code>number</code> est un flottant (comme <code>double</code>). "
                "Pour débuter, c’est le seul type numérique dont vous avez besoin. "
                "<code>text</code> est une chaîne UTF-8. "
                "<code>bool</code> vaut vrai ou faux."
            ),
            table(
                ["Type", "Équivalent C++", "Usage typique"],
                [
                    ["<code>number</code>", "<code>double</code>", "Calculs, compteurs"],
                    ["<code>text</code>", "<code>std::string</code>", "Messages, noms"],
                    ["<code>bool</code>", "<code>bool</code>", "Conditions"],
                    ["<code>list of T</code>", "<code>std::vector&lt;T&gt;</code>", "Suites ordonnées"],
                    ["<code>map K to V</code>", "<code>std::unordered_map</code>", "Dictionnaires"],
                ],
            ),
            h2("3. Optionnels — « peut-être une valeur »"),
            p(
                "Un type <code>T?</code> signifie : soit une valeur de type T, soit aucune. "
                "On initialise avec <code>nothing</code>. "
                "On teste avec <code>is defined</code> avant d’utiliser la valeur. "
                "Ce n’est <em>pas</em> la même chose qu’une chaîne vide : "
                "vide = texte présent sans caractères ; <code>nothing</code> = absence totale. "
                "N’utilisez pas <code>none</code> ni <code>is some</code> — ce n’est pas la syntaxe AFRILANG."
            ),
            code(
                "create name text? = nothing\n"
                "if name is defined then\n"
                "    say name\n"
                "end"
            ),
            h2("4. Result — « succès ou erreur attendue »"),
            p(
                "Quand une fonction peut échouer de façon normale (parse, division), "
                "déclarez <code>returns T or error</code>. "
                "L’appelant teste <code>is error</code>, puis lit <code>.message</code> "
                "ou <code>.value</code>. Il n’y a pas de mot-clé <code>is ok</code>."
            ),
            code(
                "function parse(s text) returns number or error\n"
                '    return error "invalid"\n'
                "end"
            ),
            h2("5. Génériques"),
            p(
                "Un paramètre de type <code>&lt;T&gt;</code> dit : « cette fonction marche "
                "pour n’importe quel type T ». "
                "Utile pour des utilitaires (identité, boîtes, listes typées) "
                "sans dupliquer le code pour chaque type."
            ),
            code(
                "function identity<T>(x T) returns T\n"
                "    return x\n"
                "end\n"
                "say identity(42)"
            ),
            callout(
                'Pour les erreurs « surprises », voir aussi '
                '<a href="/docs/exceptions/">Exceptions</a>.'
            ),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — The compiler knows each value’s type "
                "before runtime: fewer late bugs, efficient C++."
            ),
            h2("1. Why explicit types?"),
            p(
                "AFRILANG is <strong>statically typed</strong>. "
                "Wrong argument types fail at compile time. "
                "Types map to familiar C++ equivalents."
            ),
            h2("2. Primitive types"),
            p(
                "<code>number</code> is a float (<code>double</code>). "
                "<code>text</code> is UTF-8. <code>bool</code> is true/false."
            ),
            table(
                ["Type", "C++", "Typical use"],
                [
                    ["<code>number</code>", "<code>double</code>", "Math, counters"],
                    ["<code>text</code>", "<code>std::string</code>", "Messages, names"],
                    ["<code>bool</code>", "<code>bool</code>", "Conditions"],
                    ["<code>list of T</code>", "<code>std::vector&lt;T&gt;</code>", "Ordered sequences"],
                    ["<code>map K to V</code>", "<code>std::unordered_map</code>", "Dictionaries"],
                ],
            ),
            h2("3. Optionals — “maybe a value”"),
            p(
                "<code>T?</code> is either a T or none. Use <code>nothing</code> and "
                "<code>is defined</code>. Not the same as an empty string. "
                "Do not use <code>none</code> / <code>is some</code>."
            ),
            code(
                "create name text? = nothing\n"
                "if name is defined then\n"
                "    say name\n"
                "end"
            ),
            h2("4. Result — “success or expected error”"),
            p(
                "Declare <code>returns T or error</code>. Callers check <code>is error</code>, "
                "then read <code>.message</code> or <code>.value</code>. No <code>is ok</code>."
            ),
            code(
                "function parse(s text) returns number or error\n"
                '    return error "invalid"\n'
                "end"
            ),
            h2("5. Generics"),
            p(
                "A type parameter <code>&lt;T&gt;</code> means the function works for any T."
            ),
            code(
                "function identity<T>(x T) returns T\n"
                "    return x\n"
                "end\n"
                "say identity(42)"
            ),
            callout(
                'For unexpected failures, see also '
                '<a href="/docs/exceptions/">Exceptions</a>.'
            ),
        ],
    )


def _oop_page():
    return _page(
        "oop",
        "Programmation orientée objet",
        "Object-oriented programming",
        "Classes, constructeurs, héritage, interfaces, records — avec le pourquoi.",
        "Classes, constructors, inheritance, interfaces, records — with the why.",
        [
            callout(
                "<strong>En une phrase</strong> — Une classe regroupe données (champs) et "
                "comportements (méthodes) ; on crée des instances avec <code>new</code>."
            ),
            h2("1. Classes et constructeur"),
            p(
                "Déclarez une <code>class</code>, des <code>field</code> (souvent "
                "<code>public</code> ou <code>private</code>), et des <code>function</code> "
                "méthodes. Le constructeur s’appelle <code>init</code> : "
                "il s’exécute quand vous faites <code>new Classe(…)</code>. "
                "À l’intérieur, <code>this</code> désigne l’instance courante."
            ),
            p(
                "Dans l’exemple, chaque <code>Dog</code> a un <code>name</code>. "
                "À la création, <code>init</code> range le nom. "
                "<code>speak</code> utilise ce nom pour afficher un message."
            ),
            code(
                "class Dog\n"
                "    public field name text\n"
                "    function init(n text)\n"
                "        set this.name = n\n"
                "    end\n"
                "    function speak()\n"
                '        say name + " says Woof!"\n'
                "    end\n"
                "end\n"
                'create rex = new Dog("Rex")\n'
                "rex.speak()"
            ),
            h2("2. Héritage"),
            p(
                "<code>extends</code> crée une spécialisation : la classe fille réutilise "
                "ou redéfinit le comportement du parent. "
                "<code>super</code> appelle explicitement la version parente "
                "(utile pour enrichir un message ou une description)."
            ),
            code(
                "class Car extends Vehicle\n"
                "    function describe() returns text\n"
                "        return super.describe() + model\n"
                "    end\n"
                "end"
            ),
            h2("3. Interfaces"),
            p(
                "Une <code>interface</code> décrit un contrat (« qui sait parler ») "
                "sans fournir le corps des méthodes. "
                "Une classe <code>implements</code> l’interface et doit fournir "
                "chaque méthode. Cela permet de traiter différents objets "
                "de façon uniforme tant qu’ils respectent le contrat."
            ),
            code(
                "interface Speakable\n"
                "    function speak()\n"
                "end\n"
                "class Robot implements Speakable\n"
                "    function speak()\n"
                '        say "Beep"\n'
                "    end\n"
                "end"
            ),
            h2("4. Classes génériques et records"),
            p(
                "Comme pour les fonctions, une classe peut être paramétrée "
                "(<code>Box&lt;T&gt;</code>). "
                "Les <strong>records</strong> conviennent quand vous n’avez besoin "
                "que de champs groupés, sans hiérarchie complexe."
            ),
            code(
                "class Box<T>\n"
                "    public field value T\n"
                "end\n"
                "create b = new Box<number>(42)"
            ),
            callout(
                'Ensuite : <a href="/docs/pattern-matching/">Pattern matching</a> '
                "pour les enums et unions."
            ),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — A class groups data (fields) and "
                "behavior (methods); create instances with <code>new</code>."
            ),
            h2("1. Classes and constructor"),
            p(
                "Declare a <code>class</code>, fields, and methods. "
                "The constructor is <code>init</code>, called by <code>new</code>. "
                "Inside methods, <code>this</code> is the current instance."
            ),
            code(
                "class Dog\n"
                "    public field name text\n"
                "    function init(n text)\n"
                "        set this.name = n\n"
                "    end\n"
                "    function speak()\n"
                '        say name + " says Woof!"\n'
                "    end\n"
                "end\n"
                'create rex = new Dog("Rex")\n'
                "rex.speak()"
            ),
            h2("2. Inheritance"),
            p(
                "<code>extends</code> specializes a parent. "
                "<code>super</code> calls the parent implementation."
            ),
            code(
                "class Car extends Vehicle\n"
                "    function describe() returns text\n"
                "        return super.describe() + model\n"
                "    end\n"
                "end"
            ),
            h2("3. Interfaces"),
            p(
                "An <code>interface</code> is a contract. "
                "A class <code>implements</code> it and must provide each method."
            ),
            code(
                "interface Speakable\n"
                "    function speak()\n"
                "end\n"
                "class Robot implements Speakable\n"
                "    function speak()\n"
                '        say "Beep"\n'
                "    end\n"
                "end"
            ),
            h2("4. Generic classes and records"),
            p(
                "Classes can take type parameters. "
                "Records fit when you only need grouped fields."
            ),
            code(
                "class Box<T>\n"
                "    public field value T\n"
                "end\n"
                "create b = new Box<number>(42)"
            ),
            callout(
                'Next: <a href="/docs/pattern-matching/">Pattern matching</a>.'
            ),
        ],
    )


def _functional_page():
    return _page(
        "functional",
        "Lambdas & collections",
        "Lambdas & collections",
        "Transformer des listes avec map / filter / reduce en français naturel.",
        "Transform lists with natural map / filter / reduce.",
        [
            callout(
                "<strong>En une phrase</strong> — Au lieu d’écrire une boucle + une liste "
                "temporaire, décrivez la transformation : map, filter, reduce."
            ),
            h2("1. Le problème"),
            p(
                "Souvent on veut : « pour chaque élément, produire autre chose », "
                "« garder seulement ceux qui… », « accumuler en une seule valeur ». "
                "Les boucles manuelles marchent, mais sont verboses et faciles à rater "
                "(oubli d’ajouter, mauvaise condition). "
                "AFRILANG offre une syntaxe naturelle pour ces trois cas."
            ),
            h2("2. map — transformer chaque élément"),
            p(
                "<code>map each x in liste with expression</code> produit une "
                "<strong>nouvelle</strong> liste de même longueur. "
                "La liste d’origine n’est pas modifiée. "
                "Utile pour doubler des nombres, formater des textes, etc."
            ),
            code("create doubled = map each n in nums with n * 2"),
            h2("3. filter — garder selon une condition"),
            p(
                "<code>filter each x in liste where condition</code> ne conserve "
                "que les éléments pour lesquels la condition est vraie. "
                "La longueur du résultat est ≤ celle d’origine."
            ),
            code("create positives = filter each n in nums where n is greater than 0"),
            h2("4. reduce — agréger"),
            p(
                "Reduce part d’une valeur initiale et « plie » la liste en une seule valeur "
                "(somme, produit, concaténation…). "
                "Lisez la page exemples / specs pour la forme exacte "
                "<code>reduce … with each …</code> dans votre version."
            ),
            h2("5. Quand préférer une boucle ?"),
            p(
                "Si vous avez des effets de bord complexes (plusieurs listes, "
                "conditions croisées, I/O), une boucle <code>for each</code> reste claire. "
                "Pour une transformation pure d’une liste, préférez map/filter."
            ),
            callout(
                'Voir aussi <a href="/docs/syntax/">Syntaxe</a> (listes) et '
                "<code>examples/</code>."
            ),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — Describe the transformation "
                "(map, filter, reduce) instead of a manual loop + temp list."
            ),
            h2("1. The problem"),
            p(
                "You often want transform / keep-some / aggregate. "
                "Natural syntax reduces boilerplate and off-by-one mistakes."
            ),
            h2("2. map — transform each item"),
            p(
                "<code>map each x in list with expression</code> builds a "
                "<strong>new</strong> list of the same length; the original is unchanged."
            ),
            code("create doubled = map each n in nums with n * 2"),
            h2("3. filter — keep by condition"),
            p(
                "<code>filter each x in list where condition</code> keeps matching items only."
            ),
            code("create positives = filter each n in nums where n is greater than 0"),
            h2("4. reduce — aggregate"),
            p(
                "Reduce folds a list into one value (sum, join, …). "
                "See examples/specs for the exact <code>reduce … with each …</code> form."
            ),
            h2("5. When to prefer a loop?"),
            p(
                "Complex side effects → <code>for each</code>. "
                "Pure list transforms → map/filter."
            ),
            callout(
                'Also see <a href="/docs/syntax/">Syntax</a> and <code>examples/</code>.'
            ),
        ],
    )


def _pattern_page():
    return _page(
        "pattern-matching",
        "Pattern matching",
        "Pattern matching",
        "Enums, unions, match — brancher selon la forme d’une valeur.",
        "Enums, unions, match — branch on the shape of a value.",
        [
            callout(
                "<strong>En une phrase</strong> — Au lieu d’une cascade de <code>if</code>, "
                "décrivez les formes possibles et ce qu’il faut faire pour chacune."
            ),
            h2("1. Pourquoi matcher ?"),
            p(
                "Quand une valeur peut être « Ok » ou « Error avec message », "
                "ou « cercle » vs « rectangle », tester à la main devient fragile. "
                "Le pattern matching nomme chaque forme et peut extraire les champs "
                "(payload) en une seule étape. "
                "Le compilateur peut aussi exiger que tous les cas soient couverts "
                "(ou un <code>default</code>)."
            ),
            h2("2. Enums"),
            p(
                "Un <code>enum</code> liste des cas nommés. "
                "Certains cas portent des données (<code>case Error with message text</code>). "
                "C’est le bon outil pour des états discrets d’un domaine."
            ),
            code(
                "enum Status\n"
                "    case Ok\n"
                "    case Error with message text\n"
                "end"
            ),
            h2("3. match"),
            p(
                "<code>match</code> examine une valeur et choisit la branche "
                "<code>case</code> correspondante. "
                "Avec <code>with msg</code>, vous liez le payload à une variable locale. "
                "<code>default</code> couvre le reste. "
                "Chaque branche (et le match) se ferme avec <code>end</code>."
            ),
            code(
                "match e\n"
                "    case Error with msg then say msg\n"
                "    end\n"
                '    default say "ok"\n'
                "end"
            ),
            h2("4. Unions taguées"),
            p(
                "Une union regroupe des formes différentes (ex. formes géométriques). "
                "Le match devient alors le moyen sûr de calculer une aire ou un affichage "
                "sans casts hasardeux."
            ),
            callout(
                'Pratique : <code>examples/</code> + page '
                '<a href="/docs/types/">Types</a> pour optionnels/Result.'
            ),
        ],
        [
            callout(
                "<strong>In one sentence</strong> — Instead of long <code>if</code> chains, "
                "name each shape and what to do for it."
            ),
            h2("1. Why match?"),
            p(
                "When a value can be Ok vs Error-with-message, or circle vs rectangle, "
                "pattern matching names each shape and can bind payload fields. "
                "The compiler can require exhaustiveness or a <code>default</code>."
            ),
            h2("2. Enums"),
            p(
                "An <code>enum</code> lists named cases; some carry data "
                "(<code>case Error with message text</code>)."
            ),
            code(
                "enum Status\n"
                "    case Ok\n"
                "    case Error with message text\n"
                "end"
            ),
            h2("3. match"),
            p(
                "<code>match</code> picks a <code>case</code>. "
                "<code>with msg</code> binds payload. "
                "<code>default</code> covers the rest. Close with <code>end</code>."
            ),
            code(
                "match e\n"
                "    case Error with msg then say msg\n"
                "    end\n"
                '    default say "ok"\n'
                "end"
            ),
            h2("4. Tagged unions"),
            p(
                "Unions group different shapes; match is the safe way to compute on them."
            ),
            callout(
                'Practice: <code>examples/</code> + '
                '<a href="/docs/types/">Types</a> for optionals/Result.'
            ),
        ],
    )

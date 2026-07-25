"""Documentation détaillée style référence — pages avancées + enrichissements."""

from .docs_pages import _page, callout, code, h2, h3, p, table, ul


def register_detailed_documentation(pages):
    """Ajoute macros / itération et approfondit les pages langage."""
    pages['macros'] = _macros_page()
    pages['iteration'] = _iteration_page()
    _deepen_types(pages)
    _deepen_pattern(pages)
    _deepen_syntax(pages)
    _deepen_oop(pages)
    _deepen_functional(pages)
    _deepen_overview(pages)


def _append_blocks(page, fr_extra, en_extra):
    page['fr']['blocks'].extend(fr_extra)
    page['en']['blocks'].extend(en_extra)


def _deepen_overview(pages):
    page = pages.get('overview')
    if not page:
        return
    _append_blocks(
        page,
        [
            h2('5. Chapitres avancés (référence détaillée)'),
            p(
                'Au-delà du parcours débutant, ces pages détaillent le langage '
                'comme une référence : explications, exemples exécutables, '
                'erreurs fréquentes et liens playground.'
            ),
            table(
                ['Sujet', 'Page', 'Exemples playground'],
                [
                    [
                        'Macros',
                        '<a href="/docs/macros/">Macros</a>',
                        '<code>macros-demo</code>',
                    ],
                    [
                        'Générateurs &amp; plages',
                        '<a href="/docs/iteration/">Itération</a>',
                        '<code>generators-demo</code>, <code>ranges-demo</code>',
                    ],
                    [
                        'Contraintes génériques',
                        '<a href="/docs/types/">Types</a> §6',
                        '<code>generics-constraints</code>',
                    ],
                    [
                        'Optionnels &amp; Result',
                        '<a href="/docs/types/">Types</a> §3–4',
                        '<code>optionals-result</code>',
                    ],
                    [
                        'Match avancé',
                        '<a href="/docs/pattern-matching/">Pattern matching</a>',
                        '<code>match-advanced</code>',
                    ],
                ],
            ),
            callout(
                '<strong>Pratique :</strong> ouvrez le '
                '<a href="/playground/">playground</a> et chargez un exemple '
                'par son slug (menu « Exemples »).'
            ),
        ],
        [
            h2('5. Advanced chapters (detailed reference)'),
            p(
                'Beyond the beginner path, these pages detail the language '
                'like a reference: explanations, runnable examples, '
                'common errors, and playground links.'
            ),
            table(
                ['Topic', 'Page', 'Playground examples'],
                [
                    [
                        'Macros',
                        '<a href="/docs/macros/">Macros</a>',
                        '<code>macros-demo</code>',
                    ],
                    [
                        'Generators &amp; ranges',
                        '<a href="/docs/iteration/">Iteration</a>',
                        '<code>generators-demo</code>, <code>ranges-demo</code>',
                    ],
                    [
                        'Generic constraints',
                        '<a href="/docs/types/">Types</a> §6',
                        '<code>generics-constraints</code>',
                    ],
                    [
                        'Optionals &amp; Result',
                        '<a href="/docs/types/">Types</a> §3–4',
                        '<code>optionals-result</code>',
                    ],
                    [
                        'Advanced match',
                        '<a href="/docs/pattern-matching/">Pattern matching</a>',
                        '<code>match-advanced</code>',
                    ],
                ],
            ),
            callout(
                '<strong>Practice:</strong> open the '
                '<a href="/playground/">playground</a> and load an example '
                'by slug (Examples menu).'
            ),
        ],
    )


def _deepen_syntax(pages):
    page = pages.get('syntax')
    if not page:
        return
    _append_blocks(
        page,
        [
            h2('11. Plages numériques (littéraux)'),
            p(
                'En plus de <code>for i from A to B</code>, AFRILANG accepte des '
                '<strong>littéraux de plage</strong> : <code>1..5</code> (inclusif) '
                'et <code>1..&lt;5</code> (exclusif à droite). '
                'Une plage peut être itérée directement ou stockée comme liste.'
            ),
            code(
                'for each x in 1..5 do\n'
                '    say x\n'
                'end\n\n'
                'create xs = 1..3   // [1, 2, 3]\n'
                'say xs at 0'
            ),
            p(
                'Voir la page <a href="/docs/iteration/">Itération</a> pour les '
                'générateurs et le protocole <code>hasNext</code>/<code>next</code>.'
            ),
            h2('12. Comparaisons naturelles (référence)'),
            p(
                'Les opérateurs symboliques <code>==</code>, <code>&lt;</code>, etc. '
                'existent aussi, mais le style idiomatique privilégie les mots :'
            ),
            table(
                ['Mot', 'Sens'],
                [
                    ['<code>is equal to</code>', 'égalité'],
                    ['<code>is not equal to</code>', 'inégalité'],
                    ['<code>is greater than</code>', 'strictement supérieur'],
                    ['<code>is less than</code>', 'strictement inférieur'],
                ],
            ),
            h2('13. Exemple complet commenté'),
            p(
                'Ce mini-programme combine variables, condition, boucle et liste. '
                'Chaque ligne a un rôle clair — c’est le niveau de détail attendu '
                'quand vous lisez un tutoriel ou une page de référence.'
            ),
            code(
                '// Score d’un joueur et message selon le seuil\n'
                'create score = 85\n'
                'create grades = list of "A", "B", "C"\n\n'
                'if score is greater than 79 then\n'
                '    say "Bravo : {score}"\n'
                '    say grades at 0\n'
                'else\n'
                '    say "Continue"\n'
                'end\n\n'
                'for each g in grades do\n'
                '    say g\n'
                'end'
            ),
            callout(
                '<strong>Playground :</strong> '
                '<a href="/playground/?example=conditions">conditions</a>, '
                '<a href="/playground/?example=ranges-demo">ranges-demo</a>, '
                '<a href="/playground/?example=language-demo">language-demo</a>.'
            ),
        ],
        [
            h2('11. Numeric range literals'),
            p(
                'Besides <code>for i from A to B</code>, AFRILANG supports '
                '<strong>range literals</strong>: <code>1..5</code> (inclusive) '
                'and <code>1..&lt;5</code> (exclusive end). '
                'A range can be iterated or stored as a list.'
            ),
            code(
                'for each x in 1..5 do\n'
                '    say x\n'
                'end\n\n'
                'create xs = 1..3   // [1, 2, 3]\n'
                'say xs at 0'
            ),
            p(
                'See <a href="/docs/iteration/">Iteration</a> for generators '
                'and the <code>hasNext</code>/<code>next</code> protocol.'
            ),
            h2('12. Natural comparisons (reference)'),
            p(
                'Symbolic operators exist too, but idiomatic style prefers words:'
            ),
            table(
                ['Phrase', 'Meaning'],
                [
                    ['<code>is equal to</code>', 'equality'],
                    ['<code>is not equal to</code>', 'inequality'],
                    ['<code>is greater than</code>', 'strictly greater'],
                    ['<code>is less than</code>', 'strictly less'],
                ],
            ),
            h2('13. Fully commented example'),
            p(
                'This mini-program combines variables, conditionals, loops, and lists.'
            ),
            code(
                '// Player score and message by threshold\n'
                'create score = 85\n'
                'create grades = list of "A", "B", "C"\n\n'
                'if score is greater than 79 then\n'
                '    say "Great: {score}"\n'
                '    say grades at 0\n'
                'else\n'
                '    say "Keep going"\n'
                'end\n\n'
                'for each g in grades do\n'
                '    say g\n'
                'end'
            ),
            callout(
                '<strong>Playground:</strong> '
                '<a href="/playground/?example=conditions">conditions</a>, '
                '<a href="/playground/?example=ranges-demo">ranges-demo</a>, '
                '<a href="/playground/?example=language-demo">language-demo</a>.'
            ),
        ],
    )


def _deepen_types(pages):
    page = pages.get('types')
    if not page:
        return
    _append_blocks(
        page,
        [
            h2('6. Contraintes génériques (<code>where</code>)'),
            p(
                'Par défaut, <code>&lt;T&gt;</code> accepte n’importe quel type. '
                'Pour restreindre T, ajoutez une clause <code>where</code> après '
                'la signature :'
            ),
            ul([
                '<code>where T is number|int|text|bool|…</code> — ensemble de types autorisés',
                '<code>where T implements NomInterface</code> — T doit implémenter l’interface',
            ]),
            code(
                'function onlyNumber<T>(x T) returns T where T is number\n'
                '    return x\n'
                'end\n\n'
                'say onlyNumber(21)   // OK\n'
                '// onlyNumber("x")  // erreur de compilation'
            ),
            p(
                'Les contraintes sont vérifiées à la compilation (MVP). '
                'Exemple playground : '
                '<a href="/playground/?example=generics-constraints">generics-constraints</a>.'
            ),
            h2('7. Optionnels — API complète'),
            p(
                'Outre <code>is defined</code>, utilisez :'
            ),
            ul([
                '<code>a or else défaut</code> — valeur si présente, sinon repli',
                '<code>objet?.champ</code> — navigation sûre (un niveau), résultat optionnel',
                '<code>match</code> avec <code>case value v</code> / <code>case nothing</code>',
            ]),
            code(
                'create absent number? = nothing\n'
                'say absent or else 0\n\n'
                'create maybe number? = 9\n'
                'match maybe\n'
                '    case value v then\n'
                '        say v\n'
                '    end\n'
                '    case nothing then\n'
                '        say "vide"\n'
                '    end\n'
                'end'
            ),
            h2('8. Result — API complète'),
            p(
                'Un <code>Result</code> (<code>T or error</code>) se manipule sans accès '
                'aveugle à <code>.value</code> :'
            ),
            ul([
                '<code>is error</code> puis <code>.message</code> / <code>.value</code>',
                '<code>r or else défaut</code> — succès → valeur, sinon repli',
                '<code>x or return</code> — propage l’erreur (fonction <code>T or error</code>)',
                '<code>x or raise</code> — convertit l’erreur en exception',
                '<code>match</code> : <code>case ok v</code> / <code>case error m</code>',
            ]),
            code(
                'function half(x number) returns number or error\n'
                '    if x is less than 0 then\n'
                '        return error "négatif"\n'
                '    end\n'
                '    return x / 2\n'
                'end\n\n'
                'function chain(a number, b number) returns number or error\n'
                '    create x = half(a) or return\n'
                '    create y = half(b) or return\n'
                '    return x + y\n'
                'end\n\n'
                'say half(8) or else 0\n'
                'say chain(8, 4) or else -1'
            ),
            h2('9. Type <code>int</code>'),
            p(
                '<code>int</code> (alias FR <code>entier</code>) est un entier 64 bits. '
                'Préférez-le aux compteurs et indices quand vous ne voulez pas de flottants. '
                '<code>number</code> reste le type par défaut pour les calculs décimaux.'
            ),
            code(
                'create i int = 0\n'
                'while i is less than 3 do\n'
                '    say i\n'
                '    set i = i + 1\n'
                'end'
            ),
            callout(
                '<strong>Playground :</strong> '
                '<a href="/playground/?example=optionals-result">optionals-result</a>, '
                '<a href="/playground/?example=result">result</a>, '
                '<a href="/playground/?example=generics">generics</a>.'
            ),
        ],
        [
            h2('6. Generic constraints (<code>where</code>)'),
            p(
                'By default <code>&lt;T&gt;</code> accepts any type. '
                'Restrict T with a <code>where</code> clause after the signature:'
            ),
            ul([
                '<code>where T is number|int|text|bool|…</code> — allowed type set',
                '<code>where T implements InterfaceName</code> — T must implement the interface',
            ]),
            code(
                'function onlyNumber<T>(x T) returns T where T is number\n'
                '    return x\n'
                'end\n\n'
                'say onlyNumber(21)   // OK\n'
                '// onlyNumber("x")  // compile error'
            ),
            p(
                'Constraints are checked at compile time (MVP). '
                'Playground: '
                '<a href="/playground/?example=generics-constraints">generics-constraints</a>.'
            ),
            h2('7. Optionals — full API'),
            p('Beyond <code>is defined</code>, use:'),
            ul([
                '<code>a or else default</code> — value if present, else fallback',
                '<code>obj?.field</code> — safe navigation (one level), optional result',
                '<code>match</code> with <code>case value v</code> / <code>case nothing</code>',
            ]),
            code(
                'create absent number? = nothing\n'
                'say absent or else 0\n\n'
                'create maybe number? = 9\n'
                'match maybe\n'
                '    case value v then\n'
                '        say v\n'
                '    end\n'
                '    case nothing then\n'
                '        say "empty"\n'
                '    end\n'
                'end'
            ),
            h2('8. Result — full API'),
            p(
                'A <code>Result</code> (<code>T or error</code>) should not be blindly '
                'unwrapped via <code>.value</code>:'
            ),
            ul([
                '<code>is error</code> then <code>.message</code> / <code>.value</code>',
                '<code>r or else default</code> — success → value, else fallback',
                '<code>x or return</code> — propagate error (in <code>T or error</code> functions)',
                '<code>x or raise</code> — turn error into an exception',
                '<code>match</code>: <code>case ok v</code> / <code>case error m</code>',
            ]),
            code(
                'function half(x number) returns number or error\n'
                '    if x is less than 0 then\n'
                '        return error "negative"\n'
                '    end\n'
                '    return x / 2\n'
                'end\n\n'
                'function chain(a number, b number) returns number or error\n'
                '    create x = half(a) or return\n'
                '    create y = half(b) or return\n'
                '    return x + y\n'
                'end\n\n'
                'say half(8) or else 0\n'
                'say chain(8, 4) or else -1'
            ),
            h2('9. The <code>int</code> type'),
            p(
                '<code>int</code> (FR alias <code>entier</code>) is a 64-bit integer. '
                'Prefer it for counters and indices; keep <code>number</code> for decimals.'
            ),
            code(
                'create i int = 0\n'
                'while i is less than 3 do\n'
                '    say i\n'
                '    set i = i + 1\n'
                'end'
            ),
            callout(
                '<strong>Playground:</strong> '
                '<a href="/playground/?example=optionals-result">optionals-result</a>, '
                '<a href="/playground/?example=result">result</a>, '
                '<a href="/playground/?example=generics">generics</a>.'
            ),
        ],
    )


def _deepen_pattern(pages):
    page = pages.get('pattern-matching')
    if not page:
        return
    _append_blocks(
        page,
        [
            h2('Motifs avancés (nombres, bool, Result, optionnels)'),
            p(
                'Le <code>match</code> ne se limite pas aux enums. '
                'Il accepte des motifs riches sur <code>number</code>, <code>text</code>, '
                '<code>bool</code>, <code>Result</code> et optionnels.'
            ),
            h3('Plages et or-patterns'),
            code(
                'match n\n'
                '    case 0 then\n'
                '        say "zéro"\n'
                '    end\n'
                '    case 1 to 10 then\n'
                '        say "petit"\n'
                '    end\n'
                '    case 11 or 12 or 13 then\n'
                '        say "ado"\n'
                '    end\n'
                '    case _ then\n'
                '        say "grand"\n'
                '    end\n'
                'end'
            ),
            ul([
                '<code>a to b</code> — plage numérique inclusive',
                '<code>x or y or z</code> — plusieurs valeurs dans un même bras',
                '<code>_</code> — joker (comme <code>default</code>, rend le match exhaustif)',
            ]),
            h3('Result et optionnels'),
            code(
                'match half(x)\n'
                '    case ok v then\n'
                '        say v\n'
                '    end\n'
                '    case error m then\n'
                '        say m\n'
                '    end\n'
                'end\n\n'
                'match maybeValue\n'
                '    case value v then\n'
                '        say v\n'
                '    end\n'
                '    case nothing then\n'
                '        say "vide"\n'
                '    end\n'
                'end'
            ),
            p(
                'Exhaustivité : <code>bool</code> exige <code>true</code> + <code>false</code> '
                '(ou <code>_</code>) ; <code>Result</code> exige <code>ok</code> + <code>error</code> ; '
                'optionnel exige <code>value</code> + <code>nothing</code>.'
            ),
            callout(
                '<strong>Playground :</strong> '
                '<a href="/playground/?example=match-advanced">match-advanced</a>, '
                '<a href="/playground/?example=match-expr-demo">match-expr-demo</a>, '
                '<a href="/playground/?example=unions-demo">unions-demo</a>.'
            ),
        ],
        [
            h2('Advanced patterns (numbers, bool, Result, optionals)'),
            p(
                '<code>match</code> is not limited to enums. '
                'It supports rich patterns on <code>number</code>, <code>text</code>, '
                '<code>bool</code>, <code>Result</code>, and optionals.'
            ),
            h3('Ranges and or-patterns'),
            code(
                'match n\n'
                '    case 0 then\n'
                '        say "zero"\n'
                '    end\n'
                '    case 1 to 10 then\n'
                '        say "small"\n'
                '    end\n'
                '    case 11 or 12 or 13 then\n'
                '        say "teen"\n'
                '    end\n'
                '    case _ then\n'
                '        say "large"\n'
                '    end\n'
                'end'
            ),
            ul([
                '<code>a to b</code> — inclusive numeric range',
                '<code>x or y or z</code> — several values in one arm',
                '<code>_</code> — wildcard (like <code>default</code>)',
            ]),
            h3('Result and optionals'),
            code(
                'match half(x)\n'
                '    case ok v then\n'
                '        say v\n'
                '    end\n'
                '    case error m then\n'
                '        say m\n'
                '    end\n'
                'end\n\n'
                'match maybeValue\n'
                '    case value v then\n'
                '        say v\n'
                '    end\n'
                '    case nothing then\n'
                '        say "empty"\n'
                '    end\n'
                'end'
            ),
            p(
                'Exhaustiveness: <code>bool</code> needs <code>true</code> + <code>false</code> '
                '(or <code>_</code>); <code>Result</code> needs <code>ok</code> + <code>error</code>; '
                'optionals need <code>value</code> + <code>nothing</code>.'
            ),
            callout(
                '<strong>Playground:</strong> '
                '<a href="/playground/?example=match-advanced">match-advanced</a>, '
                '<a href="/playground/?example=match-expr-demo">match-expr-demo</a>, '
                '<a href="/playground/?example=unions-demo">unions-demo</a>.'
            ),
        ],
    )


def _deepen_oop(pages):
    page = pages.get('oop')
    if not page:
        return
    _append_blocks(
        page,
        [
            h2('5. Mots-clés POO (référence)'),
            table(
                ['Mot-clé', 'Rôle'],
                [
                    ['<code>static field</code> / <code>static function</code>', 'Partagé par la classe'],
                    ['<code>abstract class</code> / <code>abstract function</code>', 'Non instanciable / à redéfinir'],
                    ['<code>final class</code> / <code>final function</code>', 'Non extensible / non redéfinissable'],
                    ['<code>property</code>', 'Getter/setter auto'],
                    ['<code>destroy … end</code>', 'Destructeur virtuel'],
                    ['<code>protected field</code>', 'Visible dans la hiérarchie'],
                ],
            ),
            h2('6. Surcharge d’opérateurs'),
            p(
                'Dans une classe, déclarez <code>operator +</code>, <code>-</code>, '
                '<code>*</code>, <code>/</code>, <code>==</code>, <code>!=</code>, '
                '<code>&lt;</code>, <code>&gt;</code> pour définir le comportement '
                'des opérateurs sur vos types.'
            ),
            code(
                'class Vector\n'
                '    public field x number\n'
                '    public field y number\n\n'
                '    function init(ax number, ay number)\n'
                '        set this.x = ax\n'
                '        set this.y = ay\n'
                '    end\n\n'
                '    operator + (other Vector) returns Vector\n'
                '        return new Vector(x + other.x, y + other.y)\n'
                '    end\n'
                'end\n\n'
                'create a = new Vector(1, 2)\n'
                'create b = new Vector(3, 4)\n'
                'create c = a + b\n'
                'say c.x'
            ),
            callout(
                '<strong>Playground :</strong> '
                '<a href="/playground/?example=operators-demo">operators-demo</a>, '
                '<a href="/playground/?example=oop-full">oop-full</a>, '
                '<a href="/playground/?example=poo-advanced">poo-advanced</a>.'
            ),
        ],
        [
            h2('5. OOP keywords (reference)'),
            table(
                ['Keyword', 'Role'],
                [
                    ['<code>static field</code> / <code>static function</code>', 'Shared by the class'],
                    ['<code>abstract class</code> / <code>abstract function</code>', 'Not instantiable / must override'],
                    ['<code>final class</code> / <code>final function</code>', 'Not extensible / not overridable'],
                    ['<code>property</code>', 'Auto getter/setter'],
                    ['<code>destroy … end</code>', 'Virtual destructor'],
                    ['<code>protected field</code>', 'Visible in the hierarchy'],
                ],
            ),
            h2('6. Operator overloading'),
            p(
                'Inside a class, declare <code>operator +</code>, <code>-</code>, '
                '<code>*</code>, <code>/</code>, <code>==</code>, <code>!=</code>, '
                '<code>&lt;</code>, <code>&gt;</code>.'
            ),
            code(
                'class Vector\n'
                '    public field x number\n'
                '    public field y number\n\n'
                '    function init(ax number, ay number)\n'
                '        set this.x = ax\n'
                '        set this.y = ay\n'
                '    end\n\n'
                '    operator + (other Vector) returns Vector\n'
                '        return new Vector(x + other.x, y + other.y)\n'
                '    end\n'
                'end\n\n'
                'create a = new Vector(1, 2)\n'
                'create b = new Vector(3, 4)\n'
                'create c = a + b\n'
                'say c.x'
            ),
            callout(
                '<strong>Playground:</strong> '
                '<a href="/playground/?example=operators-demo">operators-demo</a>, '
                '<a href="/playground/?example=oop-full">oop-full</a>, '
                '<a href="/playground/?example=poo-advanced">poo-advanced</a>.'
            ),
        ],
    )


def _deepen_functional(pages):
    page = pages.get('functional')
    if not page:
        return
    _append_blocks(
        page,
        [
            h2('Paramètres par défaut (détail)'),
            p(
                'Les paramètres optionnels se placent à la fin de la liste. '
                'L’appelant peut omettre la valeur : le défaut est alors utilisé.'
            ),
            code(
                'function greet(name text, prefix text = "Hello") returns text\n'
                '    return "{prefix} {name}"\n'
                'end\n\n'
                'say greet("World")\n'
                'say greet("Africa", "Bonjour")'
            ),
            h2('Lambdas et collections — recettes'),
            p(
                'Chaînez <code>map</code>, <code>filter</code> et <code>reduce</code> '
                'pour transformer des listes sans boucles manuelles :'
            ),
            code(
                'create nums = list of 1, 2, 3, 4, 5\n\n'
                'create doubled = map each x in nums do\n'
                '    return x * 2\n'
                'end\n\n'
                'create bigOnes = filter each x in nums where x is greater than 3\n\n'
                'create total = reduce nums from 0 with each acc, x do\n'
                '    return acc + x\n'
                'end\n'
                'say total'
            ),
            callout(
                '<strong>Playground :</strong> '
                '<a href="/playground/?example=lambdas">lambdas</a>, '
                '<a href="/playground/?example=list-ops">list-ops</a>, '
                '<a href="/playground/?example=natural-list-ops">natural-list-ops</a>, '
                '<a href="/playground/?example=defaults">defaults</a>.'
            ),
        ],
        [
            h2('Default parameters (detail)'),
            p(
                'Optional parameters go at the end of the parameter list. '
                'Callers may omit them to use the default.'
            ),
            code(
                'function greet(name text, prefix text = "Hello") returns text\n'
                '    return "{prefix} {name}"\n'
                'end\n\n'
                'say greet("World")\n'
                'say greet("Africa", "Bonjour")'
            ),
            h2('Lambdas and collections — recipes'),
            p(
                'Chain <code>map</code>, <code>filter</code>, and <code>reduce</code> '
                'to transform lists without manual loops:'
            ),
            code(
                'create nums = list of 1, 2, 3, 4, 5\n\n'
                'create doubled = map each x in nums do\n'
                '    return x * 2\n'
                'end\n\n'
                'create bigOnes = filter each x in nums where x is greater than 3\n\n'
                'create total = reduce nums from 0 with each acc, x do\n'
                '    return acc + x\n'
                'end\n'
                'say total'
            ),
            callout(
                '<strong>Playground:</strong> '
                '<a href="/playground/?example=lambdas">lambdas</a>, '
                '<a href="/playground/?example=list-ops">list-ops</a>, '
                '<a href="/playground/?example=natural-list-ops">natural-list-ops</a>, '
                '<a href="/playground/?example=defaults">defaults</a>.'
            ),
        ],
    )


def _macros_page():
    return _page(
        'macros',
        'Macros',
        'Macros',
        'Définir et appeler des macros MVP : substitution d’identifiants et d’expressions '
        'avant la génération de code.',
        'Define and call MVP macros: identifier/expression substitution '
        'before code generation.',
        [
            callout(
                '<strong>Objectif</strong> — Écrire une macro, l’appeler avec '
                '<code>!</code>, comprendre les limites (pas de récursion, pas '
                'd’introspection AST).'
            ),
            h2('1. Qu’est-ce qu’une macro ?'),
            p(
                'Une macro est un <strong>modèle de code</strong> développé '
                '<em>avant</em> la génération C++/JS. '
                'Contrairement à une fonction, elle ne s’exécute pas à l’appel : '
                'ses arguments sont <strong>substitués textuellement</strong> dans '
                'le corps, puis le résultat est compilé comme du code normal.'
            ),
            p(
                'Cas d’usage typiques : assertions répétées, wrappers d’affichage, '
                'petits idiomes sans coût d’appel de fonction.'
            ),
            h2('2. Syntaxe'),
            p(
                'Déclarez avec <code>macro nom(params) … end</code> '
                '(alias FR : <code>macrocommande</code>). '
                'Appelez avec <code>nom!(args)</code> — le <code>!</code> est obligatoire.'
            ),
            code(
                'macro shout(msg)\n'
                '    say msg\n'
                'end\n\n'
                'macro assertEq(a, b)\n'
                '    assert a is equal to b\n'
                'end\n\n'
                'shout!("hello")\n'
                'assertEq!(1 + 1, 2)'
            ),
            h2('3. Expansion et cibles'),
            p(
                'L’expansion est <strong>sémantique</strong> (avant codegen). '
                'Les macros fonctionnent en <strong>natif</strong>, <strong>WASM</strong> '
                'et dans le <strong>playground JS</strong> après expansion.'
            ),
            table(
                ['Propriété', 'Statut MVP'],
                [
                    ['Substitution d’identifiants / expressions', 'Oui'],
                    ['Récursion de macros', 'Non'],
                    ['Introspection AST / hygiène', 'Non'],
                    ['Alias FR <code>macrocommande</code>', 'Oui'],
                ],
            ),
            h2('4. Erreurs fréquentes'),
            ul([
                'Oublier le <code>!</code> à l’appel → traité comme un identifiant normal',
                'Attendre une exécution « runtime » comme une fonction — ce n’est pas le cas',
                'Compter sur des macros hygiéniques (Python/Lisp) — hors scope MVP',
            ]),
            callout(
                '<strong>Suite :</strong> '
                '<a href="/playground/?example=macros-demo">Essayer macros-demo →</a> · '
                '<a href="/docs/iteration/">Itération →</a>'
            ),
        ],
        [
            callout(
                '<strong>Goal</strong> — Write a macro, call it with '
                '<code>!</code>, understand limits (no recursion, no AST introspection).'
            ),
            h2('1. What is a macro?'),
            p(
                'A macro is a <strong>code template</strong> expanded '
                '<em>before</em> C++/JS generation. '
                'Unlike a function, it does not run at call time: '
                'arguments are <strong>textually substituted</strong> into the body, '
                'then the result is compiled as normal code.'
            ),
            p(
                'Typical uses: repeated asserts, print wrappers, '
                'small idioms without call overhead.'
            ),
            h2('2. Syntax'),
            p(
                'Declare with <code>macro name(params) … end</code> '
                '(FR alias: <code>macrocommande</code>). '
                'Call with <code>name!(args)</code> — the <code>!</code> is required.'
            ),
            code(
                'macro shout(msg)\n'
                '    say msg\n'
                'end\n\n'
                'macro assertEq(a, b)\n'
                '    assert a is equal to b\n'
                'end\n\n'
                'shout!("hello")\n'
                'assertEq!(1 + 1, 2)'
            ),
            h2('3. Expansion and targets'),
            p(
                'Expansion is <strong>semantic</strong> (before codegen). '
                'Macros work on <strong>native</strong>, <strong>WASM</strong>, '
                'and the <strong>JS playground</strong> after expansion.'
            ),
            table(
                ['Property', 'MVP status'],
                [
                    ['Identifier / expression substitution', 'Yes'],
                    ['Macro recursion', 'No'],
                    ['AST introspection / hygiene', 'No'],
                    ['FR alias <code>macrocommande</code>', 'Yes'],
                ],
            ),
            h2('4. Common mistakes'),
            ul([
                'Forgetting <code>!</code> at the call site',
                'Expecting runtime execution like a function',
                'Expecting hygienic macros — out of MVP scope',
            ]),
            callout(
                '<strong>Next:</strong> '
                '<a href="/playground/?example=macros-demo">Try macros-demo →</a> · '
                '<a href="/docs/iteration/">Iteration →</a>'
            ),
        ],
    )


def _iteration_page():
    return _page(
        'iteration',
        'Itération, générateurs et plages',
        'Iteration, generators, and ranges',
        'Générateurs avec yield, littéraux de plage 1..n, protocole hasNext/next.',
        'Generators with yield, 1..n range literals, hasNext/next protocol.',
        [
            callout(
                '<strong>Objectif</strong> — Parcourir des séquences paresseusement '
                '(générateurs), écrire des plages compactes, et rendre vos classes '
                'itérables via un protocole duck-typé.'
            ),
            h2('1. Trois façons d’itérer'),
            table(
                ['Forme', 'Quand l’utiliser'],
                [
                    ['<code>for each x in liste do</code>', 'Liste déjà en mémoire'],
                    ['<code>for each x in 1..n do</code>', 'Plage numérique compacte'],
                    ['<code>for each x in gen(…) do</code>', 'Générateur / itérateur custom'],
                ],
            ),
            h2('2. Générateurs (<code>yield</code>)'),
            p(
                'Une <code>generator function</code> produit des valeurs une à une '
                'avec <code>yield</code>, sans construire toute la liste d’avance. '
                'Le type de retour indique la forme de séquence '
                '(souvent <code>returns list T</code>).'
            ),
            code(
                'generator function compteur(n number) returns list number\n'
                '    create i number = 0\n'
                '    while i is less than n do\n'
                '        yield i\n'
                '        set i = i + 1\n'
                '    end\n'
                'end\n\n'
                'for each v in compteur(5) do\n'
                '    say v\n'
                'end'
            ),
            p(
                'Chaque <code>yield</code> suspend la fonction et fournit une valeur '
                'au <code>for each</code>. Quand la fonction se termine, l’itération s’arrête.'
            ),
            h2('3. Littéraux de plage'),
            p(
                '<code>a..b</code> est inclusif (a et b inclus). '
                '<code>a..&lt;b</code> exclut b. '
                'Vous pouvez aussi stocker une plage comme liste :'
            ),
            code(
                'for each x in 1..5 do\n'
                '    say x\n'
                'end\n\n'
                'create total number = 0\n'
                'for each x in 1..<5 do\n'
                '    set total = total + x\n'
                'end\n'
                '// 1+2+3+4 = 10\n\n'
                'create xs = 1..3\n'
                'say length of xs   // 3'
            ),
            h2('4. Protocole d’itération'),
            p(
                'Toute classe exposant <code>hasNext() returns bool</code> et '
                '<code>next() returns T</code> est itérable dans un '
                '<code>for each</code> — sans hériter d’une interface spéciale '
                '(duck typing).'
            ),
            code(
                'class Countdown\n'
                '    public field current number\n'
                '    function hasNext() returns bool\n'
                '        return current is greater than 0\n'
                '    end\n'
                '    function next() returns number\n'
                '        set current = current - 1\n'
                '        return current + 1\n'
                '    end\n'
                'end\n\n'
                'create c = new Countdown()\n'
                'set c.current = 3\n'
                'for each v in c do\n'
                '    say v\n'
                'end'
            ),
            h2('5. Erreurs fréquentes'),
            ul([
                'Confondre <code>1..5</code> (inclusif) et <code>1..&lt;5</code> (exclusif)',
                'Oublier <code>yield</code> dans un générateur (fonction vide)',
                'Implémenter seulement <code>next</code> sans <code>hasNext</code>',
            ]),
            callout(
                '<strong>Playground :</strong> '
                '<a href="/playground/?example=generators-demo">generators-demo</a>, '
                '<a href="/playground/?example=ranges-demo">ranges-demo</a>, '
                '<a href="/playground/?example=iterator-protocol">iterator-protocol</a>.'
            ),
        ],
        [
            callout(
                '<strong>Goal</strong> — Iterate lazily (generators), write compact ranges, '
                'and make classes iterable via a duck-typed protocol.'
            ),
            h2('1. Three ways to iterate'),
            table(
                ['Form', 'When to use'],
                [
                    ['<code>for each x in list do</code>', 'List already in memory'],
                    ['<code>for each x in 1..n do</code>', 'Compact numeric range'],
                    ['<code>for each x in gen(…) do</code>', 'Generator / custom iterator'],
                ],
            ),
            h2('2. Generators (<code>yield</code>)'),
            p(
                'A <code>generator function</code> produces values one at a time '
                'with <code>yield</code>, without building the full list upfront.'
            ),
            code(
                'generator function counter(n number) returns list number\n'
                '    create i number = 0\n'
                '    while i is less than n do\n'
                '        yield i\n'
                '        set i = i + 1\n'
                '    end\n'
                'end\n\n'
                'for each v in counter(5) do\n'
                '    say v\n'
                'end'
            ),
            p(
                'Each <code>yield</code> suspends the function and feeds one value '
                'to <code>for each</code>. When the function ends, iteration stops.'
            ),
            h2('3. Range literals'),
            p(
                '<code>a..b</code> is inclusive. <code>a..&lt;b</code> excludes b. '
                'You can also store a range as a list:'
            ),
            code(
                'for each x in 1..5 do\n'
                '    say x\n'
                'end\n\n'
                'create total number = 0\n'
                'for each x in 1..<5 do\n'
                '    set total = total + x\n'
                'end\n'
                '// 1+2+3+4 = 10\n\n'
                'create xs = 1..3\n'
                'say length of xs   // 3'
            ),
            h2('4. Iteration protocol'),
            p(
                'Any class exposing <code>hasNext() returns bool</code> and '
                '<code>next() returns T</code> is iterable in <code>for each</code> '
                '(duck typing — no special interface required).'
            ),
            code(
                'class Countdown\n'
                '    public field current number\n'
                '    function hasNext() returns bool\n'
                '        return current is greater than 0\n'
                '    end\n'
                '    function next() returns number\n'
                '        set current = current - 1\n'
                '        return current + 1\n'
                '    end\n'
                'end\n\n'
                'create c = new Countdown()\n'
                'set c.current = 3\n'
                'for each v in c do\n'
                '    say v\n'
                'end'
            ),
            h2('5. Common mistakes'),
            ul([
                'Confusing <code>1..5</code> (inclusive) with <code>1..&lt;5</code>',
                'Forgetting <code>yield</code> in a generator',
                'Implementing <code>next</code> without <code>hasNext</code>',
            ]),
            callout(
                '<strong>Playground:</strong> '
                '<a href="/playground/?example=generators-demo">generators-demo</a>, '
                '<a href="/playground/?example=ranges-demo">ranges-demo</a>, '
                '<a href="/playground/?example=iterator-protocol">iterator-protocol</a>.'
            ),
        ],
    )

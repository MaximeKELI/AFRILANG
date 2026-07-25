"""Ajoute des explications pédagogiques autour des blocs de code de la doc."""

from __future__ import annotations

import re

from .docs_pages import callout


def annotate_documentation_pages(pages: dict) -> None:
    """Pour chaque page FR/EN : explique le code avant/après si la prose manque."""
    for slug, page in pages.items():
        for lang in ('fr', 'en'):
            data = page.get(lang)
            if not data or 'blocks' not in data:
                continue
            data['blocks'] = _annotate_blocks(data['blocks'], lang)


def _annotate_blocks(blocks: list, lang: str) -> list:
    out = []
    i = 0
    while i < len(blocks):
        b = blocks[i]
        out.append(b)
        if b.get('type') == 'code':
            text = b.get('text') or ''
            nxt = blocks[i + 1] if i + 1 < len(blocks) else None
            needs_after = True
            if nxt and nxt.get('type') in ('p', 'callout', 'ul'):
                html = str(nxt.get('html', '') or '')
                if nxt.get('type') == 'ul':
                    html = ' '.join(str(x) for x in nxt.get('items', []))
                html_l = html.lower()
                if any(
                    m in html_l
                    for m in (
                        'lecture',
                        'reading',
                        'cet exemple',
                        'this example',
                        'ligne',
                        'line by line',
                        'explique',
                        'explains',
                        'ici :',
                        'here:',
                        'ce que font',
                        'what each',
                        'from 0',
                        'valeur de départ',
                        'start value',
                    )
                ):
                    needs_after = False
            if needs_after:
                explanation = _explain_code(text, lang)
                if explanation:
                    out.append(callout(explanation, 'info'))
        i += 1
    return out


def _explain_code(src: str, lang: str) -> str:
    lines = [ln.rstrip() for ln in src.strip().splitlines() if ln.strip()]
    if not lines:
        return ''

    bullets = []
    for ln in lines:
        stripped = ln.strip()
        if stripped.startswith('//') or stripped.startswith('#'):
            continue
        tip = _line_tip(stripped, lang)
        if tip:
            bullets.append(tip)

    # Dédupliquer tout en gardant l'ordre
    seen = set()
    uniq = []
    for b in bullets:
        key = re.sub(r'\s+', ' ', b.lower())
        if key in seen:
            continue
        seen.add(key)
        uniq.append(b)

    if not uniq:
        return ''

    # Limiter pour rester lisible
    uniq = uniq[:10]
    if lang == 'en':
        head = (
            '<strong>Reading the example</strong> — what each important line does:'
        )
    else:
        head = (
            '<strong>Lecture de l’exemple</strong> — ce que font les lignes importantes :'
        )
    items = ''.join(f'<li>{b}</li>' for b in uniq)
    return f'{head}<ul class="mb-0 mt-2">{items}</ul>'


def _line_tip(line: str, lang: str) -> str | None:
    en = lang == 'en'
    # Normaliser espaces
    s = re.sub(r'\s+', ' ', line).strip()

    if s.startswith('say ') or s.startswith('dire '):
        msg = s.split(' ', 1)[1] if ' ' in s else ''
        return (
            f'Affiche {msg} à l’écran (<code>say</code>).'
            if not en
            else f'Prints {msg} to the screen (<code>say</code>).'
        )

    if s.startswith('ask ') or s.startswith('demander '):
        return (
            'Pose une question et stocke la réponse (<code>ask … into …</code>).'
            if not en
            else 'Asks a question and stores the answer (<code>ask … into …</code>).'
        )

    m = re.match(r'create const (\w+)', s)
    if m:
        return (
            f'Déclare la constante <code>{m.group(1)}</code> (non modifiable ensuite).'
            if not en
            else f'Declares constant <code>{m.group(1)}</code> (not modified later).'
        )

    m = re.match(r'create (\w+)', s)
    if m:
        name = m.group(1)
        if ' list of ' in s or s.endswith('list of'):
            return (
                f'Crée la liste <code>{name}</code>.'
                if not en
                else f'Creates list <code>{name}</code>.'
            )
        if ' map of ' in s or ' map ' in s:
            return (
                f'Crée la map (dictionnaire) <code>{name}</code>.'
                if not en
                else f'Creates map <code>{name}</code>.'
            )
        if ' = nothing' in s or s.endswith('nothing'):
            return (
                f'Déclare l’optionnel <code>{name}</code> sans valeur (<code>nothing</code>).'
                if not en
                else f'Declares optional <code>{name}</code> with no value (<code>nothing</code>).'
            )
        if 'new ' in s:
            return (
                f'Instancie un objet dans <code>{name}</code> via <code>new</code>.'
                if not en
                else f'Instantiates an object into <code>{name}</code> with <code>new</code>.'
            )
        return (
            f'Déclare la variable <code>{name}</code>.'
            if not en
            else f'Declares variable <code>{name}</code>.'
        )

    m = re.match(r'set (\w+)', s)
    if m:
        return (
            f'Met à jour <code>{m.group(1)}</code> avec <code>set</code>.'
            if not en
            else f'Updates <code>{m.group(1)}</code> with <code>set</code>.'
        )

    if s.startswith('if ') or s.startswith('si '):
        return (
            'Ouvre une condition : le bloc après <code>then</code> s’exécute si le test est vrai.'
            if not en
            else 'Opens a conditional: the <code>then</code> block runs if the test is true.'
        )

    if s == 'else' or s == 'sinon':
        return (
            'Branche « sinon » si la condition était fausse.'
            if not en
            else '“Else” branch when the condition was false.'
        )

    if s.startswith('while ') or s.startswith('tantque '):
        return (
            'Boucle : répète le corps tant que la condition reste vraie.'
            if not en
            else 'Loop: repeats the body while the condition stays true.'
        )

    if s.startswith('repeat ') or s.startswith('repeter '):
        return (
            'Répète un nombre fixe de fois (<code>repeat N times</code>).'
            if not en
            else 'Repeats a fixed number of times (<code>repeat N times</code>).'
        )

    if s.startswith('for each ') or s.startswith('pour chaque '):
        return (
            'Parcourt une collection élément par élément.'
            if not en
            else 'Iterates a collection item by item.'
        )

    if s.startswith('for ') and ' from ' in s:
        return (
            'Boucle numérique : compteur de A à B (inclus).'
            if not en
            else 'Numeric loop: counter from A to B (inclusive).'
        )

    if s.startswith('function ') or s.startswith('fonction '):
        name = s.split('(')[0].split()[-1]
        ret = 'returns' in s or 'retourne' in s
        extra = ' avec type de retour' if ret and not en else (' with a return type' if ret else '')
        return (
            f'Définit la fonction <code>{name}</code>{extra} ; le corps va jusqu’au <code>end</code>.'
            if not en
            else f'Defines function <code>{name}</code>{extra}; body runs until <code>end</code>.'
        )

    if s.startswith('return ') or s.startswith('retourner '):
        return (
            'Renvoie une valeur au caller et quitte la fonction.'
            if not en
            else 'Returns a value to the caller and exits the function.'
        )

    if s.startswith('class ') or s.startswith('classe '):
        name = s.split()[1]
        return (
            f'Déclare la classe <code>{name}</code> (champs + méthodes jusqu’au <code>end</code>).'
            if not en
            else f'Declares class <code>{name}</code> (fields + methods until <code>end</code>).'
        )

    if s.startswith('interface '):
        name = s.split()[1]
        return (
            f'Définit le contrat <code>{name}</code> (signatures sans corps).'
            if not en
            else f'Defines contract <code>{name}</code> (signatures without bodies).'
        )

    if ' implements ' in s:
        return (
            'La classe s’engage à fournir toutes les méthodes de l’interface.'
            if not en
            else 'The class must provide every method of the interface.'
        )

    if ' extends ' in s:
        return (
            'Héritage : la classe fille spécialise un parent.'
            if not en
            else 'Inheritance: the child class specializes a parent.'
        )

    if s.startswith('public field ') or s.startswith('private field ') or s.startswith('protected field '):
        return (
            'Déclare un champ d’instance (visibilité public/private/protected).'
            if not en
            else 'Declares an instance field (public/private/protected visibility).'
        )

    if s.startswith('function init(') or s.startswith('fonction init('):
        return (
            'Constructeur <code>init</code> : appelé par <code>new Classe(…)</code>.'
            if not en
            else 'Constructor <code>init</code>: called by <code>new Class(…)</code>.'
        )

    if s.startswith('enum ') or s.startswith('union '):
        kind = 'enum' if s.startswith('enum ') else 'union'
        name = s.split()[1]
        return (
            f'Déclare le type somme <code>{kind} {name}</code> (cas nommés).'
            if not en
            else f'Declares sum type <code>{kind} {name}</code> (named cases).'
        )

    if s.startswith('case '):
        if ' with ' in s:
            return (
                'Cas avec payload : les champs après <code>with</code> sont liés à des variables.'
                if not en
                else 'Case with payload: fields after <code>with</code> bind to variables.'
            )
        return (
            'Une branche de <code>match</code> / un cas d’enum.'
            if not en
            else 'A <code>match</code> arm / enum case.'
        )

    if s.startswith('match '):
        return (
            'Démarre un <code>match</code> : choix d’une branche selon la forme de la valeur.'
            if not en
            else 'Starts a <code>match</code>: pick a branch by the value’s shape.'
        )

    if s.startswith('default'):
        return (
            'Branche fourre-tout si aucun <code>case</code> ne correspond.'
            if not en
            else 'Catch-all branch when no <code>case</code> matches.'
        )

    if s.startswith('macro ') or s.startswith('macrocommande '):
        return (
            'Définit une macro (modèle de code expansé avant compilation).'
            if not en
            else 'Defines a macro (code template expanded before compilation).'
        )

    if '!' in s and '(' in s and not s.startswith('if '):
        # likely macro call name!(...)
        if re.search(r'\w+!\(', s):
            return (
                'Appel de macro : le <code>!</code> déclenche l’expansion.'
                if not en
                else 'Macro call: <code>!</code> triggers expansion.'
            )

    if s.startswith('generator function') or s.startswith('generator fonction'):
        return (
            'Fonction générateur : produit des valeurs avec <code>yield</code> (paresseux).'
            if not en
            else 'Generator function: produces values with <code>yield</code> (lazy).'
        )

    if s.startswith('yield '):
        return (
            'Produit une valeur et suspend le générateur jusqu’à l’itération suivante.'
            if not en
            else 'Yields one value and suspends the generator until the next iteration.'
        )

    if s.startswith('try') or s.startswith('essayer'):
        return (
            'Bloc protégé : si une exception est levée, le flux saute au <code>catch</code>.'
            if not en
            else 'Protected block: if an exception is raised, control jumps to <code>catch</code>.'
        )

    if s.startswith('raise ') or s.startswith('lever '):
        return (
            'Lève une exception (interruption du flux normal).'
            if not en
            else 'Raises an exception (interrupts normal flow).'
        )

    if s.startswith('catch ') or s.startswith('rescue ') or s.startswith('attraper '):
        return (
            'Récupère l’erreur et permet de l’afficher ou de la traiter.'
            if not en
            else 'Catches the error so you can print or handle it.'
        )

    if s.startswith('import '):
        return (
            'Charge un module (stdlib, paquet ou fichier) depuis un chemin.'
            if not en
            else 'Loads a module (stdlib, package, or file) from a path.'
        )

    if s.startswith('use ') or s.startswith('utiliser '):
        return (
            'Importe les symboles exportés du module dans la portée courante.'
            if not en
            else 'Brings the module’s exported symbols into the current scope.'
        )

    if s.startswith('module '):
        return (
            'Ouvre un module nommé (API via <code>export</code>, reste privé sinon).'
            if not en
            else 'Opens a named module (API via <code>export</code>, otherwise private).'
        )

    if s.startswith('export '):
        return (
            'Rend une fonction/classe visible depuis l’extérieur du module.'
            if not en
            else 'Makes a function/class visible outside the module.'
        )

    if s.startswith('assert '):
        return (
            'Vérifie une condition ; échoue le test si elle est fausse.'
            if not en
            else 'Checks a condition; fails the test if it is false.'
        )

    if ' map each ' in s or s.startswith('map each '):
        return (
            'Transforme chaque élément et construit une nouvelle liste (<code>map</code>).'
            if not en
            else 'Transforms each item into a new list (<code>map</code>).'
        )

    if ' filter each ' in s or s.startswith('filter each '):
        return (
            'Ne garde que les éléments qui satisfont la condition (<code>filter</code>).'
            if not en
            else 'Keeps only items that satisfy the condition (<code>filter</code>).'
        )

    if s.startswith('reduce ') or ' reduce ' in s:
        return (
            'Agrège la liste en une seule valeur à partir d’un accumulateur initial.'
            if not en
            else 'Folds the list into one value from an initial accumulator.'
        )

    if ' or else ' in s:
        return (
            'Fournit une valeur de repli si l’optionnel/Result est vide ou en erreur.'
            if not en
            else 'Provides a fallback if the optional/Result is empty or an error.'
        )

    if ' or return' in s:
        return (
            'Propage l’erreur Result hors de la fonction (<code>or return</code>).'
            if not en
            else 'Propagates the Result error out of the function (<code>or return</code>).'
        )

    if ' or raise' in s:
        return (
            'Convertit une erreur Result en exception (<code>or raise</code>).'
            if not en
            else 'Turns a Result error into an exception (<code>or raise</code>).'
        )

    if re.search(r'\d+\.\.<\d+', s) or re.search(r'\d+\.\.\d+', s):
        return (
            'Utilise un littéral de plage (<code>a..b</code> inclusif, <code>a..&lt;b</code> exclusif).'
            if not en
            else 'Uses a range literal (<code>a..b</code> inclusive, <code>a..&lt;b</code> exclusive).'
        )

    if s.startswith('operator '):
        return (
            'Surcharge d’opérateur : définit le comportement de <code>+</code>, <code>==</code>, etc. sur la classe.'
            if not en
            else 'Operator overload: defines how <code>+</code>, <code>==</code>, etc. behave on the class.'
        )

    if s.startswith('where ') or ' where T ' in s:
        return (
            'Contrainte générique : restreint le paramètre de type <code>T</code>.'
            if not en
            else 'Generic constraint: restricts type parameter <code>T</code>.'
        )

    if s == 'end' or s == 'fin':
        return None  # trop bruyant

    return None

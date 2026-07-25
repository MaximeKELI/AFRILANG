"""Politique de confidentialité AFRILANG — contenu bilingue ultra détaillé."""

from django.utils.safestring import mark_safe

PRIVACY_VERSION = '1'
PRIVACY_LAST_UPDATED = {
    'fr': '25 juillet 2026',
    'en': '25 July 2026',
}


def _h2(text):
    return {'type': 'h2', 'text': text}


def _h3(text):
    return {'type': 'h3', 'text': text}


def _p(html):
    return {'type': 'p', 'html': mark_safe(html)}


def _ul(items):
    return {'type': 'ul', 'items': [mark_safe(i) for i in items]}


def _table(headers, rows):
    return {'type': 'table', 'headers': headers, 'rows': rows}


def _callout(html, variant='info'):
    return {'type': 'callout', 'html': mark_safe(html), 'variant': variant}


def get_privacy_page(lang: str) -> dict:
    code = (lang or 'fr')[:2]
    if code == 'en':
        return {
            'slug': 'privacy',
            'title': 'Privacy Policy',
            'lead': (
                'This Privacy Policy explains how the AFRILANG official website '
                '(the “Site”) collects, uses, stores, shares and protects your '
                'personal data, and what rights you have.'
            ),
            'updated': PRIVACY_LAST_UPDATED['en'],
            'version': PRIVACY_VERSION,
            'blocks': _blocks_en(),
        }
    return {
        'slug': 'privacy',
        'title': 'Politique de confidentialité',
        'lead': (
            'La présente Politique de confidentialité décrit comment le site officiel '
            'AFRILANG (le « Site ») collecte, utilise, conserve, partage et protège '
            'vos données personnelles, ainsi que les droits dont vous disposez.'
        ),
        'updated': PRIVACY_LAST_UPDATED['fr'],
        'version': PRIVACY_VERSION,
        'blocks': _blocks_fr(),
    }


def get_privacy_summary(lang: str) -> list[str]:
    """Points clés affichés dans le portail de consentement."""
    if (lang or 'fr')[:2] == 'en':
        return [
            'We collect only what is needed to run the Site (session, language, playground).',
            'No advertising trackers and no sale of personal data.',
            'Playground code you submit may be processed temporarily to compile/run it.',
            'You can withdraw consent and exercise your GDPR rights at any time.',
            'Full details are in the Privacy Policy linked below.',
        ]
    return [
        'Nous ne collectons que le nécessaire au fonctionnement du Site (session, langue, playground).',
        'Pas de traceurs publicitaires et aucune vente de données personnelles.',
        'Le code soumis au playground peut être traité temporairement pour compilation/exécution.',
        'Vous pouvez retirer votre consentement et exercer vos droits RGPD à tout moment.',
        'Le détail complet figure dans la Politique de confidentialité ci-dessous.',
    ]


def _blocks_fr():
    return [
        _callout(
            '<strong>Consentement préalable</strong> — L’accès plein au Site est '
            'conditionné à l’acceptation explicite de cette Politique. '
            'Sans acceptation, seules la présente page et les ressources techniques '
            'strictement nécessaires restent accessibles.'
        ),
        _p(
            f'<strong>Version</strong> {PRIVACY_VERSION} · '
            f'<strong>Dernière mise à jour</strong> : {PRIVACY_LAST_UPDATED["fr"]}.'
        ),
        _h2('1. Qui sommes-nous ? (responsable du traitement)'),
        _p(
            'Le responsable du traitement des données personnelles collectées via le Site '
            'est le <strong>mainteneur du projet open source AFRILANG</strong>, '
            'projet publié sur GitHub à l’adresse '
            '<a href="https://github.com/MaximeKELI/AFRILANG" rel="noopener noreferrer" '
            'target="_blank">github.com/MaximeKELI/AFRILANG</a>.'
        ),
        _p(
            'Pour toute question relative à la protection des données, vous pouvez '
            'contacter le mainteneur <strong>de manière privée</strong> via les canaux '
            'indiqués dans <code>SECURITY.md</code> du dépôt (ne pas ouvrir d’issue '
            'publique pour des sujets sensibles).'
        ),
        _ul([
            '<strong>Nom du service</strong> : Site web officiel AFRILANG',
            '<strong>Nature</strong> : site documentaire, tutoriel, playground en ligne, '
            'catalogue de paquets et de la bibliothèque standard',
            '<strong>Licence du logiciel</strong> : MIT (le code source AFRILANG) — '
            'distincte de la présente Politique applicable au Site',
        ]),
        _h2('2. Champ d’application'),
        _p(
            'Cette Politique s’applique à l’ensemble des pages et services du Site, '
            'notamment : documentation, tutoriel, playground (natif / WASM / JS), '
            'galerie d’exemples, catalogue stdlib, registre de paquets, pages de '
            'téléchargement, API documentaire, et bascule de langue FR/EN.'
        ),
        _p(
            'Elle ne régit pas :'
        ),
        _ul([
            'les dépôts tiers ou miroirs non opérés par le mainteneur AFRILANG ;',
            'les sites externes liés (GitHub, CDN Bootstrap, etc.), qui disposent '
            'de leurs propres politiques ;',
            'l’usage local du compilateur AFRILANG installé sur votre machine '
            '(hors Site web).',
        ]),
        _h2('3. Définitions'),
        _ul([
            '<strong>Donnée personnelle</strong> : toute information se rapportant '
            'à une personne physique identifiée ou identifiable (RGPD art. 4).',
            '<strong>Traitement</strong> : toute opération sur des données '
            '(collecte, stockage, consultation, transmission, effacement, etc.).',
            '<strong>Sous-traitant</strong> : prestataire traitant des données '
            'pour le compte du responsable (hébergeur, CDN, etc.).',
            '<strong>Consentement</strong> : manifestation de volonté libre, '
            'spécifique, éclairée et univoque (case à cocher + bouton d’acceptation).',
        ]),
        _h2('4. Données que nous collectons'),
        _h3('4.1. Données collectées automatiquement'),
        _p(
            'Lors de votre visite, des données techniques peuvent être traitées '
            'de façon limitée pour assurer la sécurité et le fonctionnement du Site :'
        ),
        _table(
            ['Catégorie', 'Exemples', 'Finalité'],
            [
                [
                    'Journalisation technique',
                    'Adresse IP (éventuellement tronquée selon config hébergeur), '
                    'horodatage, URL demandée, code HTTP, user-agent',
                    'Sécurité, diagnostic d’incidents, prévention d’abus',
                ],
                [
                    'Session HTTP',
                    'Identifiant de session Django, jeton CSRF',
                    'Maintien de session, protection contre les attaques CSRF',
                ],
                [
                    'Préférence de langue',
                    'Cookie / session de locale (<code>fr</code> / <code>en</code>)',
                    'Afficher l’interface dans la langue choisie',
                ],
            ],
        ),
        _h3('4.2. Données liées au playground et aux API'),
        _p(
            'Si vous utilisez le playground ou certaines API du Site :'
        ),
        _ul([
            '<strong>Code source AFRILANG</strong> que vous saisissez ou chargez '
            '(exemples, projets) — traité pour compilation, exécution sandboxée '
            'ou transpilation WASM/JS ;',
            '<strong>métadonnées d’exécution</strong> éventuelles (succès/échec, '
            'durée, messages d’erreur) pour le fonctionnement du service et la '
            'limitation de débit (anti-abus) ;',
            '<strong>empreinte technique</strong> liée au rate-limiting '
            '(ex. association temporaire IP / jeton de session).',
        ]),
        _callout(
            '<strong>Important</strong> — Ne soumettez pas de secrets (mots de passe, '
            'clés API, données de santé, données bancaires, données de tiers) dans '
            'le playground. Tout code soumis est traité comme potentiellement public '
            'et non confidentiel.',
            'warning',
        ),
        _h3('4.3. Données stockées localement sur votre appareil'),
        _p(
            'Le Site utilise le stockage local du navigateur (<code>localStorage</code>) '
            'pour :'
        ),
        _ul([
            f'<strong>Consentement à la Politique</strong> '
            f'(clé <code>afr_privacy_consent</code>, version {PRIVACY_VERSION}) ;',
            '<strong>Thème</strong> clair/sombre (<code>afr_theme</code>) ;',
            '<strong>Progression tutoriel</strong> éventuelle (<code>afr_tutorial_done</code>) ;',
            'éventuellement d’anciennes préférences cookies (<code>afr_cookie_consent</code>).',
        ]),
        _p(
            'Ces données restent sur votre appareil ; elles ne sont pas automatiquement '
            'envoyées au serveur, sauf si une fonctionnalité le nécessite explicitement.'
        ),
        _h3('4.4. Données que nous ne collectons pas (par défaut)'),
        _ul([
            'identité civile (nom, prénom) obligatoire ;',
            'adresse e-mail obligatoire pour naviguer ;',
            'données de paiement ;',
            'géolocalisation précise ;',
            'profils publicitaires, fingerprinting marketing, pixels de tracking tiers ;',
            'vente ou location de fichiers d’utilisateurs.',
        ]),
        _h2('5. Finalités et bases légales (RGPD)'),
        _table(
            ['Finalité', 'Base légale', 'Données concernées'],
            [
                [
                    'Fournir le Site et ses fonctionnalités (docs, playground, etc.)',
                    'Exécution de mesures précontractuelles / intérêt légitime '
                    '(art. 6.1.b / 6.1.f) et, pour l’accès après information, '
                    '<strong>consentement</strong> (art. 6.1.a)',
                    'Session, logs techniques, code playground',
                ],
                [
                    'Mémoriser langue, thème, consentement',
                    'Consentement et/ou intérêt légitime (fonctionnalité demandée)',
                    'localStorage, cookie de langue',
                ],
                [
                    'Sécurité, anti-abus, rate-limiting',
                    'Intérêt légitime (art. 6.1.f)',
                    'IP, logs, métadonnées d’exécution',
                ],
                [
                    'Amélioration du service (stats agrégées éventuelles)',
                    'Intérêt légitime — uniquement données agrégées / anonymisées '
                    'lorsqu’elles existent',
                    'Compteurs, métriques techniques',
                ],
                [
                    'Répondre à une obligation légale',
                    'Obligation légale (art. 6.1.c)',
                    'Selon la demande d’autorité compétente',
                ],
            ],
        ),
        _h2('6. Cookies et technologies similaires'),
        _h3('6.1. Cookies strictement nécessaires'),
        _p(
            'Ces cookies (ou équivalents) sont requis pour le fonctionnement du Site '
            'et ne peuvent être désactivés via le bandeau sans casser des fonctions '
            'essentielles :'
        ),
        _ul([
            '<strong>Session Django</strong> — maintien de la session serveur ;',
            '<strong>CSRF</strong> — protection des formulaires et API navigateur ;',
            '<strong>Locale / langue</strong> — mémorisation FR ou EN.',
        ]),
        _h3('6.2. Stockage local et consentement'),
        _p(
            'Le consentement à la présente Politique est enregistré dans '
            '<code>localStorage</code> sous une forme versionnée. '
            'Si nous mettons à jour la Politique de façon substantielle '
            f'(nouvelle version &gt; {PRIVACY_VERSION}), un nouveau consentement '
            'pourra vous être redemandé.'
        ),
        _h3('6.3. Cookies tiers'),
        _p(
            'Le Site peut charger des ressources depuis des CDN (ex. Bootstrap) '
            'pour la présentation. Ces prestataires peuvent recevoir votre adresse IP '
            'dans le cadre d’une requête HTTP classique. Nous ne déployons pas '
            'volontairement de cookies publicitaires tiers.'
        ),
        _h2('7. Playground : traitement du code soumis'),
        _p(
            'Le playground est un service d’exécution / compilation à distance ou '
            'dans le navigateur. Lorsque vous cliquez sur « Run » (ou équivalent) :'
        ),
        _ul([
            'votre code est transmis au serveur et/ou traité localement (WASM/JS) ;',
            'il peut être écrit dans des fichiers temporaires isolés, compilé, exécuté '
            'sous contraintes de sécurité (sandbox, limites CPU/mémoire) ;',
            'les artefacts temporaires sont destinés à être effacés après usage '
            'selon la configuration du service ;',
            'des enregistrements techniques (succès, erreur, durée) peuvent être '
            'conservés brièvement pour la stabilité et la sécurité du service.',
        ]),
        _p(
            'Le mainteneur ne revendique aucun droit de propriété intellectuelle '
            'sur le code que vous saisissez dans le playground, mais vous garantissez '
            'disposer des droits nécessaires pour le soumettre et qu’il ne viole '
            'pas la loi ni les droits de tiers.'
        ),
        _h2('8. Destinataires et sous-traitants'),
        _p(
            'Vos données peuvent être traitées par :'
        ),
        _ul([
            'le mainteneur AFRILANG et les contributeurs techniques autorisés '
            'ayant besoin d’y accéder pour l’exploitation du Site ;',
            'l’<strong>hébergeur</strong> de l’infrastructure (serveur web, base de '
            'données, journaux) — sous-traitant au sens du RGPD ;',
            'éventuellement des <strong>CDN</strong> pour assets statiques ;',
            'autorités compétentes uniquement sur réquisition légale valide.',
        ]),
        _p(
            'Nous ne vendons pas vos données personnelles et ne les partageons pas '
            'à des fins de marketing tiers.'
        ),
        _h2('9. Transferts hors Union européenne'),
        _p(
            'Selon l’hébergement choisi pour le Site, des données techniques '
            '(notamment logs et IP) peuvent être traitées hors de l’Espace '
            'économique européen. Dans ce cas, nous veillons à ce que des garanties '
            'appropriées soient en place (ex. clauses contractuelles types, '
            'pays reconnu adéquat, ou mesures équivalentes), dans la mesure '
            'applicable à un projet open source auto-hébergé / hébergé chez un '
            'prestataire.'
        ),
        _p(
            'GitHub (liens externes, issues) est un service tiers soumis à ses '
            'propres conditions ; toute interaction sur GitHub n’est pas régie '
            'uniquement par la présente Politique.'
        ),
        _h2('10. Durées de conservation'),
        _table(
            ['Donnée', 'Durée indicative'],
            [
                ['Consentement (localStorage)', 'Jusqu’à suppression manuelle ou nouvelle version'],
                ['Session / CSRF', 'Durée de la session navigateur / expiration serveur'],
                ['Logs serveur', 'Courte durée technique (typiquement jours à quelques semaines), sauf incident de sécurité'],
                ['Code playground / fichiers temp.', 'Durée du traitement + purge automatique'],
                ['Métriques agrégées', 'Aussi longtemps qu’elles restent anonymes / non identifiantes'],
            ],
        ),
        _h2('11. Sécurité'),
        _p(
            'Nous mettons en œuvre des mesures raisonnables au regard de l’état '
            'de l’art et de la nature du projet :'
        ),
        _ul([
            'protection CSRF sur les requêtes navigateur ;',
            'en-têtes de sécurité HTTP (middleware dédié) ;',
            'limitation de débit sur le playground ;',
            'exécution sandboxée / contraintes ressources pour le code non fiable '
            '(voir aussi la politique de sécurité du compilateur dans le dépôt) ;',
            'principe de minimisation : pas de compte utilisateur obligatoire '
            'pour consulter la documentation.',
        ]),
        _p(
            'Aucun système n’étant infaillible, en cas de violation de données '
            'susceptible d’engendrer un risque élevé pour vos droits et libertés, '
            'nous prendrons les mesures d’information prévues par la réglementation '
            'applicable, dans la mesure où elles concernent ce Site.'
        ),
        _h2('12. Vos droits'),
        _p(
            'Conformément au RGPD (et, le cas échéant, à la loi Informatique et '
            'Libertés), vous disposez des droits suivants :'
        ),
        _ul([
            '<strong>Accès</strong> — obtenir confirmation qu’un traitement existe '
            'et en recevoir une copie ;',
            '<strong>Rectification</strong> — corriger des données inexactes ;',
            '<strong>Effacement</strong> (« droit à l’oubli ») — dans les cas prévus ;',
            '<strong>Limitation</strong> — demander le gel temporaire du traitement ;',
            '<strong>Opposition</strong> — vous opposer à certains traitements '
            'fondés sur l’intérêt légitime ;',
            '<strong>Portabilité</strong> — lorsque applicable (données fournies '
            'et traitées de façon automatisée sur base contractuelle/consentement) ;',
            '<strong>Retrait du consentement</strong> — à tout moment, sans affecter '
            'la licéité du traitement antérieur ;',
            '<strong>Directive post-mortem</strong> (France) — définir le sort '
            'de vos données après votre décès, le cas échéant.',
        ]),
        _p(
            'Pour exercer vos droits : contactez le mainteneur via le canal privé '
            'indiqué dans <code>SECURITY.md</code> / le dépôt GitHub, en précisant '
            'l’objet « Données personnelles — AFRILANG Site ». '
            'Nous pourrons demander des informations raisonnables pour vérifier '
            'votre identité lorsque cela est nécessaire.'
        ),
        _p(
            'Vous pouvez également introduire une réclamation auprès de la '
            '<strong>CNIL</strong> (France) — '
            '<a href="https://www.cnil.fr" rel="noopener noreferrer" target="_blank">www.cnil.fr</a> — '
            'ou auprès de l’autorité de contrôle de votre pays de résidence '
            'dans l’UE/EEE.'
        ),
        _h2('13. Mineurs'),
        _p(
            'Le Site présente un langage de programmation éducatif et technique. '
            'Il n’est pas destiné à collecter sciemment des données de mineurs '
            'de moins de 15 ans (ou de l’âge numérique localement applicable) '
            'sans consentement parental lorsque la loi l’exige. '
            'Si vous êtes parent ou tuteur et pensez qu’un mineur nous a transmis '
            'des données, contactez-nous pour suppression.'
        ),
        _h2('14. Contenu généré et responsabilité de l’utilisateur'),
        _ul([
            'Vous êtes responsable du code et des textes que vous soumettez ;',
            'vous vous engagez à ne pas utiliser le playground pour des activités '
            'illicites, attentatoires à la sécurité d’autrui, ou visant à contourner '
            'les protections du service ;',
            'le mainteneur peut suspendre l’accès au playground en cas d’abus '
            '(flood, exploitation, malware, etc.).',
        ]),
        _h2('15. Liens externes'),
        _p(
            'Le Site contient des liens vers des ressources externes (GitHub, '
            'documentation tierce, CDN). Nous ne contrôlons pas ces sites et '
            'déclinons toute responsabilité quant à leurs pratiques de '
            'confidentialité. Consultez leurs politiques avant d’y interagir.'
        ),
        _h2('16. Modifications de la Politique'),
        _p(
            'Nous pouvons mettre à jour cette Politique pour refléter des '
            'évolutions légales, techniques ou organisationnelles. '
            'La date de « dernière mise à jour » et le numéro de version seront '
            'révisés. En cas de changement substantiel, un nouveau consentement '
            'pourra être requis avant de continuer à utiliser pleinement le Site.'
        ),
        _h2('17. Droit applicable'),
        _p(
            'Sous réserve de dispositions impératives contraires, la présente '
            'Politique est interprétée conformément au droit applicable en France '
            'et au Règlement (UE) 2016/679 (RGPD), sans préjudice des droits '
            'dont vous disposez dans votre État de résidence.'
        ),
        _h2('18. Contact'),
        _p(
            'Projet : <strong>AFRILANG</strong><br>'
            'Dépôt : <a href="https://github.com/MaximeKELI/AFRILANG" '
            'rel="noopener noreferrer" target="_blank">github.com/MaximeKELI/AFRILANG</a><br>'
            'Sécurité / données sensibles : canal privé décrit dans '
            '<code>SECURITY.md</code>.'
        ),
        _callout(
            'En cochant la case et en cliquant sur « J’accepte » sur l’écran '
            'd’entrée, vous confirmez avoir lu cette Politique et consentir '
            'au traitement décrit pour l’utilisation du Site.'
        ),
    ]


def _blocks_en():
    return [
        _callout(
            '<strong>Prior consent</strong> — Full access to the Site requires '
            'explicit acceptance of this Policy. Without acceptance, only this '
            'page and strictly necessary technical resources remain available.'
        ),
        _p(
            f'<strong>Version</strong> {PRIVACY_VERSION} · '
            f'<strong>Last updated</strong>: {PRIVACY_LAST_UPDATED["en"]}.'
        ),
        _h2('1. Who we are (data controller)'),
        _p(
            'The controller of personal data collected via the Site is the '
            '<strong>maintainer of the AFRILANG open-source project</strong>, '
            'published on GitHub at '
            '<a href="https://github.com/MaximeKELI/AFRILANG" rel="noopener noreferrer" '
            'target="_blank">github.com/MaximeKELI/AFRILANG</a>.'
        ),
        _p(
            'For privacy questions, contact the maintainer <strong>privately</strong> '
            'using the channels described in the repository’s <code>SECURITY.md</code> '
            '(do not open public issues for sensitive matters).'
        ),
        _ul([
            '<strong>Service name</strong>: Official AFRILANG website',
            '<strong>Nature</strong>: documentation, tutorial, online playground, '
            'package and standard-library catalogue',
            '<strong>Software license</strong>: MIT (AFRILANG source) — distinct '
            'from this Policy, which applies to the Site',
        ]),
        _h2('2. Scope'),
        _p(
            'This Policy applies to all Site pages and services, including: '
            'documentation, tutorial, playground (native / WASM / JS), example '
            'gallery, stdlib catalogue, package registry, downloads, API docs, '
            'and FR/EN language switching.'
        ),
        _p('It does not cover:'),
        _ul([
            'third-party repositories or mirrors not operated by the AFRILANG maintainer;',
            'external linked sites (GitHub, CDNs, etc.), which have their own policies;',
            'local use of the AFRILANG compiler installed on your machine '
            '(outside the website).',
        ]),
        _h2('3. Definitions'),
        _ul([
            '<strong>Personal data</strong>: any information relating to an '
            'identified or identifiable natural person (GDPR Art. 4).',
            '<strong>Processing</strong>: any operation on data (collection, '
            'storage, access, transfer, erasure, etc.).',
            '<strong>Processor</strong>: a provider processing data on behalf '
            'of the controller (hosting, CDN, etc.).',
            '<strong>Consent</strong>: a freely given, specific, informed and '
            'unambiguous indication of wishes (checkbox + accept button).',
        ]),
        _h2('4. Data we collect'),
        _h3('4.1. Data collected automatically'),
        _p(
            'When you visit, limited technical data may be processed for security '
            'and Site operation:'
        ),
        _table(
            ['Category', 'Examples', 'Purpose'],
            [
                [
                    'Technical logs',
                    'IP address (possibly truncated depending on host config), '
                    'timestamp, requested URL, HTTP status, user-agent',
                    'Security, incident diagnostics, abuse prevention',
                ],
                [
                    'HTTP session',
                    'Django session id, CSRF token',
                    'Session continuity, CSRF protection',
                ],
                [
                    'Language preference',
                    'Locale cookie/session (<code>fr</code> / <code>en</code>)',
                    'Show the UI in the chosen language',
                ],
            ],
        ),
        _h3('4.2. Playground and API-related data'),
        _p('If you use the playground or certain Site APIs:'),
        _ul([
            '<strong>AFRILANG source code</strong> you type or load — processed '
            'for compilation, sandboxed execution or WASM/JS transpilation;',
            '<strong>execution metadata</strong> (success/failure, duration, '
            'error messages) for service operation and rate limiting;',
            '<strong>technical fingerprint</strong> related to rate limiting '
            '(e.g. temporary IP / session association).',
        ]),
        _callout(
            '<strong>Important</strong> — Do not submit secrets (passwords, API keys, '
            'health data, banking data, third-party data) in the playground. '
            'Submitted code is treated as potentially public and non-confidential.',
            'warning',
        ),
        _h3('4.3. Data stored locally on your device'),
        _p(
            'The Site uses browser <code>localStorage</code> for:'
        ),
        _ul([
            f'<strong>Policy consent</strong> '
            f'(key <code>afr_privacy_consent</code>, version {PRIVACY_VERSION});',
            '<strong>Theme</strong> light/dark (<code>afr_theme</code>);',
            '<strong>Tutorial progress</strong> if any (<code>afr_tutorial_done</code>);',
            'possibly legacy cookie preferences (<code>afr_cookie_consent</code>).',
        ]),
        _p(
            'These data remain on your device; they are not automatically sent '
            'to the server unless a feature explicitly requires it.'
        ),
        _h3('4.4. Data we do not collect by default'),
        _ul([
            'mandatory civil identity (name);',
            'mandatory email to browse;',
            'payment data;',
            'precise geolocation;',
            'ad profiles, marketing fingerprinting, third-party tracking pixels;',
            'sale or rental of user lists.',
        ]),
        _h2('5. Purposes and legal bases (GDPR)'),
        _table(
            ['Purpose', 'Legal basis', 'Data concerned'],
            [
                [
                    'Provide the Site and its features (docs, playground, etc.)',
                    'Pre-contractual steps / legitimate interest '
                    '(Art. 6.1.b / 6.1.f) and, for access after information, '
                    '<strong>consent</strong> (Art. 6.1.a)',
                    'Session, technical logs, playground code',
                ],
                [
                    'Remember language, theme, consent',
                    'Consent and/or legitimate interest (requested feature)',
                    'localStorage, language cookie',
                ],
                [
                    'Security, anti-abuse, rate limiting',
                    'Legitimate interest (Art. 6.1.f)',
                    'IP, logs, execution metadata',
                ],
                [
                    'Service improvement (optional aggregated stats)',
                    'Legitimate interest — only aggregated/anonymised data when present',
                    'Counters, technical metrics',
                ],
                [
                    'Comply with a legal obligation',
                    'Legal obligation (Art. 6.1.c)',
                    'As required by a competent authority',
                ],
            ],
        ),
        _h2('6. Cookies and similar technologies'),
        _h3('6.1. Strictly necessary cookies'),
        _p(
            'These cookies (or equivalents) are required for Site operation:'
        ),
        _ul([
            '<strong>Django session</strong> — server session;',
            '<strong>CSRF</strong> — form and browser API protection;',
            '<strong>Locale / language</strong> — remember FR or EN.',
        ]),
        _h3('6.2. Local storage and consent'),
        _p(
            'Consent to this Policy is stored in <code>localStorage</code> '
            'in a versioned form. If we substantially update the Policy '
            f'(new version &gt; {PRIVACY_VERSION}), renewed consent may be required.'
        ),
        _h3('6.3. Third-party cookies'),
        _p(
            'The Site may load assets from CDNs (e.g. Bootstrap). Those providers '
            'may receive your IP as part of a normal HTTP request. We do not '
            'intentionally deploy third-party advertising cookies.'
        ),
        _h2('7. Playground: processing of submitted code'),
        _p(
            'When you click “Run” (or equivalent):'
        ),
        _ul([
            'your code is sent to the server and/or processed locally (WASM/JS);',
            'it may be written to isolated temporary files, compiled and executed '
            'under security constraints (sandbox, CPU/memory limits);',
            'temporary artefacts are intended to be deleted after use according '
            'to service configuration;',
            'technical records (success, error, duration) may be kept briefly '
            'for stability and security.',
        ]),
        _p(
            'The maintainer claims no intellectual-property rights over code you '
            'type in the playground, but you warrant that you have the rights to '
            'submit it and that it does not violate law or third-party rights.'
        ),
        _h2('8. Recipients and processors'),
        _p('Your data may be processed by:'),
        _ul([
            'the AFRILANG maintainer and authorised technical contributors '
            'who need access to operate the Site;',
            'the <strong>hosting provider</strong> (web server, database, logs) '
            '— a processor under the GDPR;',
            'possibly <strong>CDNs</strong> for static assets;',
            'competent authorities only upon a valid legal request.',
        ]),
        _p(
            'We do not sell your personal data or share it for third-party marketing.'
        ),
        _h2('9. Transfers outside the European Union'),
        _p(
            'Depending on Site hosting, technical data (including logs and IP) '
            'may be processed outside the EEA. Where applicable, we seek appropriate '
            'safeguards (e.g. standard contractual clauses, adequacy decision, '
            'or equivalent measures) for an open-source project hosted with a provider.'
        ),
        _p(
            'GitHub (external links, issues) is a third-party service with its own '
            'terms; interactions on GitHub are not governed solely by this Policy.'
        ),
        _h2('10. Retention periods'),
        _table(
            ['Data', 'Indicative period'],
            [
                ['Consent (localStorage)', 'Until manual deletion or new version'],
                ['Session / CSRF', 'Browser session / server expiry'],
                ['Server logs', 'Short technical period (typically days to a few weeks), except security incidents'],
                ['Playground code / temp files', 'Processing duration + automatic purge'],
                ['Aggregated metrics', 'As long as they remain anonymous / non-identifying'],
            ],
        ),
        _h2('11. Security'),
        _p(
            'We implement reasonable measures given the state of the art and '
            'the nature of the project:'
        ),
        _ul([
            'CSRF protection for browser requests;',
            'HTTP security headers (dedicated middleware);',
            'playground rate limiting;',
            'sandboxed execution / resource limits for untrusted code '
            '(see also the compiler security policy in the repository);',
            'data minimisation: no mandatory user account to read documentation.',
        ]),
        _p(
            'No system is infallible. If a personal-data breach is likely to '
            'result in a high risk to your rights and freedoms, we will take '
            'the notification steps required by applicable law for this Site.'
        ),
        _h2('12. Your rights'),
        _p(
            'Under the GDPR (and, where applicable, French data-protection law), '
            'you have the following rights:'
        ),
        _ul([
            '<strong>Access</strong> — confirmation that processing exists and a copy;',
            '<strong>Rectification</strong> — correct inaccurate data;',
            '<strong>Erasure</strong> (“right to be forgotten”) — where applicable;',
            '<strong>Restriction</strong> — temporary freeze of processing;',
            '<strong>Objection</strong> — object to certain legitimate-interest processing;',
            '<strong>Portability</strong> — where applicable;',
            '<strong>Withdraw consent</strong> — at any time, without affecting '
            'prior lawful processing;',
            '<strong>Post-mortem directives</strong> (France) — where applicable.',
        ]),
        _p(
            'To exercise your rights: contact the maintainer via the private channel '
            'in <code>SECURITY.md</code> / the GitHub repository, with subject '
            '“Personal data — AFRILANG Site”. We may request reasonable information '
            'to verify your identity when necessary.'
        ),
        _p(
            'You may also lodge a complaint with the French '
            '<strong>CNIL</strong> — '
            '<a href="https://www.cnil.fr" rel="noopener noreferrer" target="_blank">www.cnil.fr</a> — '
            'or with your local EU/EEA supervisory authority.'
        ),
        _h2('13. Minors'),
        _p(
            'The Site presents an educational/technical programming language. '
            'It is not intended to knowingly collect data from children under 15 '
            '(or the locally applicable digital age) without parental consent where '
            'required by law. If you are a parent/guardian and believe a minor '
            'provided data, contact us for deletion.'
        ),
        _h2('14. User-generated content and responsibility'),
        _ul([
            'You are responsible for code and text you submit;',
            'you must not use the playground for unlawful activity, harming others’ '
            'security, or bypassing service protections;',
            'the maintainer may suspend playground access in case of abuse '
            '(flooding, exploitation, malware, etc.).',
        ]),
        _h2('15. External links'),
        _p(
            'The Site links to external resources (GitHub, third-party docs, CDNs). '
            'We do not control those sites and are not responsible for their privacy '
            'practices. Review their policies before interacting with them.'
        ),
        _h2('16. Changes to this Policy'),
        _p(
            'We may update this Policy to reflect legal, technical or organisational '
            'changes. The “last updated” date and version number will be revised. '
            'For material changes, renewed consent may be required before continued '
            'full use of the Site.'
        ),
        _h2('17. Governing law'),
        _p(
            'Subject to mandatory provisions otherwise, this Policy is interpreted '
            'under applicable French law and Regulation (EU) 2016/679 (GDPR), '
            'without prejudice to rights you have in your country of residence.'
        ),
        _h2('18. Contact'),
        _p(
            'Project: <strong>AFRILANG</strong><br>'
            'Repository: <a href="https://github.com/MaximeKELI/AFRILANG" '
            'rel="noopener noreferrer" target="_blank">github.com/MaximeKELI/AFRILANG</a><br>'
            'Security / sensitive data: private channel described in '
            '<code>SECURITY.md</code>.'
        ),
        _callout(
            'By checking the box and clicking “I accept” on the entry screen, '
            'you confirm that you have read this Policy and consent to the '
            'processing described for use of the Site.'
        ),
    ]

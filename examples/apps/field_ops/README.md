# field_ops — vitrine A + B

Preuve produit du positionnement AFRILANG :

- **A** — règles métier lisibles (`src/rules.afr`) compilées en binaire natif
- **B** — vertical offline Afrique : `moneyx` · `phonex` · `geox` · `storex`

## Scénario

Agent terrain près d’une clinique (Lomé) : encaissement mobile money SN.

| Règle | Comportement |
|-------|----------------|
| Zone | dans 30 km de la clinique |
| Téléphone | mobile Sénégal (E.164 via `phonex`) |
| Plafond | ≤ 50 000 XOF |
| Frais | 25 XOF + 1,5 % (`moneyx`) |
| Persistance | SQLite local (`storex`) — pas de cloud requis |

## Lancer

```bash
cd examples/apps/field_ops
afrilang pkg install
afrilang run src/main.afr
# ou : afrilang build && ./build/field_ops
```

Dépendances en `path` vers `packages/` du monorepo (pas de réseau).

## Tests

```bash
afrilang pkg install
afrilang test
# ou depuis la racine du repo :
bash scripts/check_field_ops.sh
```


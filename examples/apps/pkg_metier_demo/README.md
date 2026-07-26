# pkg_metier_demo

Démo des paquets métier AFRILANG (vagues 1 et 2).

| Paquet | Rôle |
|--------|------|
| `httpx` | Client HTTP/JSON |
| `geox` | Distances haversine |
| `datax` | CSV / JSON fichiers |
| `webapi` | Router JSON `/health` |
| `deployx` | Procfile / health URL |
| `storex` | SQLite léger |
| `apiclient` | Retry / backoff HTTP |
| `places` | Nominatim / OSM helpers |
| `moneyx` | XOF / frais mobile money |
| `csvtable` | Cellules / lignes CSV |

```bash
cd examples/apps/pkg_metier_demo
afrilang pkg install
afrilang run src/main.afr          # vague 1
afrilang run src/metier2_demo.afr  # vague 2
afrilang run src/storex_demo.afr   # storex seul
```

# pkg_metier_demo

Démo des paquets métier AFRILANG :

| Paquet | Rôle |
|--------|------|
| `httpx` | Client HTTP/JSON |
| `geox` | Distances haversine |
| `datax` | CSV / JSON fichiers |
| `webapi` | Router JSON `/health` |
| `deployx` | Procfile / health URL |
| `storex` | SQLite léger (démo séparée) |

```bash
cd examples/apps/pkg_metier_demo
afrilang pkg install
afrilang run src/main.afr          # httpx geox datax webapi deployx
afrilang run src/storex_demo.afr   # storex seul
```

Sans appels réseau (sauf si vous ajoutez `healthCheck` / `postJson`).

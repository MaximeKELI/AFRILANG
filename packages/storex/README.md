# storex

Mini **store SQLite** offline-first (`std/sql` + `std/orm`) : créer table, insert, lister.

## Usage

```afrilang
import "pkg/storex/storex.afr"
use storex

create db = "data/app.db"
ensureTable(db, "users", "id integer primary key, name text")
put(db, "users", cols1("name"), vals1("Ama"))
say listAll(db, "users")
```

## Notes

- `columns` / `values` pour `put` : champs séparés par `|` (contrat `std/orm`).
- Smoke utilise `/tmp/afrilang_storex_smoke.db`.

# datax

Helpers **CSV / JSON / fichiers** pour enquêtes, marchés, exports — `std/csv` + `std/fs` + `std/json`.

## Usage

```afrilang
import "pkg/datax/datax.afr"
use datax

create fields = parseCsvLine("ville,population")
create n = lineCount(readTextFile("data/marches.csv"))
saveJsonObject("/tmp/out.json", "status", "ok")
```

## Notes

- `joinCsvLine` gère les guillemets via le runtime CSV.
- Smoke écrit un JSON sous `/tmp`.

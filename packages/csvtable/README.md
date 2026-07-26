# csvtable

Helpers **table CSV** : lignes, en-tête, cellule `(row, col)` via `std/csv` + `std/str`.

## Usage

```afrilang
import "pkg/csvtable/csvtable.afr"
use csvtable

create csv = "ville,pop\nLome,2000000\nKara,100000"
say cell(csv, 1, 0)
say dataRowCount(csv)
```

Complète `datax` (fichiers) et `csvx` (échappement texte).

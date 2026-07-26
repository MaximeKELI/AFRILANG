# statsx

Stats / régression légère sur `std/stats` (moyenne, écart-type, linreg, moving average).

```afrilang
import "pkg/statsx/statsx.afr"
use statsx
create xs = list of 1, 2, 3
create ys = list of 2, 4, 6
say predict(xs, ys, 4)
```

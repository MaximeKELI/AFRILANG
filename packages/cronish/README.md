# cronish

Planification simple : `everyHours`, `nextDaily`, `isDue`, noms de jours (`std/datetime`).

```afrilang
import "pkg/cronish/cronish.afr"
use cronish
create t = parseStamp("2026-01-01T00:00:00Z")
say describeDaily(nextDaily(t))
```

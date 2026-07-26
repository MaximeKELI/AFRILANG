# moneyx

Helpers **XOF / CFA / mobile money** : arrondi, frais (fixe + %), partage, FX simple.

## Usage

```afrilang
import "pkg/moneyx/moneyx.afr"
use moneyx

say formatXof(1500)
say totalWithFee(10000, 25, 1.5)
say splitShare(9000, 3)
```

## Notes

- Arrondi à l’unité (pratique XOF).
- Pas un moteur de change bancaire — taux fourni par l’appelant.

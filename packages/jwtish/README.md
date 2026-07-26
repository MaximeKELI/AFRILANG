# jwtish

Découpage / décodage de jetons **JWT-shaped** (header.payload.sig) — **sans vérif crypto**.

Utile pour démos auth ; pour la prod, signer avec `hmacx` / Ed25519 côté serveur.

```afrilang
import "pkg/jwtish/jwtish.afr"
use jwtish
say subOf(token)
```

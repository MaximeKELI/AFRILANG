# hmacx

Signatures **HMAC-SHA256** pour webhooks / digests (`std/crypto`).

```afrilang
import "pkg/hmacx/hmacx.afr"
use hmacx
create sig = signHex("secret", body)
if verify("secret", body, sig) then
    say "ok"
end
```

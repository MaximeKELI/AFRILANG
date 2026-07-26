# webapi

Helpers **API JSON** sur `std/web` : routes `/health`, corps JSON, dispatch hors réseau.

## Usage

```afrilang
import "pkg/webapi/webapi.afr"
use webapi

create router = makeHealthRouter()
set router = addJsonGet(router, "/api/markets", jsonMessage("count", "12"))
// serveOnce(8080, router)
say get(router, "/health")
```

## Notes

- Corps de route = texte figé (comme `std/web`) — idéal pour stubs / démos métier.
- Smoke sans socket.

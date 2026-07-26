# httpx

Helpers **HTTP + JSON** pour appels d’API (Bearer, `Content-Type`, query string, POST JSON) — composition de `std/http` et `std/json`.

## Usage

```afrilang
import "pkg/httpx/httpx.afr"
use httpx

create url = withQuery("https://api.example/markets", "city", "Lome")
create body = object1("amount", "5000")
// create raw = postJsonAuth(url, env("API_TOKEN"), body)
// create status = getStringField(raw, "status")
```

## Notes

- Smoke `tests/smoke.afr` : **sans réseau**.
- Pour les retries réseau, combiner avec `pkg/backoff`.

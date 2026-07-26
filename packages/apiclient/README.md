# apiclient

Client API avec **retry / backoff** (réseaux mobiles instables) — `std/http` + `sleepMs`.

## Usage

```afrilang
import "pkg/apiclient/apiclient.afr"
use apiclient

if canRetry(0, 5, "") then
    say nextDelayMs(0, 200, 5000)
end

// create raw = getWithRetry("https://api.example/health", 4, 200, 3000)
```

## Notes

- Smoke **sans réseau**.
- Logique backoff alignée sur `pkg/backoff` (inline pour éviter les deps inter-paquets).

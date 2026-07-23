# llmx

Helpers chat **OpenAI-compatible** pour AFRILANG (corps JSON, extraction, POST optionnel).

## Usage

```afrilang
import "pkg/llmx/llmx.afr"
use llmx

// Offline helpers
create body = buildChatBody("llama3", "Bonjour")
create text = extractAssistantText("{\"choices\":[{\"message\":{\"content\":\"Hi\"}}]}")

// Réseau (Ollama local — pas de clé)
create reply = chatText("http://127.0.0.1:11434/v1", "", "llama3", "Bonjour")

// OpenAI (ou proxy compatible)
// create reply = chatText("https://api.openai.com/v1", env("OPENAI_API_KEY"), "gpt-4o-mini", "Hi")
```

## Notes

- Dépend de `std/http` (`httpPostHeaders`), `std/json`, `std/str`.
- Smoke `tests/smoke.afr` : **sans réseau**.
- Voir aussi `docs/STDLIB_AI.md` (ML classique catalogue) et `examples/llmx_chat.afr`.

# deployx

Helpers **ops / deploy** légers : Procfile, URL `/health`, webhook HTTP, hint Dockerfile.

> Ce n’est **pas** un SDK AWS/GCP — uniquement des briques HTTP + fichiers pour démarrer une story cloud.

## Usage

```afrilang
import "pkg/deployx/deployx.afr"
use deployx

writeProcfile("Procfile", "./build/myapi")
create body = healthCheck("https://myapp.example")
if healthLooksOk(body) then
    say "up"
end
```

## Notes

- Smoke **sans réseau** (helpers texte + écriture Procfile `/tmp`).

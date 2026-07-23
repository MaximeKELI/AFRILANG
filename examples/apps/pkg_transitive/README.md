# pkg_transitive

Dépend uniquement de `queryx` ; `pkg install` tire aussi `urlx` (dépendance déclarée dans le manifest de `queryx`).

```bash
cd examples/apps/pkg_transitive
afrilang pkg install
grep -q urlx afrilang.lock
afrilang run src/main.afr
```

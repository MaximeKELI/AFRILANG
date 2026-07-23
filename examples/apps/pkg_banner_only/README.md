# pkg_banner_only

Ne dépend que de `bannerx` ; `flagx` est tiré transitivement.

```bash
cd examples/apps/pkg_banner_only
afrilang pkg install
grep -q flagx afrilang.lock
afrilang run src/main.afr
```

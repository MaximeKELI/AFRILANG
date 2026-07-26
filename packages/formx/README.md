# formx

Helpers **form-urlencoded** pour POST d’API / USSD gateways.

```afrilang
import "pkg/formx/formx.afr"
use formx
create body = encodeForm2("msisdn", "22177", "amount", "1000")
```

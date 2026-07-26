# places

Helpers **OpenStreetMap / Nominatim** : URLs de recherche / reverse + extraction JSON (lat, lon, `display_name`).

## Usage

```afrilang
import "pkg/places/places.afr"
use places

create url = searchUrl("Marché de Kara", "tg")
// create raw = searchPlace("Lome", "tg")  // réseau — User-Agent requis côté politique OSM
create name = firstDisplayName("[{\"display_name\":\"Lomé\",\"lat\":\"6.1\",\"lon\":\"1.2\"}]")
```

## Notes

- Smoke **sans réseau**.
- Respecter la [politique d’usage Nominatim](https://operations.osmfoundation.org/policies/nominatim/) (User-Agent, rate limit).

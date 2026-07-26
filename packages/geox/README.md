# geox

Distances et rayon pour **logistique / terrain** (cliniques, marchés, flottes) — s’appuie sur `std/geo` (haversine).

## Usage

```afrilang
import "pkg/geox/geox.afr"
use geox

create d = distanceKm(6.13, 1.22, 5.60, -0.19)
if withinKm(6.13, 1.22, 6.20, 1.30, 30) then
    say "Dans le rayon"
end
```

## Notes

- Longitude moyenne = moyenne simple (pas de correction antimeridien).
- Smoke sans réseau.

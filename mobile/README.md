# AFRILANG Mobile (Flutter)

Application mobile qui **reproduit le frontend du site web** et consomme le **même backend Django** (`web/`).

## Prérequis

- Flutter 3.22+ (`flutter doctor`)
- Backend web avec le **venv** (Django n’est pas installé globalement) :

```bash
cd web
source .venv/bin/activate
python manage.py runserver 0.0.0.0:8000
```

Si `.venv` n’existe pas encore :

```bash
cd web
python3 -m venv .venv   # ou: uv venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

## Lancer l’app

```bash
cd mobile/afrilang
flutter pub get
flutter run
```

### URL du backend

| Cible | Base URL |
|--------|----------|
| Émulateur Android | `http://10.0.2.2:8000` (défaut) |
| iOS Simulator / desktop / Chrome | `http://127.0.0.1:8000` |
| Téléphone physique | IP LAN, ex. `http://192.168.1.10:8000` |

Override :

```bash
flutter run --dart-define=AFRILANG_API_BASE=http://192.168.1.10:8000
```

## Fonctionnalités (miroir du site)

- Accueil (hero, stats, features, paquets certifiés, CTA)
- Documentation (pages FR/EN + blocs code / callouts)
- Paquets + détail
- Exemples + Run
- Stdlib (cœur / expérimental) + détail API
- Playground (Run / Format / Check)
- Tutoriel interactif, releases, FR/EN, mode sombre

## API Django utilisée

Préfixe : `/api/mobile/`

- `GET bootstrap/`, `home/`, `docs/`, `docs/<slug>/`
- `GET packages/`, `packages/<name>/`, `examples/`, `stdlib/`, `stdlib/<name>/`
- `GET tutorial/`, `tutorial/<step>/`, `releases/`
- `POST run/`, `fmt/`, `check/` (CSRF exempt, rate-limité comme le playground web)

Les exemples détaillés utilisent aussi `GET /api/examples/<slug>/`.

## Structure

```
lib/
  config/api_config.dart
  services/api_client.dart
  state/app_state.dart
  theme/afrilang_theme.dart   # Plus Jakarta Sans + JetBrains Mono, #1d4ed8
  widgets/common.dart         # code panel, hero mesh, fade-ins
  screens/…
```

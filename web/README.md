# AFRILANG Web — Django + PostgreSQL + Bootstrap + Tailwind

Site officiel dynamique pour l'écosystème AFRILANG.

## Stack

| Couche | Technologie |
|--------|-------------|
| Backend | **Django 5** |
| Base de données | **PostgreSQL 16** |
| UI | **Bootstrap 5** + **Tailwind CSS** (préfixe `tw-`) |
| Compilateur | binaire `afrilang` (subprocess) |

## Démarrage rapide

```bash
# 1. PostgreSQL
cd web
docker compose up -d

# 2. Python
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
cp .env.example .env

# 3. Tailwind (optionnel — CSS minimal inclus)
npm install && npm run build:css

# 4. Django
python manage.py migrate
python manage.py seed_data
python manage.py sync_packages
python manage.py createsuperuser   # optionnel
python manage.py runserver
```

Ouvrir **http://127.0.0.1:8000**

## Pages

- `/` — Accueil (stats, paquets DB, exemples)
- `/explore/` — Capacités (modèle `Capability`)
- `/docs/` — Documentation
- `/packages/` — Registre PostgreSQL + recherche
- `/playground/` — Éditeur + API run/fmt
- `/benchmarks/` — Graphiques compile/exec (Chart.js)
- `/admin/` — Administration Django

## API REST

| Endpoint | Méthode | Description |
|----------|---------|-------------|
| `/api/run/` | POST | `{ "source": "..." }` → exécution native |
| `/api/compile/js/` | POST | Transpile vers JavaScript (exécution navigateur) |
| `/api/build/wasm/` | POST | Module WASM pour le navigateur (Emscripten serveur) |
| `/api/wasm/<id>/module.js` | GET | Artefact WASM de session |
| `/api/run/wasm/` | POST | Exécution WASM serveur (emscripten requis) |
| `/api/fmt/` | POST | Formatage |
| `/api/packages/` | GET | Liste JSON des paquets |

Les runs playground sont enregistrés dans `PlaygroundRun` (PostgreSQL).

## Variables d'environnement

Voir `.env.example` :

- `DATABASE_URL` — PostgreSQL
- `AFRILANG_BIN` — chemin vers le compilateur
- `AFRILANG_ROOT` — racine du repo
- `PLAYGROUND_WASM_DIR` — sessions WASM temporaires (défaut: `web/tmp/wasm_sessions`)

### Compilateur WASM client (optionnel)

Pour exécuter la compilation **dans le navigateur** sans appeler `/api/compile/js` :

```bash
# Nécessite Emscripten (emsdk)
./scripts/build_wasm_compiler.sh
# → web/static/compiler/afrilang-compiler.js
```

## Commandes utiles

```bash
python manage.py sync_packages   # packages/index.json → PostgreSQL
python manage.py sync_benchmarks # scripts/benchmark.sh → SiteMetric
python manage.py seed_data       # exemples + capacités
```

## Ancien site statique

Le dossier `site/` (serveur C++ `afrilang serve`) reste disponible.
Ce projet Django le remplace pour la production avec base de données.

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
- `/admin/` — Administration Django

## API REST

| Endpoint | Méthode | Description |
|----------|---------|-------------|
| `/api/run/` | POST | `{ "source": "..." }` → exécution native |
| `/api/run/wasm/` | POST | Exécution WASM (emscripten requis) |
| `/api/fmt/` | POST | Formatage |
| `/api/packages/` | GET | Liste JSON des paquets |

Les runs playground sont enregistrés dans `PlaygroundRun` (PostgreSQL).

## Variables d'environnement

Voir `.env.example` :

- `DATABASE_URL` — PostgreSQL
- `AFRILANG_BIN` — chemin vers le compilateur
- `AFRILANG_ROOT` — racine du repo

## Commandes utiles

```bash
python manage.py sync_packages   # packages/index.json → PostgreSQL
python manage.py seed_data       # exemples + capacités
```

## Ancien site statique

Le dossier `site/` (serveur C++ `afrilang serve`) reste disponible.
Ce projet Django le remplace pour la production avec base de données.

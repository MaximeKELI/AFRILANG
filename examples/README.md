# Exemples AFRILANG


## Field ops (vitrine A+B)

| App | Contenu |
|-----|---------|
| `apps/field_ops` | Règles métier lisibles + offline Afrique (`moneyx`/`phonex`/`geox`/`storex`) |

```bash
cd examples/apps/field_ops
afrilang pkg install
afrilang run src/main.afr
```

Programmes de référence. Suite : `afrilang test` (section exemples).

## Jeux (2D / 3D)

| Fichier | Contenu |
|---------|---------|
| `crystal_arena.afr` | **Crystal Arena** — jeu 3D (menu, pause, victoire/défaite, WASD, physique, HUD) |
| `crystal_arena_logic.afr` | Règles pures : POO, interfaces, héritage, enums/`match`, listes |
| `crystal_arena_test.afr` | Tests unitaires des règles (sans fenêtre SDL) |
| `snake.afr` / `snake_test.afr` | Snake 2D + tests |
| `game3d_demo.afr` / `game3d_complex.afr` | Démos `std/game3d` |

```bash
# Règles seules (CI-friendly)
./build/afrilang examples/crystal_arena_test.afr -o /tmp/crystal_arena_test && /tmp/crystal_arena_test

# Jeu 3D (affichage SDL/OpenGL requis)
./build/afrilang run examples/crystal_arena.afr
```

Contrôles Crystal Arena : `1`/`2`/`3` difficulté · `Enter` jouer · `WASD` · `Space` sauter · `P` pause · `F` caméra · `R` restart · `Escape` menu/quit.

## Finance (GUI + CLI)

| Fichier | Contenu |
|---------|---------|
| `finance_gui.afr` | **AFRIFINANCE GUI** — interface `std/ui` (dashboard, boutons, barres) |
| `finance_app.afr` | Variante CLI menu / `readLine` |
| `finance_logic.afr` | Règles : comptes, budgets, objectifs, enums/`match`, POO |
| `finance_demo.afr` | Démo scriptée + persistance fichier |
| `finance_test.afr` | Tests unitaires |

```bash
./build/afrilang run examples/finance_gui.afr
./build/afrilang examples/finance_test.afr -o /tmp/fin_test && /tmp/fin_test
./build/afrilang run examples/finance_demo.afr
```

GUI : accueil (solde + budgets) · Revenu / Dépense (pavé + catégories) · liste · budgets · objectif · charger/sauver.  
`Escape` = retour / quitter. Fichier : `finance_data.txt`.

## IA / ML / NLP (expérimental)

Voir [`docs/STDLIB_AI.md`](../docs/STDLIB_AI.md).

| Fichier | Contenu |
|---------|---------|
| `ai_toolkit_demo.afr` | Tour curated |
| `ml_cosine_demo.afr` | similarité cosinus |
| `ml_kmeans_demo.afr` | clustering |
| `ml_perceptron_demo.afr` | apprend AND |
| `ml_softmax_demo.afr` | softmax / entropy / KL |
| `ml_distance_demo.afr` | distances + kNN |
| `ml_linear_demo.afr` | régression |
| `ml_naivebayes_demo.afr` | Naive Bayes multi-features |
| `nlp_demo.afr` | Levenshtein |
| `nlp_jaccard_demo.afr` | Jaccard / Dice |
| `nlp_tfidf_demo.afr` | TF-IDF |
| `nlp_token_bow_demo.afr` | tokenize / BoW / ngrams |
| `llmx_chat.afr` | chat OpenAI-compatible (offline) |
| `iaultra_demo.afr` | pack ultra historique |

```bash
./build/afrilang run examples/ai_toolkit_demo.afr
./build/afrilang run examples/llmx_chat.afr
bash scripts/check_examples_ai.sh
```

Après rebuild : `cp build/afrilang ~/.local/bin/afrilang` (évite un binaire PATH obsolète).

# Toolkit IA AFRILANG (expérimental)

L’IA n’est **pas** dans le core (`docs/CORE_STDLIB.md`). Elle vit dans le catalogue
complexe `import "std/c/…"` (runtime opt-in `complex_libs.hpp`) et, pour les LLM,
dans le paquet utilisateur `llmx`.

**Ne pas** confondre « 5710 modules complex » avec « 5710 libs ML ».

## Noyau ML / NLP réel (curated)

| Module | Import | Rôle |
|--------|--------|------|
| mlcosine | `std/c/mlcosine` | similarité cosinus, normalize, batch |
| mlkmeans | `std/c/mlkmeans` | k-means, inertia, silhouette sample |
| mllinear | `std/c/mllinear` | régression linéaire / GD / sigmoid |
| mlsoftmax | `std/c/mlsoftmax` | softmax, CE, argmax, one-hot |
| mlperceptron | `std/c/mlperceptron` | perceptron ; `trainStep`/`trainEpoch` → `[bias, w…]` |
| mlnaivebayes | `std/c/mlnaivebayes` | NB gaussien simplifié |
| mlentropy | `std/c/mlentropy` | entropy Shannon, normalize probs |
| mlkldiv | `std/c/mlkldiv` | KL / JS / Hellinger |
| mldistance | `std/c/mldistance` | euclidean, manhattan, chebyshev |
| mlnearest | `std/c/mlnearest` | nearestIdx, knnIndices |
| mlnormalize | `std/c/mlnormalize` | L2, min-max, z-score |
| nlplevenshtein | `std/c/nlplevenshtein` | distance d’édition |
| nlpjaccard | `std/c/nlpjaccard` | Jaccard |
| nlptfidf | `std/c/nlptfidf` | TF-IDF (préférer à `mltfidf`) |

Specs : `tests/stdlib/ml_*.afr`, `tests/stdlib/nlp_levenshtein.afr`.

### Exemples (`examples/`)

| Fichier | Contenu |
|---------|---------|
| `ai_toolkit_demo.afr` | Tour curated (cosine, softmax, knn, perceptron, nlp, llmx offline) |
| `ml_cosine_demo.afr` | similarité / batch / mostSimilar |
| `ml_kmeans_demo.afr` | k-means, labels, inertia, elbow |
| `ml_perceptron_demo.afr` | apprend AND |
| `ml_softmax_demo.afr` | softmax + entropy + KL/JS |
| `ml_distance_demo.afr` | distances + knn + normalize |
| `ml_linear_demo.afr` | régression GD |
| `nlp_demo.afr` | levenshtein |
| `nlp_jaccard_demo.afr` | Jaccard / Dice |
| `llmx_chat.afr` | corps chat + extract (réseau commenté) |
| `iaultra_demo.afr` / `complex_libs_demo.afr` | demos ultra / mixte historiques |

## Fillers (noms trompeurs)

Toujours des helpers Sum/Mean génériques — **pas** l’algo annoncé :

`mlsvm`, `mlpca`, `mltfidf`, `mlgradient`, `mlcrossval`, `mlfeature`,
`mlcluster`, `mldecision`, `mlensemble`, et la majorité des `nlp*` hors
levenshtein / jaccard / tfidf.

## Ultra clones

`iaultra001`…`500` et `datasci*` : primitives ML/data classiques **réelles** mais
fortement dupliquées (variantes de défauts). Utiles en démo ; pas une surface
API à apprendre module par module. Préférer le curated ci-dessus.

## LLM

Pas de client LLM dans la stdlib. Paquet : `packages/llmx` (API chat
OpenAI-compatible via `std/http` + headers). Voir `docs/PKG.md`.

## Politique

1. Bugs / tests prioritaires sur le **curated** réel.
2. Pas de promotion en core sans runtime dédié + specs + entrée `CORE_STDLIB.md`.
3. Pas de nouveaux clones `iaultra*` pour « grossir » le catalogue.
4. WASM : complex / LLM = **natif only** (`WASM_COMPAT.md`).

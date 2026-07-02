# PyTorch (libtorch) dans AFRILANG

AFRILANG intègre **PyTorch C++ (libtorch)** via le module `std/torch` / `std/tensor`. Tu écris du code ML en syntaxe naturelle ; le compilateur transpile vers C++ et lie libtorch.

## Démarrage rapide

```afr
import "std/tensor"
use tensor

setSeed(42)
create x tensor = fromList(list of 1.0, 2.0, 3.0)
say toString(x)
say sum(x)
```

```bash
afrilang run mon_modele.afr
```

Si libtorch n'est pas installé, le compilateur le **télécharge automatiquement** (version CPU) au premier build.

---

## Installation manuelle

### Commande `install`

```bash
# CPU (recommandé pour débuter, ~200 Mo)
afrilang install torch cpu

# GPU — détecte le GPU et la version CUDA adaptée
afrilang install torch gpu

# Version précise
afrilang install torch gpu version 2.5.1

# Réinstallation forcée
afrilang install torch gpu --force
```

Sans argument `cpu`/`gpu`, la commande affiche le GPU détecté (si présent) et installe la version **CPU** par défaut.

### Détection GPU automatique

Avec `afrilang install torch gpu`, le compilateur :

1. Lance `nvidia-smi` pour identifier le GPU (ex. `NVIDIA GeForce RTX 4050`)
2. Lit la version CUDA du driver (ex. `13.1`)
3. Choisit le build libtorch correspondant :

| CUDA détecté | Build libtorch |
|--------------|----------------|
| ≥ 12.4       | `cu124`        |
| ≥ 12.1       | `cu121`        |
| ≥ 11.8       | `cu118`        |

Exemple de sortie :

```
Installation libtorch v2.5.1 (gpu)
  GPU: NVIDIA GeForce RTX 4050 Laptop GPU
  Driver: 550.xx
  CUDA detecte: 13.1 -> build cu124
  URL: https://download.pytorch.org/libtorch/cu124/...
```

### Emplacement et variables

| Élément | Chemin / variable |
|---------|-------------------|
| Installation | `~/.local/afrilang/libtorch` |
| Cache archives | `~/.local/afrilang/cache/` |
| Métadonnées | `~/.local/afrilang/libtorch/.afrilang-torch.json` |
| Variable principale | `AFRILANG_TORCH_HOME` |
| Activer CUDA au build | `AFRILANG_TORCH_CUDA=1` |

Après installation GPU :

```bash
export AFRILANG_TORCH_HOME="$HOME/.local/afrilang/libtorch"
export AFRILANG_TORCH_CUDA=1
export LD_LIBRARY_PATH="$AFRILANG_TORCH_HOME/lib:$LD_LIBRARY_PATH"
```

### Prérequis système

- `curl` ou `wget`
- `unzip`
- Pour GPU : drivers NVIDIA + `nvidia-smi`

---

## Imports et modules

Deux imports équivalents :

```afr
import "std/torch"
use torch
```

```afr
import "std/tensor"
use tensor
```

`use tensor` est un alias pratique — les fonctions sont identiques.

---

## Types `tensor` et `optimizer`

```afr
create weights tensor = random(10, 5)
create optim optimizer = adam(list of weights, 0.01)
```

En C++ généré : `afrilang::runtime::torch::Tensor` et `afrilang::runtime::torch::Optimizer`.

> Les appels de fonction sans argument nécessitent des parenthèses dans les conditions :
> `if gpuIsReady() is equal to true then` (pas `gpuIsReady` seul).

---

## API — création de tenseurs

| Fonction | Description |
|----------|-------------|
| `fromList(values)` | Vecteur 1D depuis `list number` |
| `zeros(rows, cols)` | Matrice 2D remplie de zéros |
| `ones(rows, cols)` | Matrice 2D remplie de uns |
| `random(rows, cols)` | Matrice 2D aléatoire |
| `zerosFromShape(dims)` | Tenseur N-D (`list number` de dimensions) |
| `randomFromShape(dims)` | Tenseur N-D aléatoire |
| `load(path)` | Charger depuis un fichier |
| `setSeed(seed)` | Initialiser le générateur aléatoire |

```afr
create image tensor = randomFromShape(list of 1.0, 1.0, 28.0, 28.0)
```

---

## API — opérations

| Fonction | Description |
|----------|-------------|
| `add(a, b)` | Addition |
| `sub(a, b)` | Soustraction |
| `mul(a, b)` | Multiplication élément par élément |
| `matmul(a, b)` | Produit matriciel |
| `relu(t)` | Activation ReLU |
| `flatten(t)` | Aplatir le tenseur |
| `sum(t)` | Somme scalaire (`number`) |
| `totalOf(t)` | Somme en tenseur (pour autograd) |
| `item(t)` | Valeur scalaire |
| `itemAt(t, index)` | Élément à l'index |
| `shape(t)` | `list number` des dimensions |
| `toString(t)` | Affichage texte |

---

## API — GPU / CUDA

| Fonction | Description |
|----------|-------------|
| `gpuIsReady()` | `true` si CUDA est disponible |
| `moveToGpu(t)` | Transférer sur GPU |
| `moveToCpu(t)` | Ramener sur CPU |
| `isOnGpu(t)` | Vérifier si le tenseur est sur GPU |

```afr
if gpuIsReady() is equal to true then
    create onGpu tensor = moveToGpu(input)
    say "Calcul sur GPU"
end
```

---

## API — autograd

| Fonction | Description |
|----------|-------------|
| `enableGrad(t)` | Activer le suivi des gradients |
| `gradIsEnabled(t)` | Vérifier si grad est actif |
| `computeGrad(t)` | Rétropropagation (`backward`) |
| `backward(t)` | Alias de `computeGrad` |
| `gradOf(t)` | Lire le gradient |
| `zeroTensorGrad(t)` | Remettre le gradient d'un tenseur à zéro |
| `detach(t)` | Détacher du graphe autograd |
| `cloneTensor(t)` | Copie du tenseur |

```afr
create x tensor = enableGrad(fromList(list of 2.0, 3.0))
create y tensor = mul(x, x)
create loss tensor = totalOf(y)
backward(loss)
say toString(gradOf(x))
```

> Utilise `totalOf(y)` (retourne un `tensor`) pour l'autograd, pas `sum(y)` (retourne un `number`).

---

## API — mode gradient / inference

| Fonction | Description |
|----------|-------------|
| `gradModeIsOn()` | `true` si le calcul de gradient est actif (équivalent `torch.is_grad_enabled()`) |
| `setGradMode(enabled)` | Activer / désactiver le mode gradient global |
| `noGradMode()` | Désactiver les gradients (`torch.no_grad()`) |
| `enableGradMode()` | Réactiver les gradients |
| `trainMode()` | Mode entraînement (dropout actif) |
| `evalMode()` | Mode évaluation / inference |
| `isTrainingMode()` | Vérifier le mode entraînement |

```afr
noGradMode()
create pred tensor = linear(input, weight, bias)
enableGradMode()
```

---

## API — fonctions de perte

| Fonction | Description |
|----------|-------------|
| `mseLoss(pred, target)` | Erreur quadratique moyenne |
| `crossEntropyLoss(logits, targets)` | Cross-entropy (labels entiers via `fromIntList`) |
| `binaryCrossEntropy(pred, target)` | BCE |
| `nllLoss(logProbs, targets)` | Negative log-likelihood |

---

## API — activations

| Fonction | Description |
|----------|-------------|
| `softmax(t, dim)` | Softmax sur la dimension `dim` |
| `logSoftmax(t, dim)` | Log-softmax |
| `dropout(t, p)` | Dropout (respecte `trainMode` / `evalMode`) |
| `sigmoid(t)` | Sigmoïde |
| `tanhOf(t)` | Tangente hyperbolique |
| `fromIntList(values)` | Tenseur d'indices entiers (labels) |

---

## API — optimiseurs et entraînement

| Fonction | Description |
|----------|-------------|
| `sgd(params, lr)` | Optimiseur SGD (`params` = `list tensor`) |
| `adam(params, lr)` | Optimiseur Adam |
| `zeroOptimizer(opt)` | `optimizer.zero_grad()` |
| `optimizerStep(opt)` | `optimizer.step()` |
| `trainStep(opt, loss)` | `zero_grad` + `backward` + `step` en une passe |

```afr
create weight tensor = enableGrad(random(2, 3))
create bias tensor = enableGrad(zerosFromShape(list of 2.0))
create params = list of weight, bias
create optim optimizer = adam(params, 0.01)

trainMode()

for epoch from 1 to 100 do
    create pred tensor = linear(input, weight, bias)
    create loss tensor = mseLoss(pred, target)
    trainStep(optim, loss)
end

evalMode()
noGradMode()
create output tensor = linear(input, weight, bias)
enableGradMode()
```

Type `optimizer` en C++ : `afrilang::runtime::torch::Optimizer`.

---

## API — couches réseau

| Fonction | Description |
|----------|-------------|
| `linear(input, weight, bias)` | Couche fully-connected |
| `conv2d(input, weight, bias, stride)` | Convolution 2D |

```afr
create input tensor = random(4, 3)
create weight tensor = random(2, 3)
create bias tensor = randomFromShape(list of 2.0)
create output tensor = linear(input, weight, bias)
```

Formes typiques :
- `linear` : input `(batch, in_features)`, weight `(out_features, in_features)`, bias `(out_features)`
- `conv2d` : input `(N, C, H, W)`, weight `(out_channels, in_channels, kH, kW)`

---

## Persistance

```afr
save(model, "modele.pt")
create loaded tensor = load("modele.pt")
```

---

## Exemples

| Fichier | Description |
|---------|-------------|
| `examples/torch_demo.afr` | Opérations de base (matrices, ReLU) |
| `examples/ml_demo.afr` | Autograd, linear, conv2d, GPU, entraînement |
| `examples/train_demo.afr` | Boucle complète SGD/Adam, noGrad, cross-entropy |
| `examples/tensor_auto.afr` | Import `std/tensor` minimal |
| `examples/torch_test.afr` | Tests intégrés (`test` / `assert`) |

```bash
afrilang run examples/ml_demo.afr
afrilang check examples/torch_test.afr
```

---

## Architecture

```
fichier .afr
    import "std/tensor" + use tensor
        ↓
StdlibRegistry::injectTensorModule()
        ↓
runtime/torch.hpp  (wrapper C++ autour de libtorch)
        ↓
libtorch (torch::Tensor, autograd, nn::functional)
```

Fichiers clés :

| Fichier | Rôle |
|---------|------|
| `runtime/torch.hpp` | Wrapper C++, classe `Tensor` |
| `include/afrilang/torch_install.hpp` | Installation / détection GPU |
| `src/utils/torch_install.cpp` | Téléchargement curl/wget + unzip |
| `src/utils/stdlib_registry.cpp` | Injection module AST |
| `src/codegen/codegen.cpp` | Includes, flags `-ltorch`, CUDA |

---

## Dépannage

| Problème | Solution |
|----------|----------|
| `installation invalide` après extraction | Réessayez — corrigé en v1.0+ (chemin `torch.h` libtorch 2.5) |
| `File size limit exceeded` (g++) | Mise à jour récente — ou `export AFRILANG_INSECURE=1` |
| `[torch unavailable: ...]` | `afrilang install torch cpu` ou définir `AFRILANG_TORCH_HOME` |
| Erreur `torch/torch.h not found` | Réinstaller libtorch, vérifier `AFRILANG_TORCH_HOME` |
| GPU non détecté | `nvidia-smi`, drivers NVIDIA, puis `afrilang install torch gpu` |
| Téléchargement lent | Version CPU (~200 Mo) vs GPU (~2 Go) |
| `if gpuIsReady is equal to true` échoue | Utiliser `gpuIsReady()` avec parenthèses |

---

## Licence

libtorch est distribué sous licence PyTorch (BSD-style). Voir [pytorch.org](https://pytorch.org/).

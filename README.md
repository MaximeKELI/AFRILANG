# AFRILANG

Compilateur pour **AFRILANG**, un langage orienté objet à syntaxe naturelle qui transpile vers C++17.

## Architecture

```
AFRILANG/
├── include/afrilang/     # Headers publics
│   ├── token.hpp         # Types de tokens
│   ├── lexer.hpp         # Analyseur lexical
│   ├── ast.hpp           # Nœuds de l'AST (avec positions source)
│   ├── parser.hpp        # Analyseur syntaxique
│   ├── semantic.hpp      # Analyse sémantique
│   ├── codegen.hpp       # Génération de code C++
│   ├── compiler.hpp      # Compilation multi-fichiers (imports)
│   ├── types.hpp         # Types du langage
│   └── error.hpp         # Gestion d'erreurs
├── src/
│   ├── lexer/lexer.cpp
│   ├── parser/parser.cpp
│   ├── semantic/analyzer.cpp
│   ├── codegen/codegen.cpp
│   └── utils/compiler.cpp
├── examples/             # Programmes AFRILANG
├── main.cpp              # Point d'entrée du compilateur
└── CMakeLists.txt
```

## Pipeline de compilation

```
fichier.afr  →  Compiler (imports)  →  Lexer  →  Parser  →  AST  →  Sémantique  →  CodeGen  →  g++  →  exécutable
```

## Compilation du compilateur

```bash
mkdir build && cd build
cmake ..
make
```

## Utilisation

```bash
# Compiler un programme AFRILANG
./afrilang ../examples/hello.afr

# Compiler et exécuter
./afrilang ../examples/hello.afr --run

# Afficher les tokens (debug lexer)
./afrilang ../examples/hello.afr --tokens

# Afficher l'AST (debug parser)
./afrilang ../examples/hello.afr --ast

# Générer le C++ sans compiler
./afrilang ../examples/hello.afr --emit

# Spécifier le nom de l'exécutable
./afrilang ../examples/oop.afr -o mon_programme --run
```

## Syntaxe du langage

### Affichage
```
say "Bonjour le monde"
```

### Variables
```
create x = 42
create name = "Alice"
create x number = 42
create flag bool = true
set x = 100
```

### Booléens
```
create active bool = true
create ok = yes
create failed = no

if active is equal to true then
    say "Actif"
else
    say "Inactif"
end
```

Types booléens : `true`, `false`, `yes`, `no`, type `bool`.

### Listes
```
create nums = list of 1, 2, 3
create bracket = [10, 20, 30]
create empty = empty list number

say nums at 0
say bracket[2]
say length of nums

set nums at 1 = 99
add 4 to nums

for each item in nums do
    say item
end
```

### Entrée utilisateur
```
ask "Quel est votre nom ?" into name
say name
```

### Classes et méthodes
```
class Person
    function speak()
        say "Bonjour"
    end
end

create person = new Person
person.speak()
```

### Champs et constructeurs
```
class Person
    public field name text
    private field age number

    function init(aName text, aAge number)
        set this.name = aName
        set this.age = aAge
    end

    function greet()
        say name
    end
end

create bob = new Person
set bob.name = "Bob"
```

### Records (structs)
```
record Point
    field x number
    field y number
end
```

### Modules
```
module Math
    function add(a number, b number) returns number
        return a + b
    end
end

use Math
say add(3, 4)
```

### Imports multi-fichiers
```
import "helpers.afr"
```

Les fichiers importés apportent leurs déclarations (fonctions, classes, records, modules).

### Héritage
```
class Animal
    function speak()
        say "..."
    end
end

class Dog extends Animal
    function speak()
        say "Woof!"
    end
end
```

### Fonctions avec paramètres et retour
```
function add(a number, b number) returns number
    return a + b
end
```

Types disponibles : `number`, `text`, `bool`, `list number`, `list text`, ou nom de classe/record.

### Conditions
```
if age is greater than 18 then
    say "Adulte"
else
    say "Mineur"
end

if score is equal to 100 then
    say "Parfait"
end

if x is not equal to 0 then
    say "Non nul"
end
```

### Boucles
```
repeat 5 times
    say "Hello"
end

while count is less than 10 do
    say count
    set count = count + 1
end

for each item in nums do
    say item
end
```

### Contrôle de boucle
```
while true do
    if done is equal to true then
        stop
    end
    if skipNext is equal to true then
        skip
    end
end
```

- `stop` → `break`
- `skip` → `continue`

### Opérateurs mathématiques
```
create result = 10 + 5 * 2
say x - y
say a / b
```

## Exemples

| Fichier | Description |
|---------|-------------|
| `examples/hello.afr` | Hello World et boucles repeat |
| `examples/oop.afr` | Classes et appels de méthodes |
| `examples/conditions.afr` | Conditions et arithmétique |
| `examples/inheritance.afr` | Héritage et polymorphisme |
| `examples/functions.afr` | Fonctions globales, paramètres, retours |
| `examples/while.afr` | Boucles while et if/else |
| `examples/lists.afr` | Listes, indexation, for-each |
| `examples/modules.afr` | Modules et use |
| `examples/fields.afr` | Champs public/private et init |
| `examples/records.afr` | Records (structs) |
| `examples/full_demo.afr` | Démo combinée (imports, modules, boucles) |

## Compiler tous les exemples

```bash
cd build && make examples
```

## Correspondances CodeGen (C++)

| AFRILANG | C++ |
|----------|-----|
| `bool` | `bool` |
| `list number` | `std::vector<double>` |
| `list text` | `std::vector<std::string>` |
| `record` | `struct` |
| `module` | `namespace` |
| `while ... do` | `while (...)` |
| `for each x in list` | `for (auto& x : list)` |
| `stop` | `break` |
| `skip` | `continue` |
| `ask "..." into var` | `std::cout << ...; std::getline(std::cin, var)` |
| `length of x` | `x.size()` |
| `add v to list` | `list.push_back(v)` |

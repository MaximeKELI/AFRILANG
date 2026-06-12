# AFRILANG

Compilateur pour **AFRILANG**, un langage orienté objet à syntaxe naturelle qui transpile vers C++17.

## Architecture

```
AFRILANG/
├── include/afrilang/     # Headers publics
│   ├── token.hpp         # Types de tokens
│   ├── lexer.hpp         # Analyseur lexical
│   ├── ast.hpp           # Nœuds de l'AST
│   ├── parser.hpp        # Analyseur syntaxique
│   ├── codegen.hpp       # Génération de code C++
│   └── error.hpp         # Gestion d'erreurs
├── src/
│   ├── lexer/lexer.cpp
│   ├── parser/parser.cpp
│   └── codegen/codegen.cpp
├── examples/             # Programmes AFRILANG
├── main.cpp              # Point d'entrée du compilateur
└── CMakeLists.txt
```

## Pipeline de compilation

```
fichier.afr  →  Lexer  →  Parser  →  AST  →  Sémantique  →  CodeGen  →  g++  →  exécutable
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

class Calculator
    function compute(x number, y number) returns number
        return x + y * 2
    end
end

create result = add(10, 32)
say calc.compute(5, 3)
```

Types disponibles : `number`, `text`, ou nom de classe.

### Conditions
```
if age is greater than 18 then
    say "Adulte"
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
```

### Opérateurs mathématiques
```
create result = 10 + 5 * 2
say x - y
say a / b
```

## Exemples

| Fichier | Description |
|---------|-------------|
| `examples/hello.afr` | Hello World et boucles |
| `examples/oop.afr` | Classes et appels de méthodes |
| `examples/conditions.afr` | Conditions et arithmétique |
| `examples/inheritance.afr` | Héritage et polymorphisme |
| `examples/functions.afr` | Fonctions globales, paramètres, retours |

## Compiler tous les exemples

```bash
make examples
```
# AFRILANG

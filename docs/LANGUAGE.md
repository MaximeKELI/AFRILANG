# AFRILANG Language Specification (draft 0.2)

## Types

| Type | Syntax | C++ |
|------|--------|-----|
| number | `number` | `double` |
| text | `text` | `std::string` |
| bool | `bool` | `bool` |
| list | `list of T` | `std::vector<T>` |
| map | `map K to V` | `std::unordered_map<K,V>` |
| optional | `T?` | `std::optional<T>` |
| result | `T or error` | `AfrResult_T` |

## Maps

```afr
create m = map of "a" to 1, "b" to 2
create m map text to number = map of "x" to 10
create empty = empty map text to number
say m at "a"
set m at "c" = 3
for each key, value in m do
    say key
    say value
end
```

## Exceptions

```afr
try
    raise "something failed"
catch error e
    say e
end
```

## String interpolation

```afr
create name = "World"
say "Hello {name}!"
```

## Modules

Import with `import "std/io"` and `use io`.

Available stdlib modules: io, json, fs, http, str, log, math, time, re.

## Generics

```afr
function identity<T>(x T) returns T
    return x
end
```

## Default parameters

```afr
function greet(name text, prefix text = "Hello") returns text
    return join(list of prefix, " ", name)
end

say greet("World")
say greet("Africa", "Bonjour")
```

## Numeric for loops

```afr
for i from 1 to 10 do
    say i
end

for n from 0 to 10 step 2 do
    say n
end
```

## Constants

```afr
create const MAX = 100
create const NAME text = "AFRILANG"
```

## Lambdas (fonctions anonymes)

```afr
create doubleIt = function(x number) returns number
    return x * 2
end

say doubleIt(21)

function apply(fn function number to number, value number) returns number
    return fn(value)
end

say apply(doubleIt, 10)
```

Type fonction : `function number to number`, `function number, text to text`, etc.

## map / filter / reduce (listes + lambdas)

```afr
import "std/collections"
use collections

create doubled = mapNumbers(nums, function(x number) returns number
    return x * 2
end)

create big = filterNumbers(nums, function(x number) returns bool
    if x is greater than 3 then
        return yes
    else
        return no
    end
end)

create total = reduceNumbers(nums, function(acc number, x number) returns number
    return acc + x
end, 0)
```

## Modules

Import with `import "std/io"` and `use io`.

Available stdlib modules: io, json, fs, http, str, log, math, time, re, collections.

Compiler version follows semantic versioning. Breaking syntax changes require a minor/major bump and CHANGELOG entry.

# Contributing to AFRILANG

Thank you for your interest in AFRILANG!

## Getting Started

```bash
git clone <repo-url>
cd AFRILANG
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j$(nproc)
./build/afrilang test .
./build/afrilang_tests
```

## Pull Request Process

1. Fork the repository and create a feature branch
2. Make focused changes with tests
3. Run `./build/afrilang_tests` and `./build/afrilang test .`
4. Update `docs/LANGUAGE.md` if language behavior changes
5. Update `CHANGELOG.md` under **Unreleased**
6. Open a PR with a clear description and test plan

## Code Style

- C++17, `-Wall -Wextra -Wpedantic`
- 4-space indentation (see `.editorconfig`)
- Match existing naming in each module
- Prefer minimal, focused diffs

## Adding Language Features

1. Lexer/token (`include/afrilang/token.hpp`, `src/lexer/lexer.cpp`)
2. AST (`include/afrilang/ast.hpp`)
3. Parser (`src/parser/parser.cpp`)
4. Semantic analysis (`src/semantic/analyzer.cpp`)
5. Code generation (`src/codegen/codegen.cpp`)
6. Example in `examples/` + add to test list in `src/utils/cli.cpp`
7. Document in `docs/LANGUAGE.md`

## Adding Tests

- Unit tests: `tests/test_compiler.cpp`
- Integration: add `examples/your_demo.afr` to the list in `Pipeline::runTests`

## Commit Messages

Use imperative mood, complete sentences:

```
Add French alias for async/await keywords

Fix playground path traversal when serving static files.
```

# Norme & confiance (gap #10)

> Index of **product honesty** documents. AFRILANG 1.0 is a **product normative**
> language (MUST/SHOULD in `NORMATIVE.md`), **not** an ISO language standard.

## Document map

| Doc | Role |
|-----|------|
| [`NORMATIVE.md`](NORMATIVE.md) | Product rules + conformance binding (explicitly not ISO) |
| [`PLATFORM.md`](PLATFORM.md) | Linux primary; Win/mac host; wasm subset |
| [`MEMORY_MODEL.md`](MEMORY_MODEL.md) | Bounds/optional/Result — no borrow checker claim |
| [`CORE_STDLIB.md`](CORE_STDLIB.md) | Core vs experimental catalogs |
| [`WASM_COMPAT.md`](WASM_COMPAT.md) | What works / is rejected on wasm |
| [`SECURITY.md`](../SECURITY.md) | Reporting + secure-mode policy |
| [`GAPS.md`](GAPS.md) | Industrial depth roadmap |

## Honesty gates

```bash
bash scripts/check_docs_honesty.sh
bash scripts/test_gap_10_trust.sh
```

Checks include: README leads with core (not raw catalog counts), banned ISO-cert
phrases, CHANGELOG catalog counts stay labeled experimental, conformance MANIFEST
files exist, PLATFORM tags align with release matrix.

## Conformance (separate from gap10)

```bash
./build/afrilang test --conformance .
bash scripts/check_asan_conformance.sh   # CI
```

## Non-goals

- Language certification under ISO / IEC process numbers
- Formal semantics rewrite as the gap deliverable
- Marketing “trust seal”
- Re-running the full conformance suite inside gap10 (CI already owns it)

## Related

- [`DIST.md`](DIST.md) · [`INTEROP.md`](INTEROP.md) · [`TOOLING.md`](TOOLING.md)

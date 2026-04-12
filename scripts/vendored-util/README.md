# Vendored BoringSSL util scripts

`read_symbols.go` and `make_prefix_headers.go` are copied verbatim from the
BoringSSL tree at commit
[`817ab07ebb53da35afea409ab9328f578492832d`](https://boringssl.googlesource.com/boringssl/+/817ab07ebb53da35afea409ab9328f578492832d/util/).

## Why they live here

BoringSSL removed both files in early 2026 when symbol prefixing was integrated
directly into its CMake build (via `util/audit_symbols.go` + `delocate`):

- `util/make_prefix_headers.go` — removed in `b523a5f5` (2026-01-16,
  "Integrate the new way of asm symbol prefixing with CMake").
- `util/read_symbols.go` — removed in `1842c3eb` (2026-01-19,
  "Add symbol prefixing validation to CMake").

Our `scripts/vendor-boringssl.sh` still drives symbol mangling the old way
(running these helpers out-of-tree against the built `.a` archives), so we
pin copies here and `cp` them into the clone before use. This keeps the
BoringSSL tag pin (`0.20260327.0`) intact without adopting the new
CMake-based prefixing flow.

## Updating

If BoringSSL's API stays stable, these files don't need to change. If the
surface changes (e.g. new object-file formats), update the copies from any
pre-removal BoringSSL commit and bump the reference above.

The files carry the upstream Apache 2.0 / ISC headers unchanged.

## Local modifications

- `read_symbols.go`: the import of `boringssl.googlesource.com/boringssl/util/ar`
  was rewritten to `boringssl.googlesource.com/boringssl.git/util/ar` to match
  the BoringSSL Go module rename done in commit `b8291f83a` ("Add .git hint to
  Go module name"). The module name at the source commit (`817ab07`) was
  `boringssl.googlesource.com/boringssl`, but at our pinned tag it is
  `boringssl.googlesource.com/boringssl.git`.

# BoringSSL re-vendoring to tag `0.20260327.0`

This document describes the changes made on the `revendor-pt2` branch (vs
`main`) to modernize the BoringSSL vendoring pipeline and re-vendor BoringSSL
at tag `0.20260327.0` (commit `4c91be649fec6c35fb1a3ae0539eaf85e9443ace`).

The previous vendoring was based on pre-C++ BoringSSL (`.c` files, old CMake
`perlasm()` format, pre-prefix-refactor symbol prefixing). New BoringSSL is
C++17 with `.cc` / `.cc.inc` / `.c.inc` files and a 4-param `perlasm()`
directive, and its symbol-prefix helpers were moved into CMake, so both the
driver scripts and the patches needed significant rework.

This document reflects the full working-tree diff against `main` (committed
changes plus the currently unstaged modifications on the branch).

## 1. `scripts/vendor-boringssl.sh` — rewritten top to bottom

Rebuilt to mirror swift-nio-ssl's current shape while upgrading to tag
`0.20260327.0`. The entire file is effectively rewritten; noteworthy specifics:

### Shell hygiene
- `set -eu` → `set -eou pipefail` (the old script left `pipefail` commented
  out).
- `TMPDIR` is now `$(mktemp -d ${HERE}/.boringssl)`. The template has no `X`s,
  so `mktemp` uses the literal name `.boringssl`; the script does **not**
  remove this directory itself, so a stale `.boringssl/` must be deleted
  between runs.
- Removed the legacy `CROSS_COMPILE_TARGET_LOCATION` / `CROSS_COMPILE_VERSION`
  globals (the custom destination JSON / CSCIX65G cross-compiler flow is gone).
- Removed the `getopts 'uk:'` block and the `-c` (clone-latest) / `-k`
  (keep-temp) flags. The script now always clones fresh and always cleans up.

### Cloning and upstream-util restoration
- `git clone --depth 1 --branch 0.20260327.0 …` (was an unpinned clone behind
  a `-c` flag).
- **Vendored util restore**: BoringSSL removed `util/read_symbols.go`
  (commit `1842c3eb`) and `util/make_prefix_headers.go` (`b523a5f5`) in
  Jan 2026 when they moved symbol prefixing into CMake. Our preserved
  copies in `scripts/vendored-util/` are `cp`'d into `$SRCROOT/util/`
  immediately after clone, with an inline comment naming both removal
  commits.

### `PATTERNS` / `EXCLUDES`
The old hard-coded file-by-file list is replaced with globbing patterns
matching current BoringSSL layout:

- `include/openssl/*.h`, `include/openssl/*/*.h`
- `crypto/*.h`, `crypto/*.cc`, `crypto/*/*.{h,cc,S}`,
  `crypto/*/*/*.{h,cc,cc.inc,inc,S}`, `crypto/*/*/*/*.{cc.inc,inc}`
- `gen/crypto/*.{cc,S}`, `gen/bcm/*.S` (new `gen/` tree added in 0.20260327)
- `third_party/fiat/*.h`, `third_party/fiat/*.c.inc`,
  `third_party/fiat/asm/*.S`

The `*.inc` patterns (as distinct from `*.cc.inc`) pick up
`fips_known_values.inc` under `crypto/fipsmodule/{slhdsa,mlkem,mldsa}/`.
`EXCLUDES` updated: `example_*.c` → `example_*.cc`.

### Include rewriting
The `find … | xargs sed` invocation that rewrites `<openssl/…>` to
`<CBigNumBoringSSL_…>` now:
- Covers `*.cc.inc` **and** `*.c.inc` (the latter for
  `third_party/fiat/*.c.inc`).
- Uses a regex (`([^/>]+/)*`) that preserves subpath prefixes, so
  `<openssl/experimental/kyber.h>` becomes
  `<experimental/CBigNumBoringSSL_kyber.h>`.
- Also rewrites `#include "openssl/…"` (quoted form).

### Header renaming
Old `find | sed | xargs mv` was replaced with two bash loops:

```sh
shopt -s nullglob
for x in *.h;   do mv -- "$x" "CBigNumBoringSSL_${x}"; done
for x in **/*.h; do mv -- "$x" "${x%/*}/CBigNumBoringSSL_${x##*/}"; done
shopt -u nullglob
```

`nullglob` makes the second loop a no-op when `include/` has no subdirs
(current BoringSSL layout is flat after the `openssl/` flatten, but keeping
the loop is forward-compat). Also explicitly `rm -rf include/pki` before
renaming, since we don't ship the PKI headers.

### Patch application order
Patches are now applied **before** the Linux exec-stack protection step
(the old ordering was reversed). `patch-2-arm-arch.patch` and
`patch-3-weak-linking.patch` are kept on disk but **not applied**; the
latter targets `crypto/mem.c`, which is now `mem.cc` and would not apply.

### Removed legacy steps
- `go run err_data_generate.go > …/err_data.c`: gone — upstream now ships
  pre-generated `err_data.cc` under `gen/`.
- `rm -f crypto/fipsmodule/bcm.c`: gone (no `bcm.c` in current layout;
  replaced by `rm -rf $DSTROOT/gen` in the initial wipe).
- Post-mangle `gsed` edit of `include/openssl/base.h` for the i386
  `OPENSSL_NO_ASM` guard now targets `CBigNumBoringSSL_base.h` (the
  renamed header) and uses the `$sed` variable rather than hard-coded
  `gsed`.

### `mangle_symbols`
Full rewrite to use the modern toolchain:

- Two macOS builds with explicit triples: `x86_64-apple-macosx` and
  `arm64-apple-macosx`. Previously a single host-native build.
- iOS build re-enabled: `xcodebuild -sdk iphoneos -scheme CBigNumBoringSSL
  -destination generic/platform=iOS`, followed by `ar -r` into
  `libCBigNumBoringSSL-iosarm64.a`. (The old script had this block
  commented out.)
- Linux builds now run in Docker — `swift:6.3-noble` images under
  `--platform linux/arm64` and `linux/amd64`. Replaces the JSON
  destination-file loop. `-t -i` flags were removed from both `docker run`
  invocations so the script works without a TTY (CI, pipes).
- `read_symbols.go` / `make_prefix_headers.go` are invoked from within
  `$SRCROOT` after a `go mod tidy -modcacherw`, so Go picks up BoringSSL's
  own `go.mod` rather than falling back to `GOPATH` resolution.
- Linux archive path pattern changed from `.build/*-unknown-linux/…` to
  `.build/*-unknown-linux-gnu/…` to match Swift's current triple naming.

### `namespace_inlines`
Now scans `$1/*` instead of `$1/crypto/*` (current source layout has
relevant `DEFINE_STACK_OF` / `DEFINE_LHASH_OF` macros in places outside
`crypto/`, e.g. under `ssl/` were it vendored — matching swift-nio-ssl).
Uses the `$sed` variable rather than hard-coded `gsed`.

### New function: `mangle_cpp_structures`
Entirely new (BoringSSL is now C++, so non-namespaced C++ classes whose
ctors/dtors have unprefixed linker symbols can still collide). Builds for
macOS, then:

```sh
nm -gUj …/libCBigNumBoringSSL.a \
  | c++filt \
  | grep "::" \
  | grep -v -e CBigNumBoringSSL -e swift \
  | cut -d : -f1 \
  | { grep -v "std$" || true; } \
  | sed -E -e 's/([^<>]*)(<[^<>]*>)?/\1/' \
  | sort | uniq
```

Each resulting type name gets a
`#define <struct> BORINGSSL_ADD_PREFIX(BORINGSSL_PREFIX, <struct>)` line
appended to `CBigNumBoringSSL_boringssl_prefix_symbols.h`.

**Pipefail fix**: on our archive every remaining C++ symbol is in `std::`,
so the trailing `grep -v "std$"` matches nothing and exits 1. Under
`set -o pipefail` this was killing the subshell before the `Package.swift`
revert could run (leaving the file in its mangled state). Wrapping the grep
in `{ … || true; }` is the fix, with an in-script comment explaining why.

### Modulemap / umbrella
A `module.modulemap` is now written at the end of the run (the old script
never emitted one).

## 2. `scripts/build-asm.py` — modernized for new perlasm

- `#!/usr/bin/env python` → `python3`.
- Dropped the unused `contextlib` import; reordered remaining imports.
- Whole file reindented from 2-space to 4-space (matches swift-nio-ssl).
- **New 4-param `perlasm()` parser**: upstream directive is now
  `perlasm(<name> <arch> <output> <input> [<extra_args>…])`. Parser rejects
  lines with `< 4` params (was `< 2`) and stores `arch`, `output`, `input`,
  `extra_args` keys (old keys: `output`, `input`, `extra_args` only).
- **`WriteAsmFiles` rewritten**: outer loop is now per-`perlasm`, inner
  loop over `OS_ARCH_COMBOS` filtered by `perlasm['arch']`. Output naming
  is uniform: `'%s-%s.%s' % (output, osname, asm_ext)`. The old special
  cases (`-armx32`/`-armx64` substitution, `${ASM_EXT}` replacement, the
  `ArchForAsmFilename` filename-substring heuristic) are all gone —
  upstream's explicit `arch` parameter supersedes them.
- `ArchForAsmFilename()` deleted entirely.
- `munge_file` now writes via `.format(...).encode()` since `sink` is
  opened `'wb'`.
- Python-3 dict semantics: `.iteritems()` → `.items()` at both call sites.
- Misc whitespace/linting cleanup (E501 `# noqa` markers, trailing-blank
  trims).

## 3. `scripts/vendored-util/` (new directory, not on `main`)

- `read_symbols.go`, `make_prefix_headers.go` — vendored verbatim from
  BoringSSL commit `817ab07` (the last pre-removal commit; matches
  swift-nio-ssl's own pin).
- Local patch: `read_symbols.go`'s
  `import "boringssl.googlesource.com/boringssl/util/ar"` was rewritten to
  `"boringssl.googlesource.com/boringssl.git/util/ar"` to match the Go
  module rename done in BoringSSL commit `b8291f83a`.
- `README.md` documents origin, removal commits, rationale, and the
  single local patch.

## 4. Patches — regenerated against current BoringSSL layout

Same net effect as the old patches, but updated for current line numbers
and the Apache-2.0 `//` license headers introduced in BoringSSL's
relicensing:

- `patch-1-inttypes.patch`
  - Adds `#include <inttypes.h>` to `crypto/hrss/hrss.cc`.
  - Swaps `<inttypes.h>` → `<sys/types.h>` in
    `include/CBigNumBoringSSL_bn.h`. Context rebased around the new
    `IWYU pragma: export` comment on the `CBigNumBoringSSL_base.h`
    include.
- `patch-2-inttypes.patch`
  - Adds `<inttypes.h>` to `crypto/x509/t_x509.cc`. Earlier drafts also
    patched `CBigNumBoringSSL_bn.h`; that hunk was dropped because
    patch-1 already does it.
- `patch-3-more-inttypes.patch`
  - Adds `<inttypes.h>` to `crypto/evp/print.cc`.

`patch-2-arm-arch.patch` and `patch-3-weak-linking.patch` remain on disk
but are no longer applied (see §1).

## 5. `Package.swift`

- Added trailing comma after `.library(name: "BigNum", targets: ["BigNum"])`
  — without it SwiftPM errored with `static member 'library' cannot be
  used on instance of type 'Product'` once the file was parsed together
  with the new `cxxLanguageStandard` argument.
- Added `cxxLanguageStandard: .cxx17` at the `Package` level — new
  BoringSSL uses C++17 (`std::is_integral_v`, structured bindings, etc.).
- `MANGLE_START` / `MANGLE_END` markers and target/products structure are
  unchanged.

## 6. `Sources/CBigNumBoringSSL/*` (regenerated, unstaged)

Full re-vendoring of BoringSSL at commit
`4c91be649fec6c35fb1a3ae0539eaf85e9443ace` (tag `0.20260327.0`). This
replaces the old `.c` / `.h`-only layout with `.cc` / `.cc.inc` / `.c.inc`
sources plus BoringSSL's new `CBigNumBoringSSL_prefix_symbols.h` (the
`#pragma redefine_extname`-based prefixing), a refreshed umbrella header,
module map, and `hash.txt`. These changes are currently untracked/unstaged;
committing them is the final step before landing the branch.

## 7. `Sources/BigNum/BigNum.swift` — drop the `CBigNumBoringSSL_` prefix

BoringSSL's new prefixing scheme uses `#pragma redefine_extname`, which
rewrites only the *linker* symbol. At the C source level, identifiers stay
unprefixed, so Swift's clang importer sees them as `BN_CTX_new`,
`BN_is_prime_ex`, `OPENSSL_free`, etc. — not
`CBigNumBoringSSL_BN_CTX_new` and friends. Applied
`gsed -i 's/CBigNumBoringSSL_//g' Sources/BigNum/BigNum.swift`; all 23
unit tests pass. (Unstaged.)

## How to re-run the vendoring

```sh
# Remove the stale clone dir — the literal mktemp name (.boringssl)
# persists between runs and blocks the next clone:
rm -rf .boringssl

# Make sure Package.swift is in the un-mangled pre-run state, i.e.:
#     /* … MANGLE_START
#         .library(name: "CBigNumBoringSSL", …),
#         MANGLE_END */
# If the previous run crashed during mangling you will see
# `MANGLE_START*/ … /*MANGLE_END` instead — revert manually before re-running.

bash scripts/vendor-boringssl.sh
```

A successful run takes several minutes: two native macOS builds (x86_64
and arm64), one iOS arm64 build (xcodebuild), two Linux builds inside
Docker (`swift:6.3-noble` for arm64 and amd64), symbol extraction via the
vendored `read_symbols.go`, prefix-header generation via
`make_prefix_headers.go`, C++ structure mangling via `nm` / `c++filt`,
patch application, and finally the umbrella header + modulemap
regeneration.

Docker Desktop must be running for the Linux build phases.

## Build environment

The vendoring run described here was performed on the following machine.
Anything newer in the same major line should work; older versions may not
(the script assumes Swift 6.x triple names, `swift:6.3-noble` images, Go
modules, Python 3 semantics, GNU `sed` extensions, and Xcode 26's iOS
`-destination generic/platform=iOS` syntax).

### Host
- **macOS** 26.3.1 (build 25D771280a), Darwin 25.3.0, `arm64` (Apple Silicon).
- **bash** 5.3.9 (`aarch64-apple-darwin25.1.0`). The header-rename loop uses
  `shopt -s nullglob` + `**/*.h`; with older bash you'd need `globstar`
  enabled as well.

### Swift / Xcode
- **Xcode** 26.3 (build `17C529`) at `/Applications/Xcode.app`
  (active developer dir via `xcode-select -p`). Required for the iOS arm64
  build step (`xcodebuild -sdk iphoneos -scheme CBigNumBoringSSL
  -destination generic/platform=iOS`).
- **Swift** 6.2.4 (`swiftlang-6.2.4.1.4`, `clang-1700.6.4.2`), default
  target `arm64-apple-macosx26.0`. Used for the two native macOS builds
  (`--triple x86_64-apple-macosx` and `arm64-apple-macosx`).
- **Swift in Docker**: `swift:6.3-noble` (pulled on first run). Used for
  both `linux/arm64` and `linux/amd64` builds.

### Toolchain utilities invoked by the script
- **Go** 1.26.2 (`darwin/arm64`). Runs the vendored
  `scripts/vendored-util/{read_symbols,make_prefix_headers}.go`; `go mod
  tidy -modcacherw` is executed inside `$SRCROOT` so the clone's own
  `go.mod` resolves imports.
- **Perl** 5.34.1 (`darwin-thread-multi-2level`). Drives all BoringSSL
  `perlasm` scripts via `scripts/build-asm.py`, and is also used for the
  `#define BORINGSSL_PREFIX` injection into `base.h`.
- **Python** 3.14.4. Runs `scripts/build-asm.py` (the shebang is
  `#!/usr/bin/env python3`; the vendoring script also calls `python3`
  explicitly).
- **GNU sed** (`gsed`) 4.9. The script selects `gsed` on Darwin and
  `sed` elsewhere (`sed=gsed` / `sed=sed`); both `MANGLE_START` toggling
  and the include-rewriting `-r` regex require GNU semantics. Install via
  `brew install gnu-sed`.
- **LLVM binutils from Xcode**: `nm` / `c++filt` (both Apple LLVM 17.0.0,
  shipped with Xcode). `nm -gUj` + `c++filt` drives the
  `mangle_cpp_structures` pass. `ar` (Apple `ar`, also from Xcode) is used
  to roll the iOS `.o` into `libCBigNumBoringSSL-iosarm64.a`.
- **Git** 2.50.1 (Apple Git-155). `git clone --depth 1 --branch
  0.20260327.0`, plus `git apply` for the three inttypes patches.

### Docker
- **Docker** 29.3.1 (Docker Desktop), server 29.3.1, Linux OSType, host
  arch `aarch64`. Used for both Linux Swift builds via
  `--platform linux/{arm64,amd64}`. QEMU emulation handles `linux/amd64`
  on the arm64 host (ensure "Use Rosetta for x86_64/amd64 emulation" or
  `binfmt_misc` is enabled in Docker Desktop).

### Not used by the vendoring script itself, but relevant
- `swift test` (host macOS) is used to verify the 23 unit tests pass after
  vendoring.
- `docker run --rm -v "$(pwd)":/src -w /src --platform linux/arm64
  swift:6.3-noble swift test` is the same mechanism used to verify Linux
  parity; it re-uses the same `swift:6.3-noble` image pulled during
  vendoring.


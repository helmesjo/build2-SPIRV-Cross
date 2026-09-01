# libspirv-cross - SPIR-V to GLSL/HLSL/MSL/C++ cross-compiler library

This is a `build2` package for the [`SPIRV-Cross`](https://github.com/KhronosGroup/SPIRV-Cross)
C++ library. It parses SPIR-V binaries and cross-compiles them to GLSL, HLSL,
MSL (Metal Shading Language), or back to a SPIR-V-flavored C++ representation,
and can also emit JSON reflection data describing a shader's resources.


## Usage

To start using `libspirv-cross` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libspirv-cross ^1.4.357
```

Then import the library target(s) you need in your `buildfile`, for example:

```
import libs = libspirv-cross%liba{spirv-cross-glsl}
```

Only import what you use. Importing `liba{spirv-cross-msl}` pulls in
`liba{spirv-cross-glsl}` and `liba{spirv-cross-core}` transitively.

The C API is a `lib{}` group. `config.bin.lib` selects the static or shared
member:

```
import c_libs = libspirv-cross%lib{spirv-cross-c}
```


## Importable targets

C++ backends are `liba{}` (the C++ API is not ABI-stable, matching upstream
static-only libraries). The C API is `lib{spirv-cross-c}` (static and shared).

```
liba{spirv-cross-core}      always available
liba{spirv-cross-glsl}      available if config.libspirv_cross.glsl    (default true)
liba{spirv-cross-hlsl}      available if config.libspirv_cross.hlsl    (default true, requires glsl)
liba{spirv-cross-msl}       available if config.libspirv_cross.msl     (default true, requires glsl)
liba{spirv-cross-cpp}       available if config.libspirv_cross.cpp     (default true, requires glsl)
liba{spirv-cross-reflect}   available if config.libspirv_cross.reflect (default true, requires glsl)
liba{spirv-cross-util}      available if config.libspirv_cross.util    (default true)
lib{spirv-cross-c}          available if config.libspirv_cross.c_api   (default true)
```

The shared C API is versioned with the C ABI from `spirv_cross_c.h`
(`SPVC_C_API_VERSION_*`, currently 0.68.0, SONAME major 0), not the Vulkan
SDK package version. Pre-release builds use a snapshot suffix instead so
they cannot overwrite a final ABI-named library.

Public headers install to `include/spirv_cross/`, reachable both as
`<spirv_cross/spirv_msl.hpp>` (qualified) and as `<spirv_msl.hpp>`
(unqualified, matching upstream pkg-config). C++ backend runtime headers
(`external_interface.h`, `image.hpp`, and related) are not installed,
matching upstream CMake. Generated C++ shaders that include them need those
headers from the source tree, and `image.hpp` includes `<glm/glm.hpp>`.


## Configuration variables

This package provides the following configuration variables:

```
config [bool]   config.libspirv_cross.glsl      ?= true
config [bool]   config.libspirv_cross.hlsl      ?= true
config [bool]   config.libspirv_cross.msl       ?= true
config [bool]   config.libspirv_cross.cpp       ?= true
config [bool]   config.libspirv_cross.reflect   ?= true
config [bool]   config.libspirv_cross.util      ?= true
config [bool]   config.libspirv_cross.c_api     ?= true
config [string] config.libspirv_cross.namespace ?= ''
```

The seven boolean variables mirror upstream's `SPIRV_CROSS_ENABLE_*` CMake
options one-to-one (same defaults: all on) and each controls whether the
matching library target is built. Upstream requires GLSL support
to build HLSL, MSL, C++, or JSON reflection support. This package enforces
the same constraint.

`config.libspirv_cross.namespace` mirrors upstream's
`SPIRV_CROSS_NAMESPACE_OVERRIDE` CMake option. When non-empty, it renames the
`spirv_cross` C++ namespace so multiple statically-linked copies can coexist.

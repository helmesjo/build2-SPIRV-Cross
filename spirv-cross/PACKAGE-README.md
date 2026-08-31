# spirv-cross - SPIR-V to GLSL/HLSL/MSL/C++ command line cross-compiler

This is a `build2` package for the [`SPIRV-Cross`](https://github.com/KhronosGroup/SPIRV-Cross)
executable. It is a command line tool that parses SPIR-V binaries and
cross-compiles them to GLSL, HLSL, MSL, or C++, and can emit JSON reflection.

Note that the `spirv-cross` executable in this package provides `build2` metadata.


## Usage

To start using `spirv-cross` in your project, add the following build-time
`depends` value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: * spirv-cross ^1.4.357
```

Then import the executable in your `buildfile`:

```
import! [metadata] spirv_cross = spirv-cross%exe{spirv-cross}
```


## Importable targets

This package provides the following importable targets:

```
exe{spirv-cross}
```

The command line client. It requires every `libspirv-cross` backend plus util
(same constraint as upstream CMake).


## Configuration variables

This package provides no configuration variables.

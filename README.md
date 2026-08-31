# SPIRV-Cross - SPIR-V to GLSL/HLSL/MSL/C++ cross-compiler

This is a `build2` package repository for [`SPIRV-Cross`](https://github.com/KhronosGroup/SPIRV-Cross),
a library and command line tool that parses SPIR-V and cross-compiles it to
GLSL, HLSL, MSL, C++, or JSON reflection.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`SPIRV-Cross` in your `build2`-based project, then instead see the accompanying
[`libspirv-cross/PACKAGE-README.md`](libspirv-cross/PACKAGE-README.md) and
[`spirv-cross/PACKAGE-README.md`](spirv-cross/PACKAGE-README.md) files.

The development setup for `SPIRV-Cross` uses the standard `bdep`-based workflow.
For example:

```
git clone .../SPIRV-Cross.git
cd SPIRV-Cross

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```

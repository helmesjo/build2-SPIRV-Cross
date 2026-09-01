#include <cstdio>
#include <string>
#include <vector>

#include <spirv_cross/spirv_glsl.hpp>

#undef NDEBUG
#include <cassert>

using namespace std;

// Mirrors upstream's own main.cpp read_spirv_file() helper.
//
static vector<uint32_t>
read_spirv_file (const char* path)
{
  FILE* file = fopen (path, "rb");
  assert (file != nullptr);

  fseek (file, 0, SEEK_END);
  size_t len = size_t (ftell (file)) / sizeof (uint32_t);
  rewind (file);

  vector<uint32_t> spirv (len);
  size_t n = fread (spirv.data (), sizeof (uint32_t), len, file);
  assert (n == len);

  fclose (file);
  return spirv;
}

int main (int argc, char* argv[])
{
  assert (argc == 2);

  vector<uint32_t> spirv_binary (read_spirv_file (argv[1]));
  assert (!spirv_binary.empty ());

  // SPIRV_CROSS_NAMESPACE resolves to config.libspirv_cross.namespace when
  // set (see spirv_cross_error_handling.hpp).
  //
  SPIRV_CROSS_NAMESPACE::CompilerGLSL glsl (move (spirv_binary));

  // Calls into the non-inline Compiler/CompilerGLSL API, verifying symbol
  // export from the built spirv-cross-glsl (and transitively -core) library.
  //
  string source = glsl.compile ();
  assert (!source.empty ());
}

// Handle --build2-metadata in main() (see also buildfile).

#define main xmain
#include "main.cpp"
#undef main

#include <cstring>
#include <iostream>

int
main (int argc, char** argv)
{
  if (argc == 2 && strncmp (argv[1], "--build2-metadata=", 18) == 0)
  {
    std::cout
      << "# build2 buildfile spirv-cross\n"
      << "export.metadata = 1 spirv_cross\n"
      << "spirv_cross.name = [string] spirv-cross\n"
      << "spirv_cross.version = [string] " << SPIRVCROSS_PKG_VERSION << '\n';
    return 0;
  }

  return xmain (argc, argv);
}

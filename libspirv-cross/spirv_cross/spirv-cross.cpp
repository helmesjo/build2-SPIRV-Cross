#include <spirv_cross/spirv-cross.hpp>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace spirv_cross
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}

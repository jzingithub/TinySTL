#include <cstdlib>
#include "TinySTL_Allocator.h"

using namespace TinySTL;

int main(int argc, char **argv)
{
  Allocator<int> intAlloc;
  int i = 0;
  int &ri = i;
  const int &kri = 0;
  auto address = intAlloc.Address(ri);
  auto kAddress = intAlloc.ConstAddress(kri);
  auto maxSize = intAlloc.MaxSize();

  std::system("pause");
  return 0;
}
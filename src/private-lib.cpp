#include <private-lib.hpp>

#include <iostream>

namespace detail
{
  void printHello()
  {
    std::cout << "Hello ";
  }

  void printWorld()
  {
    std::cout << "World" << std::endl;
  }
}

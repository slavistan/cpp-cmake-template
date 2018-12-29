// Include the prohject's public header
#include <my-example-project/mylib.hpp>

// Include another header which is not part of the project's public interface but is only required to build this
// library.
#include <private-lib.hpp>

#include <iostream>
namespace foo
{

void printHelloWorld()
{
  detail::printHello();
  detail::printWorld();
}

} // foo::

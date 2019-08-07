#pragma once

#include <iostream>

#include <bookshelf-core.hpp>

namespace SaltShaker::Clock
{

template <typename T = int>
void bar()
{
  std::cout << "'SaltShaker::Clock()' here!" << std::endl;
  saltshaker::bookshelf::foo();
}

}

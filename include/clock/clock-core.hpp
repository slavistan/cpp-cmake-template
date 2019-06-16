#pragma once

#include <bookshelf-core.hpp>

#include <iostream>

namespace SaltShaker::Clock
{

template <typename T = void>
void bar()
{
  std::cout << "'SaltShaker::Clock()' here!" << std::endl;
}

}

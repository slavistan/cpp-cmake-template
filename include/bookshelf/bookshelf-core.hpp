#pragma once

#include <iostream>

namespace SaltShaker::BookShelf
{

template <typename T = int, typename U = double>
void foo(T&& t = 100, U&& u = 3.14)
{
  std::cout << "You called 'SaltShaker::BookShelf()'" << std::endl;
}

}

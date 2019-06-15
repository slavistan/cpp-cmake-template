#pragma once

#include <iostream>

template <typename T = int, typename U = double>
void foo(T&& t = 100, U&& u = 3.14)
{
  std::cout << "Arg T = " << t << std::endl;
  std::cout << "Arg U = " << u << std::endl;
}

#include <bookshelf-core.hpp>
#include <clock-core.hpp>

#include <iostream>

auto lambda = [](int a) { return a; };
auto genlambda = [](auto a) { return a; };

int main()
{
  std::cout << "Hello World!" << std::endl;
  std::cout << "a = " << lambda(44) << std::endl;
  std::cout << "b = " << lambda(43) << std::endl;
}

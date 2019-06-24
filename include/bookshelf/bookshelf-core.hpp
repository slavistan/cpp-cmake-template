#pragma once

#include <iostream>

namespace saltshaker::bookshelf
{

class MyClass {
  public:
    const int defaultAge = 24;
    int age = defaultAge;
};

template <typename CamelCase = void>
void foo() {}

template <typename T = int, typename U = double>
void foo(T&& t, U&& u)
{
  const int x = 314;
  if ( t == x ) {
    std::cout << "yo";
  }

  std::cout << "You called 'saltShaker::bookshelf::foo()'" << std::endl;
  std::cout << "t = " << t << ", y = " << u << std::endl;
}

}

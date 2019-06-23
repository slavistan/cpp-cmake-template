#include <iostream>

#include <bookshelf-core.hpp>
#include <clock-core.hpp>

#include <Eigen/Dense>

auto lambda = [](int a) { return a; };
auto genlambda = [](auto a) { return a; };

int main()
{

  auto mat = Eigen::MatrixXd(2, 2);

  SaltShaker::BookShelf::foo();
  SaltShaker::Clock::bar();

  std::cout << "Hello World!" << std::endl;
  std::cout << "a = " << lambda(44) << std::endl;
  std::cout << "b = " << genlambda(43) << std::endl;
}

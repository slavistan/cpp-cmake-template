#include <gsl/gsl>

#include <iostream>

class Foo
{
 private:
  void
  privFunc_()
  {
  }
  int priv_ar_ = 1;

 public:
  Foo()
  {
  }

  explicit Foo(int n) {}

  void pubFunc() {}
  int pub_ar2 = 2;
};

int
main()
{
  Foo f1;
  auto f2 = Foo();
  auto f3 = Foo{};
  Foo f4{};

  Foo f5(2);
  auto f6 = Foo(2);
  auto f7 = Foo{2};
  Foo f8{2};

  return 1;
}

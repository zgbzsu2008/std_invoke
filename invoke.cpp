#include <functional>
#include <iostream>

struct A {
 public:
  A(int num) : num_(num) {}
  void print_add(int i) const { std::cout << "num= " << num_ + i << '\n'; }
  int num_;
};

void print(int i) { std::cout << "i= " << i << '\n'; }

struct B {
  void operator()(int i) { std::cout << "i= " << i << '\n'; }
};

int main() {
  std::invoke(print, 2);

  std::invoke([] { print(3); });

  A a(5);
  std::invoke(&A::print_add, a, 8);

  std::cout << "a.num_ = " << std::invoke(&A::num_, a) << '\n';

  using namespace std::placeholders;

  auto f = std::bind(print, _1);
  std::invoke(f, 2, 3, 4);  // Å×Æú²ÎÊı3£¬4

  return 0;
}
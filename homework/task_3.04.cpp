#include <cassert>
#include <iostream>


class Tester1;

class Entity {
  private:

    friend Tester1;
    friend class Tester2;

    static int sum(int a, int b) {
      return a + b;
    }

    static int mult(int a, int b) {
      return a * b;
    }
};

class Tester1 {
  public:
    static void test() {
      std::cout << Entity::sum(2, 3) << '\n';
    }
};

class Tester2 {
  public:
  static void test() {
    std::cout << Entity::mult(2, 3) << '\n';
  }
};

int main() {
  Tester1 t1 = Tester1();
  Tester2 t2 = Tester2();
  t1.test();
  t2.test();
}

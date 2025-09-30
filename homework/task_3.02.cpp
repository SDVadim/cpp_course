#include <numeric>
#include <iostream>
#include <cmath>

class Circle {
  public:
    Circle(double r) : radius(r) {}

    double square() {
      return M_PI * radius * radius;
    }

    double area() {
      return 2 * M_PI * radius;
    }
    
    ~Circle() {}

  private:
    double radius;
};

class Triangle {
  public:
    Triangle(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}

    double square() {
      double p = (a + b + c) / 2;
      return (std::sqrt(p * (p - a) * (p - b) * (p - c)));
    }

    double area() {
      return a + b + c;
    }

    ~Triangle() {}

  private:
    double a;
    double b;
    double c;
};

class Square {
  public:
    Square(double a_) : a(a_) {}

    double square() {
      return a * a;
    }

    double area() {
      return a * 4;
    }

  private:
    double a;
};

int main() {
  Triangle triangle = Triangle(3, 4, 5);
  std::cout << "area: " << triangle.area() << " square: " << triangle.square() << '\n';

  Circle circle = Circle(10);
  std::cout << "area: " << circle.area() << " square: " << circle.square() << '\n';

  Square square = Square(10);
  std::cout << "area: " << square.area() << " square: " << square.square() << '\n';
}
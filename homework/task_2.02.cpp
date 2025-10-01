#include <iostream>

int main()
{
  double const epsilon = 10e-6;
  double a = 0, b = 0, c = 0;
  std::cin >> a >> b >> c;
  if (std::abs(a) < epsilon)
  {
    if (std::abs(b) > epsilon) 
    {
      double result = -c / b;
      std::cout << "Решение линейного уравнения: " << result << '\n';
    }
    else 
    {
      std::cout << "Данное уравнение не имеет решения" << '\n';
    }
  }
  else
  {
    double D = b*b - 4 * a * c;
    if (D < 0)
    {
      std::cout << "Данное уравнение не имеет решения" << '\n';
    }
    else if (D < epsilon)
    {
      double x = -b / (2 * a);
      std::cout << "Корень квадратного уравнения: " << x << '\n';
    }
    else
    {
      double x1 = (-b - std::sqrt(D)) / (2 * a);
      double x2 = (-b + std::sqrt(D)) / (2 * a);
      std::cout << "Решение квадратного уравнения: " << x1 << " " << x2 << '\n';
    }
  }
}
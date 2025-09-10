#include <iostream>
#include <numbers>
#include <cmath>

int fibb(int n)
{
  double sqrt_5 = std::sqrt(5);
  double phi = (1 + sqrt_5) / 2;
  int fibb {static_cast <int> ((std::pow(phi, n) - std::pow(-phi, -n)) / sqrt_5)};
  return fibb;
}

int main()
{
  int N;
  std::cin >> N;
  int result = fibb(N);
  std::cout << N << "ое число фибоначи равно " << result << '\n';
}


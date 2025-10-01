#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

  std::cout << "Введите количество элементов\n";
  double sum = 0;
  size_t len = 0;
  std::cin >> len;
  int* array = new int[len]{};
  for(size_t i = 0; i < len; ++i) {
    std::cin >> array[i];
  }
  double min = array[0];
  double max = -1e10;
  double avg = sum / len;
  double shift = 0;
  for (size_t i = 0; i < len; ++i)
  {
    double val = array[i];
    min = std::min(min, val);
    max = std::max(max, val);
    shift = (val - avg) * (val - avg);
  }
  shift = std::sqrt(shift / len);
  std::cout << "min: " << min << "\nmax: " << max << "\navg: " << avg << "\nshift:" << shift << '\n';
}
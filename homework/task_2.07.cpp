#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::cout << "Count:\n";
  double sum = 0;
  size_t len = 0;
  std::cin >> len;
  int* array = new int[len]{};
  for(size_t i = 0; i < len; ++i) {
    int val = 0;
    std::cin >> val;
    array[i] = val;
    sum += val;
  }
  double min = array[0];
  double max = array[0];
  double avg = sum / len;
  double shift = 0;
  for (size_t i = 1; i < len; ++i)
  {
    double val = array[i];
    min = std::min(min, val);
    max = std::max(max, val);
  }
  for(size_t i = 0; i < len; ++i) {
    int val = array[i];
    shift += (val - avg) * (val - avg);
  }
  shift = std::sqrt(shift / len);
  std::cout << "min: " << min << "\nmax: " << max << "\navg: " << avg << "\nshift:" << shift << '\n';
  delete[] array;
}
#include <iostream>

int main() 
{
  std::size_t size = 8;
  double array[1024]{ 1, 2, 1, 6, 7, 3, 8, -9};
  double min = *array;
  double max = 0;
  double sum = 0;
  for (std::size_t i = 0; i < size; ++i)
  {
    min = std::min(min, array[i]);
    max = std::max(max, array[i]);
    sum += array[i];
  }
  double avg = sum / size;
  double s = 0;
  for (std::size_t i = 0; i < size; ++i)
  {
    s += (array[i] - avg) * (array[i] - avg);
  }
  s = std::sqrt(s / size);
  std::cout << "min: " << min << " max: " << max << " avg: " << avg << " s " << s;
}

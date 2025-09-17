#include <iostream>
#include <vector>

int main()
{
  std::vector<double> array;
  std::cout << "Введите циферки через пробел, закончите нулем\n";
  double sum = 0;
  while (true)
  {
    double a;
    std::cin >> a;
    sum += a;
    if (a == 0)
    {
      break;
    }
    array.push_back(a);
  }
  std::size_t const size = array.size();
  double min = array[0];
  double max = -1e10;
  double avg = sum / size;
  double shift = 0;
  for (std:: size_t i = 0; i < size; ++i)
  {
    min = std::min(min, array[i]);
    max = std::max(max, array[i]);
    shift = (array[i] - avg) * (array[i] - avg);
  }
  shift = std::sqrt(shift / size);
  std::cout << "min: " << min << "\nmax: " << max << "\navg: " << avg << "\nshift:" << shift << '\n';
}
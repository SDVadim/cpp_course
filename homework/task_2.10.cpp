#include <iostream>
#include <vector>

int partition(std::vector<int>& array, int l, int r) {
  int pivot = (l + r) / 2;
  while (l <= r) {
    while (array[l] < array[pivot]) {
      l++;
    }
    while (array[r] > array[pivot]) {
      r--;
    }
    if (l >= r) return r;
    std::swap(array[l], array[r]);
    l++;
    r--;
  }
  return r;
}

void quickSort(std::vector<int>& array, int l, int r) {
  if (l >= r) return;
  int pivot = partition(array, l, r);
  quickSort(array, l, pivot);
  quickSort(array, pivot + 1, r);
}

int main() {
  std::vector<int> array;
  std::cout << "Введите циферки через пробел, закончите нулем\n";
  while (true) {
    int a;
    std::cin >> a;
    if (a == 0) {
      break;
    }
    array.push_back(a);
  }
  quickSort(array, 0, array.size() - 1);

  for (int i : array) {
    std::cout << i << " ";
  }

}


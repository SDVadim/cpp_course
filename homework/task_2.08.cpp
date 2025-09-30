#include <iostream>
#include <vector>

std::size_t findSize(unsigned long long int a, std::vector<std::size_t>& cache) {
  std::size_t len = 0;
  if (cache[a] != 0) {
    len = cache[a];
    return cache[a];
  }
  if (a % 2 == 0) {
    len = findSize(a / 2, cache) + 1;
    cache[a] = len;
  } else {
    len = findSize(a * 3 + 1, cache) + 1;
    cache[a] = len;
  }
  return cache[a];
}

int main() {
  std::vector<std::size_t> cache = std::vector<std::size_t>(1e4);
  cache[1] = 1;
  int i = 0;
  while (i <= 100) {
    i++;
    if (cache[i] != 0) {
      continue;
    }
    cache[i] = findSize(i, cache);
  }
  std::size_t max = 0;
  int max_i = 0;
  for (int i = 1; i <= 100; ++i) {
    if (max < cache[i]) {
      max = cache[i];
      max_i = i;
    }

    std::cout << "i: " << i << " " << cache[i] << '\n';
  }
  std::cout << "max_i: " << max_i << " max: " << max << '\n';
}


#include <algorithm>
#include <cstdio>

int main() {
  int number;
  int min_number = INT_MAX;
  int max_number = INT_MIN;

  while (scanf("%d", &number) != EOF) {
    min_number = std::min(min_number, number);
    max_number = std::max(max_number, number);
  }

  printf("min: %d\nmax: %d\n", min_number, max_number);

  return 0;
}

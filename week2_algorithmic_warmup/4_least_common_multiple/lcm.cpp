#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
long long lcm_algo(int a, int b) {
	if (!a || !b) return 0;
	int Min = (a <= b) ? a : b;
	int Max = (a > b) ? a : b;
	long long Total = Max;
	while (1) {
		if (!(Total % Min)) {
			return Total;
		}
		Total += static_cast<long long>(Max);
	}
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_algo(a, b) << std::endl;
  return 0;
}

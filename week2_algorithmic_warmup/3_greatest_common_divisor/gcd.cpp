#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_Euclids(int a, int b) {
	if (!a || !b) return 1;
	while (1) {
		int& Max_Val = (a >= b) ? a : b;
		int& Min_Val = (a < b) ? a : b;
		int Mod_Val  = Max_Val % Min_Val;
		if (!Mod_Val) return Min_Val;
		Max_Val = Mod_Val;
	}
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_Euclids(a, b) << std::endl;
  return 0;
}

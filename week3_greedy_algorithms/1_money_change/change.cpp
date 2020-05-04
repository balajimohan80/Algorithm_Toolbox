#include <iostream>
#include <vector>

int get_change(int m) {
	std::vector<int> Coins = { 10, 5, 1 };
	int Total_Coins = 0;
	for (int i = 0; i < Coins.size(); i++) {
		if (!m) break;
		Total_Coins += (m / Coins[i]);
		m = m % Coins[i];
	}
	return Total_Coins;
}


int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

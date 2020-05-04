#include<iostream>
#include<utility>
#include<vector>


int get_change(int m) {
	std::vector<int> Combination(m + 1, m + 1);
	std::vector<int> Coins = { 1,3,4 };
	Combination[0] = 0;
	for (auto i = 1; i < Combination.size(); i++) {
		for (auto j : Coins) {
			if (i >= j) {
				auto Temp = Combination[i - j] + 1;
				Combination[i] = (Temp < Combination[i]) ? Temp: Combination[i];
			}
			else break;
		}
	}
	return Combination[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

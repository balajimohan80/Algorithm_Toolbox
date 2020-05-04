#include <iostream>
#include <vector>
#include <algorithm>


long long MaxPairwiseProduct(const std::vector<int>& num) {
    const int n = num.size();
	if (!n) return 0;
	int Max_1 = std::numeric_limits<int>::min();
	int Max_2 = Max_1;
	for (int i = 0; i < n; i++) {
		if (Max_1 < num[i]) {
			Max_2 = Max_1;
			Max_1 = num[i];
			continue;
		}
		if (Max_2 < num[i] && num[i] <= Max_1) {
			Max_2 = num[i];
		}
	}
	long long Res = static_cast<long long>(Max_1) * static_cast<long long>(Max_2);
    return Res;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}
	long long Res = MaxPairwiseProduct(numbers);
	std::cout << Res << "\n";
	return 0;
}

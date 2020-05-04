#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {

	int n;
	n = numbers.size();
	int max1 = -1;
	for (int i = 0; i < n; i++)
		if ((max1 == -1) || (numbers[i] > numbers[max1]))
			max1 = i;

	int max2 = -1;
	for (int j = 0; j < n; j++)
		if ((j != max1) && ((max2 == -1) || (numbers[j] > numbers[max2])))
		max2 = j;
	return ((long long)(numbers[max1])) * numbers[max2];
}

long long MaxPairwiseProduct_Balu(const std::vector<int>& num) {
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
void Display_V(std::vector<int>& Num) {
	for (int i = 0; i < Num.size(); i++)
		std::cout << Num[i] << " ";
	std::cout << std::endl;
}

int main() {
    int n;
#if 1
	while (1) {
		n = rand();
		std::vector<int> Num(n);

		for (int i = 0; i < n; i++)
			Num[i] = rand();
		long long Res_1 = MaxPairwiseProduct(Num);
		long long Res_2 = MaxPairwiseProduct_Balu(Num);
		if (Res_1 != Res_2) {
			Display_V(Num);
			std::cout << "Res_1: " << MaxPairwiseProduct(Num) << " Res_2: " << MaxPairwiseProduct_Balu(Num) << std::endl;
			break;
		}
		else {
			std::cout << "Matched: " << n << std::endl;
		}
	}
#else
#if 0
    std::cin >> n;
    std::vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}
#else
	std::vector<int> numbers = { 2327, 9974, 20567, 490, 32766, 14728, 27906, 32766, 5569, 9095 };
	n = numbers.size();
#endif
	
	long long Res_1 = MaxPairwiseProduct(numbers);
	long long Res_2 = MaxPairwiseProduct(numbers);

	std::cout << Res_2 << "\n";
#endif	
	return 0;
}

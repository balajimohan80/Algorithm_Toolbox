#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Knap_Sack {
	double Wei_Per_Val;
	int Max_Weight;
};

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double Value = 0.0;
	vector<Knap_Sack> Calc_Val(weights.size());
	for (int i = 0; i < weights.size(); i++) {
		Calc_Val[i].Wei_Per_Val = static_cast<double>(values[i]) / static_cast<double>(weights[i]);
		Calc_Val[i].Max_Weight = weights[i];
	}
	std::sort(Calc_Val.begin(), Calc_Val.end(), [](const Knap_Sack& a, const Knap_Sack& b) {return a.Wei_Per_Val > b.Wei_Per_Val; });

	for (int i = 0; i < Calc_Val.size(); i++) {
		if (capacity <= Calc_Val[i].Max_Weight) {
			Value += (Calc_Val[i].Wei_Per_Val * static_cast<double>(capacity));
			break;
		}
		Value += (Calc_Val[i].Wei_Per_Val * static_cast<double>(Calc_Val[i].Max_Weight));
		capacity -= Calc_Val[i].Max_Weight;
	}
	return Value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}


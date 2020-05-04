#include <iostream>
#include <vector>

using std::vector;

bool Partition_into_K_Subset_Sum(int Index, const vector<int>& Num, vector<bool>& Cache, unsigned int Computed_Sum, const unsigned int Targeted_Sum, unsigned int K) {
	if (K == 1) return true;
	if (Targeted_Sum == Computed_Sum) {
		return Partition_into_K_Subset_Sum(0, Num, Cache, 0, Targeted_Sum, K - 1);
	}

	for (int i = 0; i < Num.size(); i++) {
		if (!Cache[i] && (Computed_Sum + Num[i] <= Targeted_Sum)) {
			Cache[i] = true;
			if (Partition_into_K_Subset_Sum(i + 1, Num, Cache, Computed_Sum + Num[i], Targeted_Sum, K)) {
				return true;
			}
			Cache[i] = false;
		}
	}
	return false;
}

int partition3(vector<int> &Num) {
	unsigned int Total_Sum = 0l;
	for (auto i : Num) {
		Total_Sum += i;
	}
	const unsigned int K = 3;
	if (Total_Sum % K) return false;
	Total_Sum /= K;
	vector<bool> Cache(Num.size(), 0);
	return Partition_into_K_Subset_Sum(0, Num, Cache, 0, Total_Sum, K);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}


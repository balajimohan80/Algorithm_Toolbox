#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
	vector<int> summands;
	int i = 0;
	while (n > i) {
		++i;
		summands.push_back(i);
		n = n - i;
	}
	if (n) {
		int Temp = summands.back() + n;
		summands.pop_back();
		summands.push_back(Temp);
	}
	return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}

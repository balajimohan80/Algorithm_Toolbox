#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

#if 0
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 2 == 0) {
      n /= 2;
    } else if (n % 3 == 0) {
      n /= 3;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
#endif

inline int Min(int a, int b) {
	return (a < b) ? a : b;
}
vector<int> optimal_sequence(int n) {
	vector<int> Sequence;

	//int[] arr = new int[n + 1];
	vector<int> Arr(n + 1);
	for (int i = 1; i < Arr.size(); i++) {
		Arr[i] = Arr[i - 1] + 1;
		if (i % 2 == 0) Arr[i] = Min(1 + Arr[i / 2], Arr[i]);
		if (i % 3 == 0) Arr[i] = Min(1 + Arr[i / 3], Arr[i]);

	}

	for (int i = n; i > 1; ) {
		Sequence.push_back(i);
		if (Arr[i - 1] == Arr[i] - 1)
			i = i - 1;
		else if (i % 2 == 0 && (Arr[i / 2] == Arr[i] - 1))
			i = i / 2;
		else if (i % 3 == 0 && (Arr[i / 3] == Arr[i] - 1))
			i = i / 3;
	}
	Sequence.push_back(1);

	reverse(Sequence.begin(), Sequence.end());
	return Sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}

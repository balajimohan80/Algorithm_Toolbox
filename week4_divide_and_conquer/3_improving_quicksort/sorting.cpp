#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include "Timer.hpp"

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

std::pair<int, int> partition3(vector<int>& Num, int Low, int High) {
	/*
	if (High - Low <= 1) {
		if (Num[High] < Num[Low])
			swap(Num[High], Num[Low]);
		return std::pair<int, int>(Low, High);
	}*/
	int Data = Num[High];
	int i = Low;
	int j = High;
	int Count = Low;
	while (Count <= j) {
		if (Num[Count] < Data) {
			swap(Num[i++], Num[Count++]);
		}
		else if (Num[Count] == Data) {
			Count++;
		}
		else {
			swap(Num[Count], Num[j--]);
		}
	}
	return std::pair<int, int>(i - 1, j);
}


void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}


void randomized_quick_sort_1(vector<int>& a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[r], a[k]);
	std::pair<int, int> Index = partition3(a, l, r);

	randomized_quick_sort_1(a, l, Index.first);
	randomized_quick_sort_1(a, Index.second, r);
}


int main() {
#if 0
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort_1(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
#else
	while (1) {
		int n = rand() % 1000000;
		vector<int> Num_1(n);
		vector<int> Num_2(n);
		double Sort_1, Sort_2;
		for (size_t i = 0; i < n; i++) {
			int Temp = rand() % 1000;
			Num_1[i] = Temp;
			Num_2[i] = Temp;
		}
		{
			Timer T1("2Way_Sort");
			randomized_quick_sort(Num_1, 0, Num_1.size() - 1);
			Sort_1 = T1.Get_Compute_Time_ms();
		}
		//std::sort(Num_1.begin(), Num_1.end(), [](int a, int b) { return a < b; });
		for (size_t i = 0; i < Num_1.size(); ++i) {
			std::cout << Num_1[i] << ' ';
		}
		std::cout << "\n";
		{
			Timer T1("3Way_Sort");
			randomized_quick_sort_1(Num_2, 0, Num_2.size() - 1);
			Sort_2 = T1.Get_Compute_Time_ms();
		}
		for (size_t i = 0; i < Num_2.size(); ++i) {
			std::cout << Num_2[i] << ' ';
		}
		std::cout << "\n";
		if (Num_1 != Num_2) {
			std::cout << "Not Matching!!!!!!!!\n";
			break;
		}

		if ((Sort_2 - Sort_1) > std::chrono::duration<double, std::ratio<1,1000>>(1).count()) {
			std::cout << "Computation Time on Sort2 is increased!!!!!";
			break;
		}
		break;
    }
#endif
}

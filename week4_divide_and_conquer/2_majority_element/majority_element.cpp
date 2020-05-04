#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;



int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left+1 == right) return -1;
  //if (left + 1 == right) return a[left];
  //write your code here
  std::sort(a.begin(), a.end(), [](int a, int b) {return a < b; });
  int Mid = a.size() >> 1;
  int Count = 0;
  while (Mid-1 >= 0 && a[Mid] == a[Mid-1]) {
	  ++Count;
	  --Mid;
  }
  Mid = a.size() >> 1;
  while (Mid + 1 < a.size() && a[Mid] == a[Mid + 1]) {
	  ++Count;
	  ++Mid;
  }

  return (Count >= (a.size() >> 1)) ? 1 : -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

#include <iostream>
#include <vector>

using std::vector;

int max(int i1, int i2) {
	return i1 > i2 ? i1 : i2;
}
int lcs(vector<vector<int>> &c,vector<int> &x, vector<int> &y, int i, int j) {
	if (i < 0 || j < 0) return 0;
	if (c[i][j] == 0) {
		if (x[i] == y[j]) {
			c[i][j] = lcs(c, x, y, i - 1, j - 1) + 1;
		} 
		else {
			c[i][j] = max(lcs(c, x, y, i - 1, j), lcs(c, x, y, i, j - 1));
		}
	}
	return c[i][j];
}

int lcs2(vector<int>& x, vector<int>& y) {
	vector<vector<int>> c(x.size() + 1);
	for (int i = 0; i <= x.size(); i++) {
		c[i] = vector<int>(y.size() + 1, 0);
	}
	return lcs(c, x, y, x.size()-1, y.size()-1);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}

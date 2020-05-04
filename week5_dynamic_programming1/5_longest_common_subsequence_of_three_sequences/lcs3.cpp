#include <iostream>
#include <vector>
#include <cstring>

using std::vector;

int Max(int X, int Y, int Z) {
	int Temp = X > Y ? X : Y;
	return Temp > Z ? Temp : Z;
}

#if 1
int lcs3(vector<int> &X, vector<int> &Y, vector<int> &Z) {
	vector<vector<vector<int>>> C(X.size() + 1);

	for (int i = 0; i <= X.size(); i++)
		C[i] = vector<vector<int>>(Y.size() + 1);
	for (int i = 0; i <= X.size(); i++)
		for (int j = 0; j <= Y.size(); j++)
		C[i][j] =vector<int>(Z.size() + 1, 0);


	for (int i = 1; i <= X.size(); i++) {
		for (int j = 1; j <= Y.size(); j++) {
			for (int k = 1; k <= Z.size(); k++) {
				if (X[i - 1] == Y[j - 1] && Y[j- 1] == Z[k- 1]) {
					C[i][j][k] = C[i-1][j-1][k-1] + 1;
				}
				else {
					C[i][j][k] = Max(C[i - 1][j][k], C[i][j - 1][k], C[i][j][k - 1]);
				}
			}
		}
	}

	return C[X.size()][Y.size()][Z.size()];
}
#else
int lcs(const vector<int> &X, const vector<int> &Y, const vector<int> &Z, int i, int j, int k) {
	if (i == 0 || j == 0 || k == 0)
		return 0;
	if (X[i] == Y[j] && X[i] == Z[k]) {
		return 
	}
}

int lcs3(vector<int>& X, vector<int>& Y, vector<int>& Z) {

}
#endif

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}

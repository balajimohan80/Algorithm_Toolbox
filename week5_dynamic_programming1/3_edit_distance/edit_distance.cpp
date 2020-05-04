#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

int Min(int x, int y, int z) {
	int Temp = (x < y) ? x : y;
	return (Temp < z) ? Temp : z;
}

int edit_distance(const string &str1, const string &str2) {
	vector<vector<int >> DP(str1.length()+1);
	for (int i = 0; i < str1.length()+1; i++)
		DP[i] = vector<int>(str2.length()+1);

	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			if (!i && !j) DP[i][j] = 0;
			else if (!i) DP[i][j] = j;
			else if (!j) DP[i][j] = i;
			else if (str1[i - 1] == str2[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1];
			} else {
				DP[i][j] = Min(DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]) + 1;
			}
		}
	}
	return DP[str1.length()][str2.length()]; 
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

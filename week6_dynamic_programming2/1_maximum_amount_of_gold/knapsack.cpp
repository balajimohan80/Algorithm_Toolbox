#include <iostream>
#include <vector>

using std::vector;

/* 
   Note: To get better understanding, please refer
   https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/RM1BDv71V60
*/

#if 0
int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}
#endif

int max(int i1, int i2) {
	return (i1 > i2) ? i1 : i2;
}

int Knap_Sack_Top_Down_Recur(vector<vector<int>> &DP, const vector<int>& W, int Total_Weight, int Index) {
	if (Total_Weight <= 0 || Index >= W.size())
		return 0;
	int Max_Weight_1 = 0;
	if (DP[Index][Total_Weight] != -1)
		return DP[Index][Total_Weight];

	if (Total_Weight >= W[Index]) {
		Max_Weight_1 = W[Index] +
			Knap_Sack_Top_Down_Recur(DP, W, Total_Weight - W[Index], Index + 1);
	}

	int Max_Weight_2 = Knap_Sack_Top_Down_Recur(DP, W, Total_Weight, Index + 1);
	int Temp = max(Max_Weight_1, Max_Weight_2);
	DP[Index][Total_Weight] = Temp;
	return Temp;
}


int Knap_Sack_Top_Up(const int Total_Weight, const vector<int>& W) {
	vector<vector<int>> DP(W.size(), vector<int>(Total_Weight + 1, 0));
	
	for (int C = 0; C <= Total_Weight; C++) {
		if (W[0] <= C)
			DP[0][C] = W[0];
	}

	for (int i = 1; i < W.size(); i++) {
		for (int c = 1; c <= Total_Weight; c++) {
			int Max_Wt_1 = 0; int Max_Wt_2 = 0;
			if (W[i] <= c) {
				Max_Wt_1 = W[i] + DP[i - 1][c - W[i]];
			}
			Max_Wt_2 = DP[i - 1][c];
			DP[i][c] = max(Max_Wt_1, Max_Wt_2);
		}
	}
	return DP[W.size() - 1] [Total_Weight];
}

int optimal_weight(int Total_Weight, const vector<int>& W) {

/* Note both approaches (Top_UP & Top_Down) are working */
#if 0
	vector<vector<int>> DP_Memoization(W.size(), vector<int>(Total_Weight + 1, -1));
	return Knap_Sack_Top_Down_Recur(DP_Memoization, W, Total_Weight, 0);
#else
	return Knap_Sack_Top_Up(Total_Weight, W);
#endif
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}

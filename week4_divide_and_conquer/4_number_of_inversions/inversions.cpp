#include <iostream>
#include <vector>

using std::vector;

long long Merge(vector<int>& Num, int Low, int Mid, int High) {
	vector<int> Sort(High - Low + 1);
	int i = Low;
	int j = Mid + 1;
	int k = 0;
	long long No_Of_Inversion = 0;
	while (i <= Mid && j <= High) {
		if (Num[i] <= Num[j]) {
			Sort[k++] = Num[i++];
		}
		else {
			Sort[k++] = Num[j++];
			/* At any step in Merge(), if Num[i] is greater than Num[j],
			   Then there are (Mid - i) inversions. 
			   Because left and right subarrays are sorted, so all the 
			   remaining elements in Left-subarray will be
			   greater than a[j];
			   Example:
			            Left-Sorted     Right-Sorted
			   Index :     0 1 2          3 4 5 
			   Data  :     1 3 5          2 4 6
			   i is 0, Mid is 2 and j is 3 (All are indices)
			   Ist Iteration: a[0] < a[3]
			   Sort  :     1
			   2nd ITeration: a[1] > a[3], then remaining 2 elements a[1] & a[3]
			   are already small, so inversion takes place by jumping 2 elements
			   Sort  :     1 2 
			   Inversion : (Mid - 1) + 1 => (2 -1) + 1 => 2
			   3rd Iteration:
			   Sort  :     1 2 3
			   4th Iteration: a[2] > a[4], then remaining 1 elements are small
			   Inversion : 2 + (Mid - 1) + 1 -> 2 + (1 -1) + 1 => 3
			   Sort   :    1 2 3 4
			   5th Iteration: a[2] < a[5]
			   Sort   :    1 2 3 4 5
			 */
			No_Of_Inversion += (Mid - i)+1;
		}
	}

	while (i <= Mid)
		Sort[k++] = Num[i++];

	while (j <= High)
		Sort[k++] = Num[j++];
	for (int i = 0; i < Sort.size(); i++)
		Num[Low++] = Sort[i];
	return No_Of_Inversion;
}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (left >= right) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, left, ave);
  number_of_inversions += get_number_of_inversions(a, ave+1, right);
  number_of_inversions += Merge(a, left, ave, right);
  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  //vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, 0, a.size()-1) << '\n';
  return 0;
}

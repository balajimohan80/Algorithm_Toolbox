#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> Num) {
	std::sort(Num.begin(), Num.end(), [](const string& a, const string& b) {
		if (a[0] > b[0]) {
			return true;
		} 
#if 0		
		else if (a[0] == b[0]) {
			int i = 0;
			int j = 0;
			char ch_a = a[0];
			char ch_b = b[0];
			while (i < a.length() || j < b.length()) {
				ch_a = (i < a.length()) ? a[i++]: ch_a;
				ch_b = (j < b.length()) ? b[j++]: ch_b;
				if (ch_a > ch_b) return true;
				else if (ch_a < ch_b) return false;
			}
		}
		return false;
#else
		string ab = a + b;
		string ba = b + a;
		return ab > ba ? true : false;
#endif		
		});
	string Ret;
	for (int i = 0; i < Num.size(); i++)
		Ret += Num[i];
	return Ret;
}

int main() {
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	std::cout << largest_number(a);
	return 0;
}


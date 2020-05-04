#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibo_huge(long long n, long long m) {
	if (!n || !m) return 0;
	std::vector<long long> Pisano_Seq; 
	std::vector<long long> Temp_Seq;
	long long F_I_1 = 1;
	long long F_I_2 = 0;
	long long F_I = 1;
	int Index = 1;
	bool Matched = false;
	bool Pattern_Matched = false;
	int i = 0;

	Pisano_Seq.push_back(0);
	Pisano_Seq.push_back(1);

	while (Index < n) {
		F_I = (F_I_1 + F_I_2) % m;
		F_I_2 = F_I_1; F_I_1 = F_I;
		if (!Matched && F_I == 0) {
			Matched = true; 
			i = 0;
			Temp_Seq.clear();
		}
		
		if (!Matched) {
			Pisano_Seq.push_back(F_I);
		}

		else {
			if (Pisano_Seq[i] == F_I) ++i;
			else {
				Matched = false;
				if (Temp_Seq.size()) {
					Temp_Seq.push_back(F_I);
					for (int j = 0; j < Temp_Seq.size(); j++)
						Pisano_Seq.push_back(Temp_Seq[j]);
					
				}
				i = 0;
			}
			if (i == Pisano_Seq.size()) {
				Pattern_Matched = true;
				break;
			}
			Temp_Seq.push_back(F_I);
		}
		++Index;
	}
	if (Pattern_Matched) {
		long long Mod = n % Pisano_Seq.size();
		return Pisano_Seq[Mod];
	} 
	return F_I;
}



int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibo_huge(n, m) << '\n';
}

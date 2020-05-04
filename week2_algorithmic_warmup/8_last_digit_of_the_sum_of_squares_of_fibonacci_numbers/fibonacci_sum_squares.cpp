#include <iostream>
#include<vector>

using namespace std;

vector<int> Generate_Pisano_Seq(uint64_t n, uint64_t m) {
	vector<int> Pisano_Seq;
	vector<int> Temp_Seq;
	uint64_t F_N, F_N_1, F_N_2;
	uint64_t Index = 1;
	uint64_t Count = 0;
	bool Matched = false;
	bool Pisano_Pattern_Matched = false;

	Pisano_Seq.push_back(1);
	F_N_1 = 1; F_N_2 = 0;
	while (Index < n) {
		F_N = (F_N_1 + F_N_2) % m;
		F_N_2 = F_N_1;
		F_N_1 = F_N;
		if (!Matched && !F_N) {
			Matched = true;
		}
		else if (!Matched) {
			Pisano_Seq.push_back(F_N);
		}
		if (Matched) {
			if (Pisano_Seq[Count] == F_N) {
				Temp_Seq.push_back(F_N);
				++Count;
			}
			else {
				Temp_Seq.push_back(F_N);
				for (int i = 0; i < Temp_Seq.size(); i++) {
					Pisano_Seq.push_back(Temp_Seq[i]);
				}
				Temp_Seq.clear();
				Count = 0;
			}
			if (Count == Pisano_Seq.size()) {
				Pisano_Pattern_Matched = true;
				break;
			}
		}
		++Index;
	}
	return Pisano_Pattern_Matched ? Pisano_Seq : vector<int>{};
}


const vector<int> Pisano_Seq = Generate_Pisano_Seq(124, 10);

int Last_Digit_Sum_Of_Squares(int64_t n) {
	uint64_t Sum_Of_Squares = 0;
	n = n % Pisano_Seq.size();
	uint32_t x =( (n - 1) < 0) ? Pisano_Seq.size() - 1 : n - 1;
	Sum_Of_Squares = Pisano_Seq[x] * Pisano_Seq[n];
	return Sum_Of_Squares % 10;
}


int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    uint64_t previous = 0;
	uint64_t current  = 1;
	uint64_t sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << Last_Digit_Sum_Of_Squares(n);
	return 0;
}

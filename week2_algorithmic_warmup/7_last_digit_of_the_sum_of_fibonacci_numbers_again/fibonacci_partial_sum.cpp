#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

std::vector<int> Generate_Fibo_Seq(long long n, long long m, long long& Total_Seq_Sum) {
	std::vector<int> Pisano_Seq;
	std::vector<int> Temp_Seq;
	bool Matched = false;
	bool Pattern_Matched = false;
	long long F_N_1, F_N_2, F_N;
	long long Index = 1;
	long long Count = 0;

	F_N_1 = 1; F_N_2 = 0;
	Pisano_Seq.push_back(0);
	Pisano_Seq.push_back(1);
	Total_Seq_Sum = 1;
	while (Index < n) {
		F_N = (F_N_1 + F_N_2) % m;
		F_N_2 = F_N_1;
		F_N_1 = F_N;
		//Pattern for Pisano Seq is 01
		if (!Matched && !F_N) {
			Matched = 1;
		}
		else if (!Matched) {
			Pisano_Seq.push_back(F_N);
			Total_Seq_Sum += F_N;
		}

		if (Matched) {
			if (Pisano_Seq[Count] == F_N) {
				++Count;
				Temp_Seq.push_back(F_N);
			}
			else {
				Matched = false;
				Temp_Seq.push_back(F_N);
				Count = 0;
				for (int i = 0; i < Temp_Seq.size(); i++) {
					Pisano_Seq.push_back(Temp_Seq[i]);
					Total_Seq_Sum += Temp_Seq[i];
				}
				Temp_Seq.clear();
			}

			if (Count == Pisano_Seq.size()) {
				Pattern_Matched = true;
				break;
			}
		}
		++Index;
	}
12	return Pattern_Matched ? Pisano_Seq : std::vector<int>{};
}

long long Total_Seq_Sum;
std::vector<int> Pisano_Seq = Generate_Fibo_Seq(128, 10, Total_Seq_Sum);

#if 0
int Get_Fibo_Partial_Sum(long long Left, long long Right) {
	long long No_Of_OverFlow = 0;
	long long Adj_Left = 0;
	long long Count = 0;
	long long Total_Sum = 0;
	if ((Right - Left) < Pisano_Seq.size()) {
		Adj_Left = Left % Pisano_Seq.size();
		Count = (Right - Left) % Pisano_Seq.size();
		Count++;
	}
	else {
		Adj_Left = Left % Pisano_Seq.size();
		Count  = (Pisano_Seq.size() - Adj_Left);
		Count += (Right % Pisano_Seq.size());
		No_Of_OverFlow = (Right - Left) / Pisano_Seq.size();
		--No_Of_OverFlow;
	}

	while (Count) {
		Total_Sum += Pisano_Seq[Adj_Left];
		Adj_Left = (Adj_Left + 1) % Pisano_Seq.size();
		//Reason for this check, in Pisano_seq[0] = 0. This is dont care situation
		//if Adj_Left reached to Zero, do not decrement count
		// 58 59 0(Dont consider) 1 2
		if (Adj_Left)
		--Count;
	}

	//Total_Sum += (Total_Seq_Sum * No_Of_OverFlow);
	return Total_Sum % 10;
}
#else
int Get_Fibo_Partial_Sum(long long Left, long long Right) {
	long long Total_Sum = 0;
	Left  = Left  % Pisano_Seq.size();
	Right = Right % Pisano_Seq.size();
	if (Right < Left) {
		Right += Pisano_Seq.size();
	}
	long long Count = (Right - Left) + 1;
	while (Count) {
		Total_Sum += Pisano_Seq[Left];
		Left = (Left + 1) % Pisano_Seq.size();
		--Count;
	}
	return (Total_Sum % 10);
}
#endif


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << Get_Fibo_Partial_Sum(from, to) << '\n';
}

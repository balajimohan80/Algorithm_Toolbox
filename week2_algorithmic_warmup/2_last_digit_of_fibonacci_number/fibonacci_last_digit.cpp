#include <iostream>
#include <vector>
using namespace std;

#if 0
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

std::vector<int> Vector_Decimal_Addition(const std::vector<int>& Oper1, const std::vector<int>& Oper2) {
	std::vector<int> Res;
	int Index_1 = 0;
	int Index_2 = 0;
	int Carry = 0;

	while (Index_1 < Oper1.size() && Index_2 < Oper2.size()) {
		int Sum = Oper1[Index_1] + Oper2[Index_2] + Carry;
		Carry = Sum / 10;
		Sum = Sum % 10;
		Res.push_back(Sum);
		Index_1++;
		Index_2++;
	}

	while (Index_1 < Oper1.size()) {
		if (Carry) {
			int Sum = Oper1[Index_1] + Carry;
			Carry = Sum / 10;
			Sum = Sum % 10;
			Res.push_back(Sum);
		}
		else {
			Res.push_back(Oper1[Index_1]);
		}
		++Index_1;
	}

	while (Index_2 < Oper2.size()) {
		if (Carry) {
			int Sum = Oper2[Index_2] + Carry;
			Carry = Sum / 10;
			Sum = Sum % 10;
			Res.push_back(Sum);
		}
		else {
			Res.push_back(Oper2[Index_2]);
		}
		++Index_2;
	}

	if (Carry)
		Res.push_back(Carry);

	return Res;
}
#endif

int get_fibonacci_last_digit(int n) {
#if 0	
	vector<unsigned char> F(n+1);
	F[0] = 0;
	F[1] = 1;
	for (int i =2 ; i <= n; i++) {
		F[i] = (F[i-1] + F[i-2]) % 10;
	}
	return static_cast<int>(F[n]);
#else 
	unsigned char F_N_1 = 1;
	unsigned char F_N_2 = 0;
	unsigned char F_N;
	for (int i = 2; i <= n; i++) {
		F_N = (F_N_1 + F_N_2) % 10;
		F_N_2 = F_N_1;
		F_N_1 = F_N;	
	}
	return static_cast<int>(F_N);
#endif
}



int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    return 0;
}

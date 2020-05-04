#include<iostream>
#include<vector>
using namespace std;

vector<uint64_t> fibList; // Fibonacci numbers List
vector<uint64_t> pisanoSequence; // Pisano Sequence list
void generatePisanoSequence(int mod)
{
	fibList.push_back((*(fibList.end() - 1) + *(fibList.end() - 2)) % mod); // Get the last digits of the next Fibonacci number depending on the modulp. 
	pisanoSequence.push_back(*(fibList.end() - 1)); //Put the last digit of the last Fibonacci number in the Pisano Sequence
	if (*(pisanoSequence.end() - 1) == 1 && *(pisanoSequence.end() - 2) == 0) // If we return to having 0 then 1 as inputs to the Pisano sequence that mean we have reached the end of the period of the sequence
	{
		return; // Stop Generating entries
	}
	else
	{
		generatePisanoSequence(mod); // Calculate the next entry.
	}
}
int main()
{
	fibList.push_back(0); // Put 0 to the Fibonacci sequence
	fibList.push_back(1); // Put 1 to the Fibonacci sequence
	pisanoSequence.push_back(0); // Put 0 to the Pisano Sequence
	pisanoSequence.push_back(1); // Put 1 to the Pisano sequence
	generatePisanoSequence(1000); // An Examplry Modulos of 1000
	uint64_t n, m; // Input Fibonacci numbers
	cin >> n >> m;
	if (m == n) //If the same number entered for both, simply get the last digit of that number/
	{
		m = m % pisanoSequence.size(); //Find its place in the Pisano sequence
		cout << pisanoSequence[m] % 10; // Get the number and print and its units digits
		return 0;
	}
	if (m > n) swap(m, n); //If m is bigger than n, i.e the second Fibonacci is bigger than the first, swap them.
	n = n + 2; //Get Fn+2
	m = m + 1; //Get Fm+1
	n = n % (pisanoSequence.size()); // Get its position in Pisano Sequence
	m = m % (pisanoSequence.size()); // Get its position in Pisano Sequence
	uint64_t n2 = pisanoSequence[n]; //Get the number
	uint64_t m2 = pisanoSequence[m]; //Get the number
	int64_t z = n2 - m2; //Subtract the numbers to find the partial sum
	z = abs(z); //If negative make it positive because the sum is +ve and the subtraction might yield negative.
	cout << z % 10; // Print the units of the sum

	return 0;
}


#if 0
#include <iostream>
#include <vector>

std::vector<int> Pisano_Seq_Generator(long long n, long long m, unsigned int &Total_Sum) {
	std::vector<int> Pisano_Seq;
	std::vector<int> Temp_Seq;
	long long F_I_1, F_I_2, F_I;
	bool Matched = false;
	bool Pisano_Seq_Matched = false;
	long long Index = 1;
	long long Count = 0;
	
	F_I_2 = 0; F_I_1 = 1;
	Pisano_Seq.push_back(0);
	Pisano_Seq.push_back(1);
	Total_Sum = 1;
	while (Index < n) {
		F_I   = (F_I_1 + F_I_2) % m;
		F_I_2 = F_I_1; 
		F_I_1 = F_I;

		if (!Matched && !F_I) {
			Matched = true;
		}
		else if (!Matched) {
			Pisano_Seq.push_back(F_I);
			Total_Sum += F_I;
		}

		if (Matched) {
			if (Pisano_Seq[Count] == F_I) {
				++Count;
				Temp_Seq.push_back(F_I);
			}
			else {
				Matched = false;
				Count = 0;
				Temp_Seq.push_back(F_I);
				for (int i = 0; i < Temp_Seq.size(); i++) {
					Total_Sum += Temp_Seq[i];
					Pisano_Seq.push_back(Temp_Seq[i]);
				}
				Temp_Seq.clear();
			}

			if (Count == Pisano_Seq.size()) {
				Pisano_Seq_Matched = true;
				break;
			}
		}
		++Index;
	}
	return Pisano_Seq_Matched ? Pisano_Seq : std::vector<int>{};
}

unsigned int Total_Sum;
const std::vector<int> Pisano_Seq = Pisano_Seq_Generator(120, 10, Total_Sum);

int Fibo_Last_Digit_Sum(long long n) {
	const long long Mod_Last_Digit = 10;
	long long Div = n / Pisano_Seq.size();
	long long Rem = n % Pisano_Seq.size();
	Div = Div * static_cast<long long>(Total_Sum);
	unsigned int Rem_Total_Sum = 0;
	for (int i = 0; i <= Rem; i++) {
		Rem_Total_Sum += Pisano_Seq[i];
	}
	Div += Rem_Total_Sum;
	return static_cast<int>(Div % Mod_Last_Digit);
}


int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << Fibo_Last_Digit_Sum(n);
}
#endif


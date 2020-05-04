#include <iostream>

int sum_of_two_digits(int first_digit, int second_digit) {
    return first_digit + second_digit;
}

int main() {
#if 0
    int a = 0;
    int b = 0;
    std::cin >> a;
    std::cin >> b;
    std::cout << sum_of_two_digits(a, b);
#else
	int n = rand() + 2;
	std::cout << "n: " << n << std::endl;
#endif
	return 0;
}
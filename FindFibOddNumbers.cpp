#include <iostream>
using namespace std;

int fibOddNumbersSum(int);
void addToSum(int&, int&, int&);


int main() {

	cout << fibOddNumbersSum(4) << endl;

	return 0;
}

int fibOddNumbersSum(int maxNumber) {

	int fibOddNum1 = 0; 
	int fibOddNum2 = 1;
	int number = 1;
	int sum = 0;

	while (number <= maxNumber) {
		addToSum(sum, number, fibOddNum2);
		number = fibOddNum1 + fibOddNum2;
		fibOddNum1 = fibOddNum2;
		fibOddNum2 = number;
	}

	return sum;
}

void addToSum(int& sum, int &number, int &fibOddNum2) {
	if (number % 2 == 1) {
		sum += fibOddNum2;
	}
}


#include <iostream>
#include <vector>

using namespace std;

#define _MAX_3_DIGIT_NUMBER_ 999
#define _MAX_2_DIGIT_NUMBER_ 99

void findPalindromic();
bool isPalindromic(long);
bool isTwoDigitsGreaterThanMax(long, long);


int main() {
	findPalindromic();
	return 0;
}

void findPalindromic() {
	long max = 0;

	for (int i = _MAX_2_DIGIT_NUMBER_; i > 0; i--) {
		for (int j = _MAX_2_DIGIT_NUMBER_; j > 0; j--) {
			if (isPalindromic(i * j)) {
				if (isTwoDigitsGreaterThanMax((i*j), max)) {
					max = i*j;
				}
			}
		}
		
	}
	cout << "Largest palindrome made from the product of two 2-digit numbers is: " << max << endl;
}

bool isPalindromic(long numbers) {
	long reversedNumber = 0;
	long remainder = 0;
	int n = numbers;
	vector<int> forwardNumber;
	while (numbers > 0) {
		remainder = numbers % 10;
		reversedNumber = reversedNumber * 10 + remainder;
		numbers /= 10;
	}

	if (n == reversedNumber) {
		return true;
	}
	return false;
}

//helper function
bool isTwoDigitsGreaterThanMax(long product, long max) {
	if (product > max) {
		return true;
	}
	else {
		return false;
	}
}
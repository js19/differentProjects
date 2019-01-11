#include <iostream>

using namespace std;

bool isPrime(int);
void getPrime();

#define _MAX_NUMBER_OF_PRIMES 10001

int main() {
	getPrime();
	return 0;
}

void getPrime() {
	int counter = 0;
	int number = 2;
	while (counter != _MAX_NUMBER_OF_PRIMES) {
		if (isPrime(number)) {
			counter++;
			cout << number << endl;
		}
		number++;
	}
}

bool isPrime(int number) {

	for (int i = 2; i < number; i++) {
		if (number % i == 0) {
			return false;
		}
	}
	
	return true;
}
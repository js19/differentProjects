#include <iostream>
#include <vector>

using namespace std;

#define _MAX_ 9999999999999999
#define _MAX_TO_ 20
#define _SMALLEST_MULTIPLE_FOR_ONE_TEN_  2520

void findSmallestMultiple();
bool hasRemainder(int);

int main() {
	
	findSmallestMultiple();

	return 0;
}


void findSmallestMultiple() {

	int counter;

	for (int i = _SMALLEST_MULTIPLE_FOR_ONE_TEN_; i <= _MAX_; i++) {
		counter = 0;
		for (int j = 1; j <= _MAX_TO_; j++) {
			if (hasRemainder(i % j)) {
				break;
			}
			counter++;
		}

		if (counter == _MAX_TO_) {
			cout << "Smallest multiple is: " << i << endl; 
			return;
		}
	}
}

bool hasRemainder(int product) {
	if (product >= 1) {
		return true;
	}
	return false;
}
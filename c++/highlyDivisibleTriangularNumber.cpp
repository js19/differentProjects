#include <iostream>

using namespace std;

int checkDivisors(long long total) {
	int count = 0;
	for (int i = 1; i <= total; i++) {
		if (total % i == 0) {
			count++;
		}
	}
	return count;
}

//Naive approch to find the high divisible triangular number (SLOW!)
//Will approch a better solution later on. 
int main() {
	long long total = 28;
	long long i = 8;
	cout << "Calculating..." << endl;
	while(checkDivisors(total) < 500){
		total += i;
		i++;
	}
	cout << total << endl;
	return 0;
}
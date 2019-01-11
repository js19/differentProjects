#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void findMultiples(int);
void findMultipleRecursion(int, int);

int main() {
	auto start = high_resolution_clock::now();
	findMultiples(1000);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << duration.count() << " microseconds" << endl;

	start = high_resolution_clock::now();
	findMultipleRecursion(999, 0);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << duration.count() << " microseconds"  << endl;


	return 0;
}

void findMultiples(int number) {
	int sum = 0;
	for (int i = 0; i < number; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	cout << sum << endl;
}

void findMultipleRecursion(int number, int sum) {

	if (number == 0) {
		cout << sum << endl;
	}
	else {
		if (number % 3 == 0 || number % 5 == 0) {
			sum += number;
		}
		findMultipleRecursion(--number, sum);
	}

}
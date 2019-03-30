#include <iostream>
#include <string>

using namespace std;
#define STRING_LENGTH_SIZE_ONE 1

string FirstReverse(string str) {
	
	int characterCounter = 0;
	char lastCharacter;
	char frontCharacter;

	if (str.length() == STRING_LENGTH_SIZE_ONE) {
		return str;
	}

	for (int i = str.length() - 1; i >= str.length() / 2; i--) {
		lastCharacter = str[i];
		frontCharacter = str[characterCounter];
		str[i] = frontCharacter;
		str[characterCounter] = lastCharacter;
		characterCounter++;
	}

	return str;
}

//Simple program to reverse a string with C++
int main() {

	string str = "dog";
	cout << "Forward: " << str << endl;
	cout << "Reversed: " << FirstReverse(str) << endl;

	return 0;
}
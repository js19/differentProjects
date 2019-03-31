#include <iostream>
#include <string>
#include <map>

#define lcA 97
#define lcE 101
#define lcI 105
#define lcO 111
#define lcU 117
#define lcZ 122

using namespace std;


//O(nlogn)
string letterChangeWithMaps(string str) {
	map<char, char> characters = { {'a', 'b'},{'b', 'c'},{'c', 'd'},{'d', 'e'},{'e', 'f'},{'f', 'g'},{'g', 'h'},{'h', 'i'},{'i', 'j'},{'j', 'k'},{'k', 'l'},
	{'l', 'm'},{'m', 'n'},{'n', 'o'},{'o', 'p'},{'p', 'q'},{'q', 'r'},{'r', 's'},{'s', 't'},{'t', 'u'},{'u', 'v'},{'v', 'w'},{'w', 'x'},{'x', 'y'},{'y', 'z'},{'z', 'a'}
	};
	map<char, char> vowsArray = { {'a', 'A'}, {'e', 'E'}, {'i', 'I'}, {'o', 'O'}, {'u', 'U'} };

	for (int i = 0; i < str.length(); i++) {
		if (characters.find(str[i]) != characters.end()) {
			str[i] = characters[str[i]];
			if (vowsArray.find(str[i]) != vowsArray.end()) {
				str[i] = vowsArray[str[i]];
			}
		}
		else {
			str[i] = str[i];
		}
	}

	return str;
}


//helper function to convert vowels to uppercase 
char upperVowel(char character) {

	switch (character) {
	case lcA:
		return lcA - 32;
	case lcE:
		return lcE - 32;
	case lcI:
		return lcI - 32;
	case lcO:
		return lcO - 32;
	case lcU:
		return lcU - 32;
	default:
		return character;
	}
}

//O(n)
string letterChangeWithOutMaps(string str) {
	
	for (int i = 0; i < str.length(); i++) {
		//loop back to A
		if (str[i] == lcZ) {
			str[i] = char(lcA);
			str[i] = upperVowel(str[i]);
		}
		else if ( str[i] < lcA || str[i] > lcZ) {
			str[i] = str[i];
		}
		else {
			str[i] = str[i] + 1;
			str[i] = upperVowel(str[i]);
		}
		
	}

	return str;
}

int main() {

	string str = "hello"; //expected: Ifmmp
	cout << "Original: " << str << endl;
	cout << "Shifted with maps: " << letterChangeWithMaps(str) << endl;
	cout << "Shifted without maps: " << letterChangeWithOutMaps(str) << endl;

	return 0;
}
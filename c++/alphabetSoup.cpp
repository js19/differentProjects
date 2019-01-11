#include <iostream>
#include <string>
#include "Source.h"

using namespace std; 

void alphabetSoup(string);

int main() {

	string word; 
	cin >> word;
	alphabetSoup(word);
	
	return 0;
}


void alphabetSoup(string word) {
	char key;
	int j; 
	for (int i = 0; i < word.length(); i++) {
		key = word[i];
		j = i - 1;
		while (j >= 0 && word[j] > key) {
			word[j + 1] = word[j]; 
			j = j - 1;
		}
		word[j + 1] = key;
	}
	cout << word << endl;
}
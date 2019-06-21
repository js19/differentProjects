#include <iostream>
#include <string>
#include <map>


using namespace std;

int strStr(string haystack, string needle) {

	if (needle.empty()) {
		return 0;
	}

	if (needle.length() > haystack.length()) {
		return -1;
	}

	if (needle.length() == 1 && haystack.length() == 1 && needle == haystack) {
		return 0;
	}

	int count = 0;
	for (int i = 0; i < haystack.length() - (needle.length() - 1); i++) {
		string temp;
		while (count < needle.length()) {
			temp.push_back(haystack[i + count]);
			count++;
		}
		if (needle == temp) {
			return i;
		}
		count = 0;
	}

	return -1;
}


int main() {

	cout << strStr("hello", "ll") << endl;
	cout << strStr("aaaaa", "bba") << endl;
	cout << strStr("a", "a") << endl;
	cout << strStr("aaa", "a") << endl;
	cout << strStr("aaa", "aaa") << endl;
	cout << strStr("a", "aa") << endl;
	cout << strStr("aa", "") << endl;
	cout << strStr("", "a") << endl;
	cout << strStr("abb", "abaaa") << endl;
	
		

	return 0;
}
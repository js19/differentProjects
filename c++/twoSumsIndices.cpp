#include <iostream>
#include <vector>

using namespace std;

/*
Brute Force method

Simple program that find the indices of elements that add
up to the target 

ex:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

vector<int> twoSums(vector<int>& nums, int target) {
	vector<int> v; // vector that will hold the two indicies 

	for (int i = 0; i < nums.size(); i++) {				//n
		for (int j = i; j < nums.size(); j++) {			//n
			//can't use same element twice and see if we equal the target
			if (i != j && nums[i] + nums[j] == target) {
				return v = { i, j };
			}
		}
	}

	//total runtime n * n = O(n^2)

	return v;
}


int main() {

	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> numReturn;

	numReturn = twoSums(nums, target);
	cout << numReturn[0] << " " << numReturn[1] << endl;

	return 0;
}
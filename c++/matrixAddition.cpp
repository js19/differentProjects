#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int> > matrixAddition(std::vector<std::vector<int> > a, std::vector<std::vector<int> > b);

int main() {
	std::vector<std::vector<int> > expected;
	std::vector<std::vector<int> > m1;
	std::vector<std::vector<int> > m2;
	std::vector<std::vector<int> > n;
	expected = { {3, 4, 4}, {6, 4, 4}, {2, 2, 4} };
	m1 = { {1, 2, 3}, {3, 2 , 1}, {1, 1, 1} };
	m2 = { {2, 2, 1}, {3, 2, 3}, {1, 1, 3} };
	n = matrixAddition(m1, m2);

	(n != expected) ? cout << "Fail" << endl : cout << "Pass!" << endl; 
	return 0;
}

std::vector<std::vector<int> > matrixAddition(std::vector<std::vector<int> > a, std::vector<std::vector<int> > b) {
	vector<vector<int>> result;
	vector<int> line;

	if (a.size() != b.size()) {
		exit;
	}
	int size = a.size();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			line.push_back(a[i][j] + b[i][j]);
		}
		result.push_back(line);
		line.clear();
	}

	return result;
}
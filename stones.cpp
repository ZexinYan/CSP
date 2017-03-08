#include <iostream>
#include <vector>

#define N 100
using namespace std;

int calculate(vector<int>& stones, int size) {
	vector<vector<int> > matrix(size, vector<int>(size, 0));

	// two heap combine.
	for (int i = 0; i < size - 1; ++i) {
		matrix[i][i + 1] = stones[i] + stones[i + 1];
	}

	int sum = 0;
	for (int heapSize = 3; heapSize <= size; ++heapSize) {
		for (int left = 0; left < size - heapSize + 1; ++left) {
			sum = 0;
			int right = left + heapSize - 1;

			for (int k = left; k <= right; ++k) {
				sum += stones[k];
			}

			matrix[left][right] = matrix[left + 1][right] + sum;

			for (int k = left + 1; k < right; ++k) {
				matrix[left][right] = min(matrix[left][k] + matrix[k + 1][right] + sum, matrix[left][right]);
			}
		}
	}
	return matrix[0][size - 1];
}

int main() {
	int size, tmp;
	cin >> size;
	vector<int> stones(size, 0);
	for (int i = 0; i < size; ++i) {
		cin >> tmp;
		stones[i] = tmp;
	}

	cout << calculate(stones, size) << endl;
	return 0;
}

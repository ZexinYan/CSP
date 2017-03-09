#include <iostream>
#include <vector>

using namespace std;


int main() {
	int row, col;
	cin >> row >> col;
	vector<vector<int> > graph(row, vector<int>(col, 0));
	vector<vector<int> > result(row, vector<int>(col, 0));

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> graph[i][j];
			result[i][j] = graph[i][j];
		}
	}

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col - 2; ++j) {
			if (graph[i][j] == graph[i][j + 1] && graph[i][j + 1] == graph[i][j + 2]) {
				result[i][j] = result[i][j + 1] = result[i][j + 2] = 0;
			}
		}
	}

	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row - 2; ++j) {
			if (graph[j][i] == graph[j + 1][i] && graph[j + 1][i] == graph[j + 2][i]) {
				result[j][i] = result[j + 1][i] = result[j + 2][i] = 0;
			}
		}
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col - 1; ++j) {
			cout << result[i][j] << " ";
		}
		cout << result[i][col - 1] << endl;
	}
	return 0;
}

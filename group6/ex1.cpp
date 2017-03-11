#include <iostream>
#include <vector>

using namespace std;

int main() {
	int row, col;
	cin >> row >> col;
	vector<vector<int> > orginalGraph(row, vector<int>(col, 0));
	vector<vector<int> > anoGraph(col, vector<int>(row, 0));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> orginalGraph[i][j];
		}
	}
	for (int i = col - 1, ii = 0; i >= 0; i--, ii++) {
		for (int j = 0, jj = 0; j < row; ++j, jj++) {
			anoGraph[ii][jj] = orginalGraph[j][i];
		}
	}
	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row - 1; j++) {
			cout << anoGraph[i][j] << " ";
		}
		cout << anoGraph[i][row - 1] << endl;
	}
	return 0;
}

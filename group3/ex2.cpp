#include <iostream>
#include <vector>

using namespace std;

int row = 15;
int col = 10;
int square = 4;

vector<vector<int> > graph(row, vector<int>(col, 0));
int startCol;

vector<vector<int> > block(square, vector<int>(square, 0));
int upRowForBlock = 0;
int downRowForBlock = 3;

bool validate(int scanRow) {
	for (int rowForBlock = downRowForBlock, rowForGraph = scanRow;
						 rowForBlock >= upRowForBlock;
						  --rowForBlock, rowForGraph--) {
		for (int colForGraph = startCol, colForBlock = 0; colForBlock < 4; ++colForGraph, ++colForBlock) {
			if (graph[rowForGraph][colForGraph] == 1 && block[rowForBlock][colForBlock] == 1) {
				return false;
			}
		}
	}
	return true;
}

void print(int scanRow) {
	for (int rowForBlock = downRowForBlock, rowForGraph = scanRow;
						 rowForBlock >= upRowForBlock;
						  --rowForBlock, rowForGraph--) {
		for (int colForGraph = startCol, colForBlock = 0; colForBlock < 4; ++colForGraph, ++colForBlock) {
			graph[rowForGraph][colForGraph] = block[rowForBlock][colForBlock] | graph[rowForGraph][colForGraph];
		}
	}
}

int main() {
	/**
	 * Input the graph.
	 */
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < square; ++i) {
		for (int j = 0; j < square; ++j) {
			cin >> block[i][j];
		}
	}

	cin >> startCol;

	startCol--;
	/**
	 * Process.
	 */
	for (int i = 3; i >= 0; --i) {
		if (block[i][0] == 0 && block[i][1] == 0 && block[i][2] == 0 && block[i][3] == 0) {
			continue;
		} else {
			downRowForBlock = i;
			break;
		}
	}

	for (int i = 0; i < 4; ++i) {
		if (block[i][0] == 0 && block[i][1] == 0 && block[i][2] == 0 && block[i][3] == 0) {
			continue;
		} else {
			upRowForBlock = i;
			break;
		}
	}
	int scanRow = 0;
	int saveRange = downRowForBlock - upRowForBlock;
	for (scanRow = saveRange; scanRow <= 14; ++scanRow) {
		if (validate(scanRow)) {
			continue;
		} else {
			break;
		}
	}
	print(scanRow - 1);

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col - 1; ++j) {
			cout << graph[i][j] << " ";
		}
		cout << graph[i][9] << endl;
	}
	return 0;
}

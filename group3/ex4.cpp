#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

struct Point {
	int row;
	int col;
	int costTime;
	Point(int t_row = 0, int t_col = 0, int t_costTime = 0) {
		row = t_row;
		col = t_col;
		costTime = t_costTime;
	}
};
int row, col;

int visited[100][100][301];

int main() {
	int trapSize;
	cin >> row >> col >> trapSize;
	vector<vector<pair<int, int> > > graph(row, vector<pair<int, int> >(col, pair<int, int>(-1, -1)));
	int r, c, a, b;
	while (trapSize--) {
		cin >> r >> c >> a >> b;
		graph[r - 1][c - 1] = pair<int, int>(a, b);
	}

	queue<Point> pointQueue;
	pointQueue.push(Point(0, 0, 0));
	Point top;
	while (!pointQueue.empty()) {
		top = pointQueue.front();
		pointQueue.pop();
		if (visited[top.row][top.col][top.costTime] == 1) {
			continue;
		}
		visited[top.row][top.col][top.costTime] = 1;
		if (top.row == row - 1 && top.col == col - 1) {
			cout << top.costTime << endl;
			return 0;
		}

		if (graph[top.row][top.col].first <= top.costTime && top.costTime <= graph[top.row][top.col].second) {
			continue;
		} else {
			// up
			if (top.row >= 1) {
				pointQueue.push(Point(top.row - 1, top.col, top.costTime + 1));
			}
			// down
			if (top.row < row - 1) {
				pointQueue.push(Point(top.row + 1, top.col, top.costTime + 1));
			}
			// left
			if (top.col >= 1) {
				pointQueue.push(Point(top.row, top.col - 1, top.costTime + 1));
			}
			// right
			if (top.col < col - 1) {
				pointQueue.push(Point(top.row, top.col + 1, top.costTime + 1));
			}
		}
	}
	return 0;
}

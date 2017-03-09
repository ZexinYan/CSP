#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char> > graph;
int row, col;

void printGraph() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << graph[i][j];
		}
		cout << endl;
	}
}

struct Point {
	int x;
	int y;
	Point(int t_x = 0, int t_y = 0) : x(t_x), y(t_y) {}
};

void fill(int x, int y, char ch) {
	x = row - x - 1;
	vector<vector<bool> > visited(row, vector<bool>(col, false));
	queue<Point> pointQueue;
	pointQueue.push(Point(x, y));
	Point top;
	while (!pointQueue.empty()) {
		top = pointQueue.front();
		pointQueue.pop();
		if (visited[top.x][top.y]) {
			continue;
		}
		visited[top.x][top.y] = true;
		if (graph[top.x][top.y] == '-' || graph[top.x][top.y] == '|' || graph[top.x][top.y] == '+') {
			continue;
		}
		graph[top.x][top.y] = ch;
		if (top.x < row - 1) {
			// right;
			pointQueue.push(Point(top.x + 1, top.y));
		}
		if (top.x >= 1) {
			// left;
			pointQueue.push(Point(top.x - 1, top.y));
		}
		if (top.y >= 1) {
			// up
			pointQueue.push(Point(top.x, top.y - 1));
		}
		if (top.y < col - 1) {
			// down
			pointQueue.push(Point(top.x, top.y + 1));
		}

	}
}

void draw(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		// horizontal '-'
		int startY = min(y1, y2);
		int endY = max(y1, y2);
		for (int i = startY; i <= endY; i++) {
			if (graph[row - x1 - 1][i] == '|') {
				graph[row - x1 - 1][i] = '+';
			} else {
				graph[row - x1 - 1][i] = '-';
			}
		}
	} else {
		// vertical '|'
		x1 = row - x1 - 1;
		x2 = row - x2 - 1;
		int startX = min(x1, x2);
		int endX = max(x1, x2);
		for (int i = startX; i <= endX; ++i) {
			if (graph[i][y1] == '-') {
				graph[i][y1] = '+';
			} else {
				graph[i][y1] = '|';
			}
		}
	}
}

int main() {
	int opSize;
	cin >> col >> row >> opSize;
	graph = vector<vector<char> >(row, vector<char>(col, '.'));
	while (opSize--) {
		int opType;
		cin >> opType;
		if (opType == 1) {
			// fill in
			int x, y; char ch;
			cin >> y >> x >> ch;
			fill(x, y, ch);
		} else {
			// draw
			int x1, y1, x2, y2;
			cin >> y1 >> x1 >> y2 >> x2;
			draw(x1, y1, x2, y2);
		}
	}
	printGraph();
}

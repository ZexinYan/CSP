#include <iostream>
#include <set>
#define MAX 10001

using namespace std;

set<int> graph[MAX];
int maxSum = 0;

int bfs(int src) {
	if (src < 0) {
		return 1;
	}
	int first = 0, second = 0, now = 0;
	for (set<int>::iterator iter = graph[src].begin(); iter != graph[src].end(); iter++) {
		now = bfs(*iter);
		if (now >= first) {
			second = first;
			first = now;
		} else if (now > second) {
			second = now;
		}
	}
	maxSum = max(maxSum, first + second);
	return first + 1;
}

int main() {
	int circleSize, squareSize;
	cin >> circleSize >> squareSize;
	int father;
	for (int i = 2; i <= circleSize; ++i) {
		cin >> father;
		graph[father].insert(i);
	}

	for (int i = 0; i < squareSize; ++i) {
		cin >> father;
		graph[father].insert(-i);
	}
	bfs(1);
	cout << maxSum << endl;
	return 0;
}

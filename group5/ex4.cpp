#include <iostream>
#include <set>
#include <cstring>
#include <queue>

#define MAXSIZE 10000

using namespace std;

bool connect[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE];
set<int> graph[MAXSIZE];

queue<int> visitQueue;

void clear() {
	while (!visitQueue.empty()) {
		visitQueue.pop();
	}
}

void bfs(int src) {
	memset(visited, false, sizeof(visited));
	clear();
	visitQueue.push(src);
	int top;
	while (!visitQueue.empty()) {
		top = visitQueue.front();
		visitQueue.pop();
		if (visited[top]) { continue; }
		visited[top] = true;
		for (set<int>::iterator iter = graph[top].begin(); iter != graph[top].end(); iter++) {
			if (!visited[*iter]) {
				visitQueue.push(*iter);
				connect[src][*iter] = true;
			}
		}
	}
}

int main() {
	memset(connect, false, sizeof(connect));
	int citySize, pathSize;
	cin >> citySize >> pathSize;
	int src, dest;
	while (pathSize--) {
		cin >> src >> dest;
		graph[src - 1].insert(dest - 1);
	}

	for (int i = 0; i < citySize; ++i) {
		bfs(i);
	}

	int result = 0;

	// for (int i = 0; i < citySize; ++i) {
	// 	for (int j = 0; j < citySize; ++j) {
	// 		cout << connect[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	for (int i = 0; i < citySize; ++i) {
		for (int j = i + 1; j < citySize; j++) {
			if (connect[i][j] && connect[j][i]) {
				result++;
			}
		}
	}

	cout << result << endl;
	return 0;
}

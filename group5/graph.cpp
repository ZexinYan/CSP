#include <iostream>
#include <set>
#include <stack>

#define MAX 10000

using namespace std;

class DirectedCycle {
private:
	set<int> edges[MAX];
	bool visited[MAX];
	bool onStack[MAX];
	stack<int> cycle;
	int edgeTo[MAX];
	int size;

	void dfs(int src) {
		visited[src] = true;
		onStack[src] = true;
		for (set<int>::iterator iter = edges[src].begin(); iter != edges[src].end(); iter++) {
			if (hasCycle()) { return; }
			if (!visited[*iter]) {
				edgeTo[*iter] = src;
				dfs(*iter);
			} else if (onStack[*iter]) {
				// has cycle!
				for (int i = src; i != *iter; i = edgeTo[i]) {
					cycle.push(i);
				}
				cycle.push(*iter);
				cycle.push(src);
				return;
			}
		}
		onStack[src] = false;
	}

public:
	DirectedCycle(int size = 0) {
		this->size = size;
		memset(visited, false, sizeof(visited));
		memset(onStack, false, sizeof(onStack));
		memset(edgeTo, -1, sizeof(edgeTo));
	}

	void constructEdge() {
		int edgeSize;
		cin >> edgeSize;
		int src, dest;
		while(edgeSize--) {
			cin >> src >> dest;
			edges[src].insert(dest);
		}
	}

	bool hasCycle() {
		return !cycle.empty();
	}

	void validate() {
		for (int i = 1; i <= size; ++i) {
			if (!visited[i]) {
				dfs(i);
			}
		}
	}

	void printCycle() {
		if (hasCycle()) {
			while (!cycle.empty()) {
				cout << cycle.top() << " ";
				cycle.pop();
			}
			cout << endl;
		}
	}
};

int main() {
	int vertexSize;
	cin >> vertexSize;
	DirectedCycle graph(vertexSize);
	graph.constructEdge();
	graph.validate();
	graph.printCycle();

	return 0;
}

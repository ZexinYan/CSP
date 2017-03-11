#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#define MAX 100001

typedef unsigned long long ULL; 

using namespace std;

struct Adjacence {
	int dest;
	int distance;
	Adjacence(int t_dest = 0, int t_distance = 0) {
		dest = t_dest;
		distance = t_distance;
	}
};

struct Node {

};

int citySize;
vector<ULL> prices(MAX, 0);
vector<Adjacence> graph[MAX];
bool visited[MAX];
ULL ans = 0;
bool endFlag = false;

void dfs(int src, int dest, ULL miniPrice) {
	if (endFlag) {
		return;
	}
	if (src == dest) {
		cout << ans << endl;
		endFlag = true;
		return;
	}
	visited[src] = true;
	for (int i = 0; i < graph[src].size(); ++i) {
		if (!visited[graph[src][i].dest]) {
			miniPrice = min(miniPrice, prices[src]);
			ans += miniPrice * graph[src][i].distance;
			dfs(graph[src][i].dest, dest, miniPrice);
			ans -= miniPrice * graph[src][i].distance;
		}
	}
}

int main() {
	int planSize;
	cin >> citySize >> planSize;
	for (int i = 1; i <= citySize; ++i) {
		cin >> prices[i];
	}
	int src, dest, distance;
	for (int i = 0; i < citySize - 1; ++i) {
		cin >> src >> dest >> distance;

		graph[src].push_back(Adjacence(dest, distance));
		graph[dest].push_back(Adjacence(src, distance));
	}

	for (int i = 0; i < planSize; ++i) {
		cin >> src >> dest;
		memset(visited, false, sizeof(visited));
		endFlag = false;
		ans = 0;
		dfs(src, dest, prices[src]);
	}
	return 0;
}

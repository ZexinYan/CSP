#include <iostream>
#include <set>
#include <stack>
#include <cstring>

#define MAXSIZE 10005
using namespace std;

bool visited[MAXSIZE][MAXSIZE];
set<int> graph[MAXSIZE];
int unionFindSet[MAXSIZE];
stack<int> result;

class UnionFindSetOperation {
private:
    int length;
public:
    UnionFindSetOperation(int t_length) {
        length = t_length;
        for (int i = 1; i <= length; ++i) {
            unionFindSet[i] = i;
        }
    }

    int find(int x) {
        if (x == unionFindSet[x]) {
            return x;
        } else {
            return unionFindSet[x] = find(unionFindSet[x]);
        }
    }

    void unionBetween(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            unionFindSet[x] = y;
        }
    }

};

void dfs(int src) {
    for (set<int>::iterator iter = graph[src].begin(); iter != graph[src].end(); iter++) {
        if (!visited[src][*iter]) {
            visited[src][*iter] = true;
            visited[*iter][src] = true;
            dfs(*iter);
        }
    }
    result.push(src);
}

int main() {
    int citySize, pathSize;
    cin >> citySize >> pathSize;

    UnionFindSetOperation setOp(citySize);
    
    int src, dest;
    while (pathSize--) {
        cin >> src >> dest;
        
        graph[src].insert(dest);
        graph[dest].insert(src);

        setOp.unionBetween(src, dest);
    }

    bool nonPathExisted = false;

    int root = setOp.find(1);
    for (int i = 1; i <= citySize; i++) {
        if (root != setOp.find(i)) {
            nonPathExisted = true;
            break;
        }
    }

    if (!nonPathExisted) {
        int oddNum = 0;
        for (int i = 1; i <= citySize; ++i) {
            if (graph[i].size() % 2 == 1) {
                oddNum++;
            }
        }
        if (oddNum == 0 || (oddNum == 2 && graph[1].size() % 2 == 1)) {
            nonPathExisted = false;
        } else {
            nonPathExisted = true;
        }
    }

    if (!nonPathExisted) {
        memset(visited, false, sizeof(visited));

        dfs(1);

        while (result.size() != 1) {
            cout << result.top() << " ";
            result.pop();
        }
        cout << result.top() << endl;
    } else {
        cout << -1 << endl;
    }

}
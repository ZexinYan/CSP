#include <iostream>
#include <queue>
#include <vector>

#define MAXSIZE 10005
#define INF 0xfffffff

using namespace std;

struct Point {
    int index;
    int distance;
    Point(int t_index, int t_distance) {
        index = t_index;
        distance = t_distance;
    }

    friend bool operator < (Point a, Point b) {
        return a.distance > b.distance;
    }
};

struct Edge {
    int destination;
    int cost;
    Edge(int t_destination, int t_cost) {
        destination = t_destination;
        cost = t_cost;
    }
};

vector<Edge> graph[MAXSIZE];
bool isVisited[MAXSIZE];
int distanceTo[MAXSIZE];
int costTo[MAXSIZE]; // key point!
int totalCity, totalEdge;

void dijkstra(int src) {
    for (int i = 1; i <= totalCity; ++i) {
        isVisited[i] = false;
        distanceTo[i] = costTo[i] = INF;
    }
    distanceTo[src] = 0;
    costTo[src] = 0;
    priority_queue<Point> pointQueue;
    pointQueue.push(Point(src, 0));
    while (!pointQueue.empty()) {
        Point top = pointQueue.top();
        pointQueue.pop();
        int topIndex = top.index;
        if (!isVisited[topIndex]) {
            for (int i = 0; i < graph[topIndex].size(); ++i) {
                int destination = graph[topIndex][i].destination;
                int cost = graph[topIndex][i].cost;
                if (!isVisited[destination]) {
                    if (distanceTo[destination] > distanceTo[topIndex] + cost) {
                        distanceTo[destination] = distanceTo[topIndex] + cost;
                        pointQueue.push(Point(destination, distanceTo[destination]));
                        costTo[destination] = cost;
                    }
                    if (distanceTo[destination] == distanceTo[topIndex] + cost) {
                        costTo[destination] = min(costTo[destination], cost);
                    }
                }
            }   
        }
        isVisited[topIndex] = true;
    }
}

int main() {
    int aCity, bCity, cost;
    cin >> totalCity >> totalEdge;
    while (totalEdge--) {
        cin >> aCity >> bCity >> cost;
        graph[aCity].push_back(Edge(bCity, cost));
        graph[bCity].push_back(Edge(aCity, cost));
    }

    dijkstra(1);

    int ans = 0;
    for (int i = 2; i <= totalCity; ++i) {
        ans += costTo[i];
    }
    cout << ans << endl;
    return 0;
}

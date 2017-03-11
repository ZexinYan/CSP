#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map<int, int> hashTable;

class Cmp {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second || (a.second == b.second && a.first < b.first);
	}
};

int main() {
	int totalSize;
	cin >> totalSize;
	int tmpValue;
	while (totalSize--) {
		cin >> tmpValue;
		hashTable[tmpValue]++;
	}
	vector<pair<int, int> > table(hashTable.begin(), hashTable.end());
	sort(table.begin(), table.end(), Cmp());
	for (int i = 0; i < table.size(); i++) {
		cout << table[i].first << " " << table[i].second << endl;
	}
	return 0;
}

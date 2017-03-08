#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	vector<int> prices;
	int total; cin >> total;
	int pre = 0, now = 0, max = 0;
	for (int i = 0; i < total; ++i) {
		pre = now;
		cin >> now;
		if (i == 0) {
			continue;
		} else {
			max = abs(pre - now) > max ? abs(pre - now) : max;
		}
	}
	cout << max << endl;
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int total;
	cin >> total;
	vector<int> prices;
	vector<int> increase(total, 0);
	int tmp;
	for (int i = 0; i < total; ++i) {
		cin >> tmp;
		prices.push_back(tmp);
	}
	int ans = 0;
	for (int i = 1; i < total - 1; ++i)	{
		if (prices[i] - prices[i - 1] > 0 && prices[i] - prices[i + 1] > 0) {
			ans++;
		} else if (prices[i] - prices[i - 1] < 0 && prices[i] - prices[i + 1] < 0) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

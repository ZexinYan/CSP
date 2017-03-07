#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int total, tmp;
	vector<int> seq;
	cin >> total;
	for (int i = 0; i < total; ++i) {
		cin >> tmp;
		seq.push_back(tmp);
	}
	sort(seq.begin(), seq.end());
	int right = total / 2;
	int left = right;
	int mid = right;
	while (seq[right] == seq[total / 2]) {
		right--;
	}
	right++;
	while(seq[left] == seq[total / 2]) {
		left++;
	}
	left--;
	if (total % 2 == 0) {
		if (mid - right == left - mid + 1) {
			cout << seq[mid] << endl;
		} else {
			cout << -1 << endl;
		}
	} else {
		if (mid - right == left - mid) {
			cout << seq[mid] << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}

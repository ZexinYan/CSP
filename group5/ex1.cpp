#include <iostream>

using namespace std;

int main() {
	int arraySize, seqSize = 1;
	int prev = 0, now = 0;
	cin >> arraySize;
	prev = -1;
	cin >> prev;
	while (--arraySize) {
		cin >> now;
		if (prev != now) {
			seqSize++;
			prev = now;
		}
	}
	cout << seqSize << endl;
	return 0;
}
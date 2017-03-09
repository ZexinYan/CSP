#include <iostream>
#include <cstdlib>

using namespace std;

int toInt(char ch) {
	return ch - '0';
}

int main() {
	string num;
	cin >> num;
	int total = 0;
	for (int i = 0; i < num.size(); ++i) {
		total += toInt(num[i]);
	}
	cout << total << endl;
	return 0;
}

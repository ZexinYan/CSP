#include <iostream>
#include <vector>

using namespace std;

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		month[2]++;
	}
}

int main() {
	int year, day;
	cin >> year >> day;
	isLeapYear(year);
	for (int i = 1; i <= 12; ++i) {
		if (day > month[i]) {
			day -= month[i];
		} else {
			cout << i << endl;
			cout << day << endl;
			break;
		}
	}
	return 0;
}

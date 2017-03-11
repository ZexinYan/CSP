#include <iostream>
#include <vector>

using namespace std;

int day[201][13];

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		month[2] = 29;
	} else {
		month[2] = 28;
	}
}

void init() {
	day[0][1] = 2;
	for (int year = 0; year < 201; ++year) {
		if (year != 0) {
			day[year][1] = (day[year - 1][12] + 31) % 7 == 0 ? 7 : ((day[year - 1][12] + 31) % 7);
		}
		isLeapYear(year + 1850);
		for (int perMonth = 2; perMonth < 13; ++perMonth) {
			int elapse = month[perMonth - 1];
			elapse += day[year][perMonth - 1];
			elapse = elapse % 7 == 0 ? 7 : elapse % 7;
			day[year][perMonth] = elapse;
		}
	}
}

int main() {
	init();
	int a, b, c, y1, y2;
	cin >> a >> b >> c >> y1 >> y2;
	int yearMin = min(y1, y2);
	int yearMax = max(y1, y2);
	for (int startYear = yearMin; startYear <= y2; startYear++) {
		isLeapYear(startYear - 1850);
		int nowDay = 1;
		int startDay = day[startYear - 1850][a];
		int weekIndex = 1;
		while (!(weekIndex == b && startDay == c)) {
			startDay++;
			nowDay++;
			weekIndex = (nowDay - 1) / 7 + 1;
			if (startDay > 7) {
				startDay = 1;
			}
		}
		if (nowDay > month[a]) {
			cout << "none" << endl;
			continue;
		}
		cout << startYear << "/";
		if (a >= 10) {
			cout << a << "/";
		} else {
			cout << "0" << a << "/";
		}
		if (nowDay >= 10) {
			cout << nowDay << endl;
		} else {
			cout << "0" << nowDay << endl;
		}
	}
	return 0;
}


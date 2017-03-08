#include <iostream>
#include <vector>
using namespace std;

int salaryRange[] = {3500, 3500 + 1500, 3500 + 4500, 3500 + 9000, 3500 + 35000, 3500 + 55000, 3500 + 80000};
int rates[] = {3, 10, 20, 25, 30, 35, 45};
const int size = sizeof(salaryRange) / sizeof(int);

int afterTaxRange[size];

int main() {
	afterTaxRange[0] = salaryRange[0];

	for (int i = 1; i < size; ++i) {
		afterTaxRange[i] = afterTaxRange[i - 1] + 
						(salaryRange[i] - salaryRange[i - 1]) * (100 - rates[i - 1]) / 100;
	}

	int afterTaxIncome;
	cin >> afterTaxIncome;

	int level = 0;
	for (level = 0; level < size; ++level) {
		if (afterTaxIncome <= afterTaxRange[level]) {
			break;
		}
	}

	if (level != 0) {
		afterTaxIncome = salaryRange[level - 1] + (afterTaxIncome - afterTaxRange[level - 1]) * 100 / (100 - rates[level - 1]);
	}

	cout << afterTaxIncome << endl;
	return 0;
}

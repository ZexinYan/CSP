#include <iostream>
#include <vector>
using namespace std;

struct Row {
	int nowPos;
	int left;
	Row() {
		nowPos = 0;
		left = 5;
	}
};

int main() {
	vector<Row> train(20, Row());
	int size; cin >> size;
	while (size--) {
		int num;
		cin >> num;
		bool finish = false;
		for (int i = 0; i < 20; ++i) {
			if (train[i].left >= num) {
				train[i].left -= num;
				finish = true;
				for (int j = 1; j < num; ++j) {
					cout << (train[i].nowPos + j + i * 5) << " ";
				}
				cout << train[i].nowPos + num + i * 5 << endl;
				train[i].nowPos += num;
				break;
			}
		}
		if (!finish) {
			for (int i = 0; i < 20; ++i) {
				if (num == 0) {
					break;
				}
				while (train[i].left > 0 && num > 0) {
					if (num > 1) {
						cout << train[i].nowPos + 1 + i * 5 << " ";
					} else {
						cout << train[i].nowPos + 1 + i * 5 << endl;
					}
					num--;
					train[i].nowPos++;
					train[i].left--;
				}
			}
		}
	}
	return 0;
}

#include <iostream>
#include <map>
#include <cstring>

using namespace std;

string html;
char str[10000];
map<string, string> hashTable;

void getLine(char* c_str) {
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {
		*c_str++ = ch;
	}
	*c_str = '\0';
}

void render() {
	int leftBracket = 0;
	int rightBracket = 0;
	while ((leftBracket = html.find("{{")) != -1) {
		rightBracket = html.find(" }}", leftBracket);
		if (rightBracket == -1) {
			break;
		} else {
			string key = html.substr(leftBracket, rightBracket - leftBracket);
			html.erase(leftBracket, rightBracket - leftBracket + 3);
			html.insert(leftBracket, hashTable[key.substr(3, key.size() - 3)]);
		}
	}
}

int main() {
	int htmlLines, varSize;
	cin >> htmlLines >> varSize;
	string tmpForInput;
	getchar();
	while (htmlLines--) {
		getLine(str);
		html += str;
		html += '\n';
	}

	string key, value;
	while (varSize--) {
		cin >> key;
		getchar();
		getLine(str);
		value = str;
		hashTable[key] = value.substr(1, value.size() - 2);
	}

	render();

	cout << html;
	return 0;
}

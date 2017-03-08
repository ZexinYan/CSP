#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char str[1005];

void getLine(char* c_str) {
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch != ' ') {
            *c_str++ = ch;            
        }
    }
    *c_str = '\0';
}

int main() {
    int pathSize;
    string currentPath;
    cin >> pathSize >> currentPath;
    getchar();

    while (pathSize--) {
        string line;
        getLine(str);
        line = str;

        if (line.size() == 0) {
            cout << "/" << endl;
        } else {
            if (line[0] != '/') {
                line = currentPath + "/" + line + "/";
            } else {
                line += "/";
            }

            int indexForPoint;
            while ((indexForPoint = line.find("/./")) != string::npos) {
                line.erase(indexForPoint + 1, 2);
            }

            int indexForTwoSolidus;

            while ((indexForTwoSolidus = line.find("//")) != -1) {
                int indexEnd = indexForTwoSolidus;
                int times = 0;
                while (line[indexEnd] == '/') {
                    times++;
                    indexEnd++;
                }
                line.erase(indexForTwoSolidus + 1, times -1);
            }

            int indexForDoublePoint;
            while ((indexForDoublePoint = line.find("/../")) != -1) {
                if (indexForDoublePoint == 0) {
                    line.erase(1, 3);
                } else {
                    int times = 0;
                    indexForDoublePoint--;
                    while (line[indexForDoublePoint] != '/') {
                        indexForDoublePoint--;
                        times++;
                    }
                    line.erase(indexForDoublePoint + 1, times + 4);
                }
            }

            if (line[line.size() - 1] == '/') {
                line.erase(line.size() - 1, 1);
            }
            if (line.size() == 0) {
                line = "/";
            }
            cout << line << endl;
        }
    }
    return 0 ;
}

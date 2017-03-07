#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	map<string, int> qualifications;
	map<string, vector<pair<string, int> > > roles;
	map<string, vector<pair<string, int> > > users;
	int qualificationSize, roleSize, userSize;

	cin >> qualificationSize;
	while (qualificationSize--) {
		string qualif;
		cin >> qualif;
		for (int i = 0; i < qualif.size(); ++i) {
			if (qualif[i] == ':') {
				qualifications.insert(pair<string, int>(qualif.substr(0, i), atoi(qualif.substr(i + 1, qualif.size()).c_str())));
				break;
			}
			if (i == qualif.size() - 1) {
				qualifications.insert(pair<string, int>(qualif, -1));
			}
		}
	}

	cin >> roleSize;
	while (roleSize--) {
		string roleName;
		int t_size;
		cin >> roleName >> t_size;
		while (t_size--) {
			string qua;
			cin >> qua;
			for (int i = 0; i < qua.size(); ++i) {
				if (qua[i] == ':') {
					roles[roleName].push_back(pair<string, int>(qua.substr(0, i), atoi(qua.substr(i + 1, qua.size()).c_str())));
					break;
				}
				if (i == qua.size() - 1) {
					roles[roleName].push_back(pair<string, int>(qua, -1));
				}
			}
		}
	}

	cin >> userSize;
	while (userSize--) {
		string userName;
		int size;
		cin >> userName >> size;
		while (size--) {
			string role;
			cin >> role;
			map<string, vector<pair<string, int> > >::iterator iter = roles.find(role);
			for (int i = 0; i != (*iter).second.size(); i++) {
				if (users[userName].size() == 0) {
					users[userName].push_back((*iter).second[i]);
					continue;
				}
				for (int j = 0; j < users[userName].size(); ++j) {
					if (users[userName][j].first == (*iter).second[i].first) {
						if (users[userName][j].second < (*iter).second[i].second) {
							users[userName][j].second = (*iter).second[i].second;
						}
						break;
					}
					if (j == users[userName].size() - 1) {
						users[userName].push_back((*iter).second[i]);
					}
				}
			}
		}
	}

	// for_each(users.begin(), users.end(), [](pair<string, vector<pair<string, int> > > each) {
	// 	cout << each.first << endl;
	// 	for (int i = 0; i < each.second.size(); ++i) {
	// 		cout << each.second[i].first << ":" << each.second[i].second << endl;
	// 	}
	// });

	// cout << endl;

	int querySize;
	cin >> querySize;
	vector<pair<string, int> > vec;
	while (querySize--) {
		string userName, quaName;
		cin >> userName >> quaName;
		vec = users[userName];
		if (vec.size() == 0) {
			cout <<  "false" << endl;
			continue;
		} else {
			string name; int level;
			for (int i = 0; i < quaName.size(); ++i) {
				if (quaName[i] == ':') {
					name = quaName.substr(0, i);
					level = atoi(quaName.substr(i + 1, quaName.size()).c_str());
					break;
				}
				if (i == quaName.size() - 1) {
					name = quaName;
					level = -1;
				}
			}
			for (int i = 0; i < vec.size(); ++i) {
				if (vec[i].first == name) {
					if (vec[i].second != -1 && level == -1) {
						cout << vec[i].second << endl;
						break;
					}
					if (vec[i].second >= level) {
						cout << "true" << endl;
						break;
					}
				}
				if (i == vec.size() - 1) {
					cout << "false" << endl;
				}
			}
		}
	}
	return 0;
}

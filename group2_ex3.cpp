#include <iostream>
#include <vector>

using namespace std;

struct Carder {
	int health;
	int attack;
	Carder(int t_attack = 0, int t_health = 0) :
		attack(t_attack), health(t_health) {}
};

class Player {
public:
	vector<Carder> attendants;
	Carder hero;

	Player() {
		hero = Carder(0, 30);
	}
};

int main() {
	Player firstPlayer;
	Player secondPlayer;
	int size;
	cin >> size;
	bool first = true;
	Player* onPlayer = &firstPlayer;
	Player* offPlayer = &secondPlayer;
	while (size--) {
		string action;
		cin >> action;
		if (action == "end") {
			first = !first;
		} else {
			if (first) {
				onPlayer = &firstPlayer;
				offPlayer = &secondPlayer;
			} else {
				onPlayer = &secondPlayer;
				offPlayer = &firstPlayer;
			}
			if (action == "summon") {
				int position, attack, health;
				cin >> position >> attack >> health;
				onPlayer->attendants.insert(onPlayer->attendants.begin() + position - 1, Carder(attack, health));					
			}
			if (action == "attack") {
				int attacker, defender;
				cin >> attacker >> defender;
				if (defender == 0) {
					attacker--;
					offPlayer->hero.health -= onPlayer->attendants[attacker].attack;
				} else {
					attacker--;
					defender--;
					onPlayer->attendants[attacker].health -= offPlayer->attendants[defender].attack;
					offPlayer->attendants[defender].health -= onPlayer->attendants[attacker].attack;
					if (onPlayer->attendants[attacker].health <= 0) {
						onPlayer->attendants.erase(onPlayer->attendants.begin() + attacker);
					}
					if (offPlayer->attendants[defender].health <= 0) {
						offPlayer->attendants.erase(offPlayer->attendants.begin() + defender);
					}
				}
			}
		}
	}
	if (firstPlayer.hero.health < 0 && secondPlayer.hero.health < 0) {
		cout << 0 << endl;
	} else if (firstPlayer.hero.health <= 0) {
		cout << -1 << endl;
	} else {
		cout << 1 << endl;
	}

	cout << firstPlayer.hero.health << endl;

	cout << firstPlayer.attendants.size();
	for (int i = 0; i < firstPlayer.attendants.size(); i++) {
		cout << " " << firstPlayer.attendants[i].health;
	}
	cout << endl;

	cout << secondPlayer.hero.health << endl;

	cout << secondPlayer.attendants.size();
	for (int i = 0; i < secondPlayer.attendants.size(); i++) {
		cout << " " << secondPlayer.attendants[i].health;
	}
	cout << endl;

	return 0;
}

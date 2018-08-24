#include <iostream>
#include <string>
#include "helper.h" // helper.h includes Player.cpp
using namespace std;

// arr size
// cout << (sizeof(team1)/sizeof(*team1)) << endl;

int main() {

	// Total = 100;
	Player red = {"Red", 80, 5, 15, "redAttack", 1, 4};
	Player orange = {"Orange", 70, 25, 5, "orangeAttack", 1, 8};
	Player yellow = {"Yellow", 60, 20, 20, "yellowAttack", 1, 6};

	Player green = {"Green", 80, 15, 5, "greenAttack", 2, 2};
	Player blue = {"Blue", 70, 20, 10, "blueAttack", 2, 1};
	Player purple = {"Purple", 60, 25, 15, "purpleAttack", 2, 5};

	Player team1[] = {red, orange, yellow};
	Player team2[] = {green, blue, purple};

	int t1S = (sizeof(team1) / sizeof(*team1));
	int t2S = (sizeof(team2) / sizeof(*team2));

	listTeams(team1, team2, t1S, t2S);
	fight(team1[0], team2[0]);
	fight(team1[1], team2[1]);
	fight(team1[2], team2[2]);

	printStats(team1, t1S);
	printStats(team2, t2S);

	system("pause");
	return 0;
}
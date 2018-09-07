#include <iostream>
#include <string>
#include "helper.h" // helper.h includes Player.cpp
using namespace std;

// To Do
	// random attacks
	// take player out of array when they die
		// or skip over them


// arr size
// cout << (sizeof(team1)/sizeof(*team1)) << endl;

int main() {

	int roundNum = 1;

	// Total = 100;
	// CHECK TOTALS / BALANCE TEAMS
	Player red = {"Red", 80, 50, 15, "redAttack", 1, 4};
	Player orange = {"Orange", 70, 25, 5, "orangeAttack", 1, 12};
	Player yellow = {"Yellow", 50, 30, 20, "yellowAttack", 1, 6};

	Player green = {"Green", 80, 15, 5, "greenAttack", 2, 2};
	Player blue = {"Blue", 70, 20, 10, "blueAttack", 2, 9};
	Player purple = {"Purple", 40, 25, 35, "purpleAttack", 2, 5};

	Player team1[] = {red, orange, yellow};
	Player team2[] = {green, blue, purple};

	int t1S = (sizeof(team1) / sizeof(*team1));
	int t2S = (sizeof(team2) / sizeof(*team2));

	listTeam(team1, t1S, 1);
	listTeam(team2, t2S, 2);

	// while both teams have players remaining
	// (check length)
		// keep fighting

	while (t1S > 0 && t2S > 0) {
		cout << "Round " << roundNum << endl;

		// fight
		team2[0].health = fightPlayers(team1[0], team2[0]);
		team2[1].health = fightPlayers(team1[1], team2[1]);
		team2[2].health = fightPlayers(team1[2], team2[2]);

		team1[0].health = fightPlayers(team2[0], team1[0]);
		team1[1].health = fightPlayers(team2[1], team1[1]);
		team1[2].health = fightPlayers(team2[2], team1[2]);

		// print
		printStats(team1, t1S);
		printStats(team2, t2S);

		// check if anyone has died
		checkForDeath(team1, t1S);
		checkForDeath(team2, t2S);

		// update tS
		t1S = updateTS(team1, t1S);
		t2S = updateTS(team2, t2S);

		// test
		/*cout << "T1: " << t1S << endl;
		cout << "T2: " << t2S << endl;*/

		roundNum++;
	}

	system("pause");
	return 0;
}
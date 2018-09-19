#include <iostream>

#include "helper.h"

using std::cout;
using std::endl;


int main() {

	// teams
	Player red("Red", 80, 50, 15, "redAttack", 1, 4);
	Player orange("Orange", 70, 25, 5, "orangeAttack", 1, 12);
	Player yellow("Yellow", 50, 30, 20, "yellowAttack", 1, 6);

	Player green("Green", 80, 15, 5, "greenAttack", 2, 2);
	Player blue("Blue", 70, 20, 10, "blueAttack", 2, 9);
	Player purple("Purple", 40, 25, 35, "purpleAttack", 2, 5);

	Player team1[] = { red, orange, yellow };
	Player team2[] = { green, blue, purple };

	int teamSize = 3;

	// print welcome
	printWelcome();

	// list teams
	printTeam(team1, "Team 1", teamSize);
	printTeam(team2, "Team 2", teamSize);

	// this is an infinite loop that breaks out when one
	// team dies
	int round = 1;
	int defenderIdx = -1;
	for (;;) {
		// Team 1 attacking
		cout << "\nRound " << round << " - Team 1\n" << endl;
		cout << "Press [ ENTER ] to continue.\n" << endl;
		system("pause");
		// stats for both teams
		cout << endl;
		printBasicStats(team1, teamSize);
		printBasicStats(team2, teamSize);
		// choose defender
		defenderIdx = chooseRandomOpponent(team2, teamSize);
		// fight
		team2[defenderIdx].health -= fight(team1[0], team2[defenderIdx]);
		// change color
		if (checkForDeath(team2[defenderIdx])) {
			team2[defenderIdx].color = 8;
		}
		// sort
		sortTeam(team2, 3);
		// new stats
		printBasicStats(team1, teamSize);
		printBasicStats(team2, teamSize);
		// check for remaining members
		if (!hasLivingMember(team2, teamSize)) {
			cout << "\nTeam 1 wins!" << endl;
			// something else here?
			break;
		}
		// Team 2 attacking
		cout << "\nRound " << round << " - Team 2\n" << endl;
		cout << "Press [ ENTER ] to continue.\n" << endl;
		system("pause");
		// stats for both teams
		cout << endl;
		printBasicStats(team2, teamSize);
		printBasicStats(team1, teamSize);
		// choose defender
		defenderIdx = chooseRandomOpponent(team1, teamSize);
		// fight
		team1[defenderIdx].health -= fight(team2[0], team1[defenderIdx]);
		// change color
		if (checkForDeath(team1[defenderIdx])) {
			team1[defenderIdx].color = 8;
		}
		// sort
		sortTeam(team1, 3);
		// new stats
		printBasicStats(team2, teamSize);
		printBasicStats(team1, teamSize);
		// check for remaining members
		if (!hasLivingMember(team1, teamSize)) {
			cout << "\nTeam 2 wins!" << endl;
			// something else here?
			break;
		}
		round++;
	}

	system("pause");
	return 0;
}
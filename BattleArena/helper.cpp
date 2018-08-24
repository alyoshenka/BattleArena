#include <iostream>
#include "helper.h" // includes Player.cpp
// #include "Player.cpp"
#include <windows.h> // Sleep()
#include <conio.h> // color
#include <stdio.h>
	/*
	The different color codes are

	0   BLACK
	1   BLUE
	2   GREEN
	3   CYAN
	4   RED
	5   MAGENTA
	6   BROWN
	7   LIGHTGRAY
	8   DARKGRAY
	9   LIGHTBLUE
	10  LIGHTGREEN
	11  LIGHTCYAN
	12  LIGHTRED
	13  LIGHTMAGENTA
	14  YELLOW
	15  WHITE
	*/

// This function sets the color of the text
void textcolor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Overload
// This function sets the color of the text to white
void textcolor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


// This function lists the teams and their members
void listTeams(Player team1[], Player team2[], int t1S, int t2S) {
	cout << "Team 1:" << endl;
	for (int i = 0; i < t1S; i++) {
		cout << team1[i].name << endl;
	}

	cout << endl;

	cout << "Team 2:" << endl;
	for (int i = 0; i < t2S; i++) {
		cout << team2[i].name << endl;
	}
}

// This function sorts the teams in descending order
// according to their health
void sortTeams(Player t[], int tS) {
	Player swap = {};
	for (int i = 0; i < tS; i++) {
		for (int j = 0; j < tS - 1; j++) {
			if (t[j].health < t[j + 1].health) {
				swap = t[j];
				t[j] = t[j + 1];
				t[j + 1] = swap;
			}
		}
	}
}

// This function makes the team mebers of equal indexes
// fight each other
int fight(Player p1, Player p2) {
	int damage = 0;
	cout << endl;
	cout << p1.name << " fights " << p2.name << endl;
	cout << p1.name << " hits " << p2.name << " with " <<
		p1.attackName << " for " << p1.attackP << " points."
		<< endl;
	cout << p2.name << " defends with " << p2.defP <<
		" points." << endl;
	damage = p1.attackP - p2.defP;
	if (damage < 0) {
		damage = 0;
	}
	cout << p2.name << " takes " << damage <<
		" damage. " << endl;
	p2.health -= damage;
	cout << p2.name << ": " << p2.health << " HP"
		<< endl;
	return damage;
}

// THIS IS REDUNDANT NOW
// This function tells when a player has died
void isDead(Player p) {
	cout << p.name << " is dead." << endl;
}

// This function prints out the entire stats
// of a team
void printStats(Player t[], int tS) {
	cout << endl;
	cout << "Team: " << t[0].team << endl;
	for (int i = 0; i < tS; i++) {
		textcolor(t[i].color);
		cout << "Player: " << t[i].name << endl;
		cout << "Health: " << t[i].health << endl;
		cout << "Attack: " << t[i].attackP << " points" << endl;
		cout << "Defense: " << t[i].defP << " points" << endl;
		cout << "Attack Name: " << t[i].attackName << endl;
		cout << endl;
	}
	textcolor();
}

// This function tests to see if any players have dies
// and if so prints which player
void checkForDeath(Player t[], int tS) {
	cout << endl;
	for (int i = 0; i < tS; i++) {
		// if dead
		if (t[i].health <= 0) {
			cout << t[i].name << " has died." << endl;
			// remove from array

			// change color to gray
			t[i].color = 8;

			// pause so I can see what is happening
			system("pause");
		}
	}
}










// This function runs the program
void go() {

}

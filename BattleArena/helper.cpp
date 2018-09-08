#include <iostream>
#include "helper.h"
#include <windows.h> // Sleep()
#include <conio.h> // color
#include <stdio.h>
#include <time.h>
// #include <unistd.h> // sleep
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

// NOTE usint Sleep() won't work on other OSs

// To Do
// function to determine random matchups
// function to sort teams by health

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
void listTeam(Player team[], int tS, int teamNum) {
	textcolor();
	cout << "Team " << teamNum << ":" << endl;
	for (int i = 0; i < tS; i++) {
		textcolor(team[i].color);
		cout << team[i].name << endl;
	}
	textcolor();
	cout << endl;
}

// This function sorts the teams in descending order
// according to their health
void sortTeam(Player t[], int tS) {
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
int fightPlayers(Player p1, Player p2) {
	int delayTime = 500;
	int damage = 0;
	cout << endl;
	textcolor(p1.color);
	cout << p1.name;
	textcolor();
	cout << " fights ";
	textcolor(p2.color);
	cout << p2.name << endl;
	Sleep(delayTime);
	textcolor(p1.color);
	cout << p1.name;
	textcolor();
	cout << " hits ";
	textcolor(p2.color);
	cout << p2.name;
	textcolor();
	cout << " with ";
	textcolor(p1.color); 
	cout << p1.attackName;
	textcolor();
	cout << " for " << p1.attackP << " points." << endl;
	Sleep(delayTime);
	textcolor(p2.color);
	cout << p2.name;
	textcolor();
	cout << " defends with " << p2.defP <<
		" points." << endl;
	Sleep(delayTime);
	damage = p1.attackP - p2.defP;
	if (damage < 0) {
		damage = 0;
	}
	textcolor(p2.color);
	cout << p2.name;
	textcolor();
	cout << " takes " << damage <<
		" damage. " << endl;
	Sleep(delayTime);
	p2.health -= damage;
	textcolor(p2.color);
	cout << p2.name;
	textcolor();
	cout << ": " << p2.health << " HP"
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
		cout << "Player: ";
		textcolor(t[i].color);
		std::cout << t[i].name << endl;
		textcolor();
		cout << "Health: " << t[i].health << endl;
		cout << "Attack: " << t[i].attackP << " points" << endl;
		cout << "Defense: " << t[i].defP << " points" << endl;
		cout << "Attack Name: " << t[i].attackName << endl;
		cout << endl;
	}
}

// This function tests to see if any players have died
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

// This function updates the team size
int updateTS(Player t[], int tS) {

	int newTS = 0;

	for (int i = 0; i < tS; i++) {
		if (t[i].health != 0) {
			newTS++;
		}
	}
	return newTS;
}

// Utilize rand()
// This functions makes two teams fight
void fightTeams(Player t1[], Player t2[], int t1S, int t2S) {
	// sort teams
	// determine number of eligible players on each team

	// iterate through arrays and determine if player is dead
	// this is determined by health
	int t1eligible = 0;
	int t2eligible = 0;
}

// Put rand() here
// picks a random player on the team to fight
// and returns the index value of said player
int pickPlayer(Player t[]) {

	// enable random function
	srand(time(NULL));

	// iterate through array and determine how many players
	// are still alive
	int count = 0;
	// MAKE DEPENDANT
	for (int i = 0; i < 3; i++) {
		// if still alive
		if (t[i].health > 0) {
			count++;
		}
	}

	// get a random value within this range
	int playerIdx = 0;
	playerIdx = rand() % count + 1;

	// iterate through array, skipping over dead players,
	// to find the playerIdx nth player that is not dead
	for (int i = 0; i < count; i++) {
		if (t[i].health > 0) {
			return i;
		}
		else {
			// ????
		}
	}
}










// This function runs the program
void go() {

}

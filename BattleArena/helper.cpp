#include <iostream>
// #include <conio.h>
#include <windows.h>
#include <string>
#include <time.h>


#include "Player.h"

using std::cout;
using std::endl;

// This function sets the color of the text
void textcolor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Overload
// This function sets the color of the text to white
void textcolor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// This function prints the welcome message for the game.
void printWelcome() {
	cout << "\n Welcome to Battle Arena!\n" << endl;
	cout << "Press [ ENTER ] to begin.\n" << endl;
	system("pause");
	cout << "\nHere are the teams:\n" << endl;
}

// This function prints the team members.
void printTeam(Player team[], string name, int tSize) {
	textcolor();
	cout << endl;
	cout << name << ":" << endl;
	for (int i = 0; i < tSize; i++) {
		textcolor(team[i].color);
		cout << team[i].name << endl;
	}
	textcolor();
	cout << endl;
}

// This function makes two players fight each other and 
// returns the damage sustained by the defender, p2
int fight(Player p1, Player p2) {
	// print stuff
	int delayTime = 500;
	int damage = p1.attackP - p2.defP;
	if (damage < 0) {
		damage = 0;
	}
	cout << endl;
	cout << "  [ ";
	textcolor(p1.color);
	cout << p1.name;
	textcolor();
	cout << " fights ";
	textcolor(p2.color);
	cout << p2.name;
	textcolor();
	cout << " ]\n" << endl;
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
	textcolor(p2.color);
	cout << p2.name;
	textcolor();	
	cout << " takes " << damage <<
		" damage.\n" << endl;	
	Sleep(delayTime);
	textcolor(p2.color);
	cout << p2.name;
	textcolor();
	cout << ": " << p2.health - damage << " HP\n" << endl;
	return damage;
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
		cout << "Health: " << t[i].health << " points" << endl;
		cout << "Attack: " << t[i].attackP << " points" << endl;
		cout << "Defense: " << t[i].defP << " points" << endl;
		cout << "Attack Name: ";
		textcolor(t[i].color);
		cout << t[i].attackName << endl;
		textcolor();
		cout << endl;
	}
}

// This function prints out only the Player
// name and health points
void printBasicStats(Player t[], int tS) {
	cout << "Team: " << t[0].team << endl;
	for (int i = 0; i < tS; i++) {
		textcolor(t[i].color);
		std::cout << t[i].name;
		textcolor();
		cout << ": " << t[i].health << " HP  ";
	}
	cout << endl;
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

// This function searches the team and returns true 
// if there is a living member, false if not
bool hasLivingMember(Player t[], int tS) {
	for (int i = 0; i < tS; i++) {
		if (t[i].health > 0) {
			return true;
		}
	}
	return false;
}

// This function returns a random index of a player
// to fight
int chooseRandomOpponent(Player t[], int tS) {
	srand(time(NULL));
	// number of remaining players
	int count = 0;
	for (int i = 0; i < tS; i++) {
		if (t[i].health > 0) {
			count++;
		}
	}
	// pick random number 0 - ( count-1 ) (for index)
	return rand() % count;
}

// This function checks if a Player has died and if so
// displays a message and sets the color to gray
bool checkForDeath(Player p) {
	if (p.health <= 0) {
		cout << endl;
		textcolor(p.color);
		cout << p.name;
		textcolor();
		cout << " has died!" << endl;
		cout << endl;
		return true;
	}
	return false;
}

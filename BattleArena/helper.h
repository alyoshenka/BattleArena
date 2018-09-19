#pragma once

#include "Player.h"

void printWelcome();

void printTeam(Player team[], string name, int tSize);

int fight(Player p1, Player p2);

void printStats(Player t[], int tS);

void printBasicStats(Player t[], int tS);

void sortTeam(Player t[], int tS);

bool hasLivingMember(Player t[], int tS);

int chooseRandomOpponent(Player t[], int tS);

bool checkForDeath(Player p);

bool checkForDeath(Player p);

#pragma once
#include "Player.cpp"

void textcolor(int color);

void listTeam(Player team[], int tS, int teamNum);

void sortTeams(Player t[],int tS);

int fightPlayers(Player p1, Player p2);

void isDead(Player p);

void printStats(Player p[], int tS);

void checkForDeath(Player t[], int tS);

int updateTS(Player t[], int tS);

void fightTeams(Player t1[], int t1S, Player t2[], int t2S);



void go();


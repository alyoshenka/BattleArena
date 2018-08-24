#pragma once
#include "Player.cpp"

void textcolor(int color);

void listTeams(Player team1[], Player team2[], int t1S, int t2S);

void sortTeams(Player t[],int tS);

void fight(Player p1, Player p2);

void isDead(Player p);

void printStats(Player p[], int tS);


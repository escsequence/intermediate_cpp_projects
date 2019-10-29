#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Player.h"
#include <limits>

using namespace std;

void computePaymentAndDeductions(Player*);


void generatePayStubs(Player*, Agent*);
void generatePlayerPayStubs(Player*);
void generateAgentPayStubs(Agent*);


void displayPlayers(Player*);
void displayAgents(Agent*);

int getMenuInputChoice();
int getPlayerChoice(Player*);
int getAgentChoice(Agent*);
int findPlayerByName(string, Player*);
int findAgentByName(string, Agent*);

Agent* generateAgents();
Agent getAgentInformation();
void displayAgentInformation();

Player* generatePlayers(Agent*);
Player getPlayerInformation();

string getStringFromUser(string);
double getValueFromUser(string);

void updateAgentForPlayer(Player*, Agent*);
void updatePlayerSalary(Player*);
void displayMenu();

bool valueWithin(double, double, double);

#endif

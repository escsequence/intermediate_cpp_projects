#include "Player.h"
using namespace std;
/*
* NBATeam.cpp
* Written by:
* Written for: project 2
* Created on:
*/
const int AGENT_COUNT = 6;
const int PLAYER_COUNT = 15;
void generatePayStub(Agent[], int, Player[], int);

int getMenuInputChoice();

Agent* generateAgents();
Agent getAgentInformation();
void displayAgentInformation();

Player* generatePlayers(Agent*);
Player getPlayerInformation();

string getStringFromUser(string);
double getValueFromUser(string);


/**
* Program for managing a NBA team
*/
int main()
{
	//Create profiles for all 6 agents
	Agent* myAgents = generateAgents();

	//Create files for 15 players, associate agent with the player
	Player* myPlayers = generatePlayers(myAgents);


	//Display a menu and allow one to input the choice
	cout << "--------------------- NBA TEAM MANAGER ---------------------" << endl;
	cout << "1" << "\t-\t" << "Change agent for player" << endl;
	cout << "2" << "\t-\t" << "Change salary for player" << endl;
	cout << "3" << "\t-\t" << "Generate paystub for all players and all agents" << endl;
	cout << "4" << "\t-\t" << "Display agents and players" << endl;
	cout << "5" << "\t-\t" << "Quit" << endl;
	cout << "------------------------------------------------------------" << endl;

	bool menuIsOpen = true;
	while(menuIsOpen) {
		switch(getMenuInputChoice()) {
			case 1:
				
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				menuIsOpen = false;
				break;
			default:
				cout << "Invalid input, please try again." << endl;
		};
	}
	//Create a while loop to allow one to conduct different service
		//Ask user to make their choice

		//Choice 1: switch agent and then redisplay the menu

		//Choice 2: change salary for a player, then redisplay the menu

		//Choice 3: generate paystub for all players and agents, and then quit

}

int getMenuInputChoice() {
	int choice = -1;
	while(choice == -1) {
		cout << "Enter a command: ";
		cin >> choice;
		if (cin.fail() || choice == -1) {
			cout << "Invalid input, please try again." << endl;
			cin.clear();
			choice = -1;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return choice;
}

int getAgentChoice() {
	int choice = -1;
	while(choice == -1) {
		cout << "Select an agent: ";
		cin >> choice;
		if (cin.fail() || choice <= 0 || choice > AGENT_COUNT) {
			cout << "Invalid agent, please try again." << endl;
			cin.clear();
			choice = -1;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return choice;
}

Agent getAgentInformation() {
	return Agent(getStringFromUser("Name"), getValueFromUser("Stipend Ratio"));
}

std::string getStringFromUser(string print) {
	cout << print << ": ";
	string value;
	getline(cin, value);
	return value;
}

Agent* getAgentFromUser(Agent *myAgents) {
	for (int index = 0; index < AGENT_COUNT; ++index) {
		cout << "Agent #" << (index+1) << " | ";
		myAgents[index].printBasic();
		cout << endl;
	}
	return &myAgents[getAgentChoice()];
}

double getValueFromUser(string message) {
	double value = -1;
	while(value <= -1) {
		cout << message << ": ";
		cin >> value;
		if (cin.fail() || value <= -1) {
			cout << "Invalid input, please try again." << endl;
			cin.clear();
			value = -1;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return value;
}

Agent* generateAgents() {
	Agent* myAgents = new Agent[AGENT_COUNT];
	for (int index = 0; index < AGENT_COUNT; ++index) {
		cout << "[ Agent #" << (index+1) << " ]: " << endl;
		myAgents[index] = getAgentInformation();
	}
	return myAgents;
}

Player getPlayerInformation(Agent* myAgents) {
	return Player(getStringFromUser("Name"),
								getValueFromUser("Salary"),
								getAgentFromUser(myAgents));
}

Player* generatePlayers(Agent* myAgents) {
	Player* myPlayers = new Player[PLAYER_COUNT];
	for (int index = 0; index < PLAYER_COUNT; ++index) {
		cout << "[ Player #" << (index+1) << " ]: " << endl;
		myPlayers[index] = getPlayerInformation(myAgents);
	}
	return myPlayers;
}

void generatePayStub(Agent agents[], int agentNumber, Player players[], int playerNumber)
{
	//Go through all 15 players to decide each agent's income
		//Compute deduction for each player

		//Add the deduction as payment to this player's agent
		//	(An agent could get payment from multiple players)

	//Generate pay stub for all players

	//Generate pay stub for all agents
}

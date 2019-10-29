#include "Functions.h"
/*
* NBATeam.cpp
* Written by:			James Johnston
* Written for: 		Project 2
* Created on:			10/29/19
*/

/**
* Program for managing a NBA team
* @return int,	Program termination status.
*/
int main()
{
	//Create profiles for all agents
	Agent* myAgents = generateAgents();

	//Create files for players - and associate agent with the player
	Player* myPlayers = generatePlayers(myAgents);

	// Menu is open by default
	bool menuIsOpen = true;

	// Loop while menu is open
	while(menuIsOpen) {
		//Display a menu and allow one to input the choice
		displayMenu();

		// Get the input
		switch(getMenuInputChoice()) {
			case 1:
			//Choice 1: switch agent and then redisplay the menu
				// Update the agent for a player
				updateAgentForPlayer(myPlayers, myAgents);

				break;
			case 2:
			//Choice 2: change salary for a player, then redisplay the menu

				//Change salary for player
				updatePlayerSalary(myPlayers);

				break;
			case 3:
			//Choice 3: generate paystub for all players and agents, and then quit

				// Generate paystubs
				generatePayStubs(myPlayers, myAgents);

				// Close menu
				menuIsOpen = false;

				break;
			default:

				// Message to display for incorrect input
				cout << "Invalid input, please try again." << endl;

		};
	}

	// Program terminated.
	return 0;
}

/**
 * GenerateAgents
 */
Agent* generateAgents() {
	
	// Display what were doing.
	cout << "===== Creating Agents =====" << endl;

	// Create a new Agent array based on a constant size
	Agent* myAgents = new Agent[AGENT_COUNT];

	// Loop through, and add the objects in the array
	for (int index = 0; index < AGENT_COUNT; ++index) {
		cout << "[ Agent #" << (index+1) << " ]: " << endl;
		myAgents[index] = getAgentInformation();
	}

	// Formatting.
	cout << "===========================" << endl;

	// Return the array.
	return myAgents;
}

/**
 * GeneratePlayers
 */
Player* generatePlayers(Agent* myAgents) {
	cout << "==== Creating Players =====" << endl;
	Player* myPlayers = new Player[PLAYER_COUNT];
	for (int index = 0; index < PLAYER_COUNT; ++index) {
		cout << "[ Player #" << (index+1) << " ]: " << endl;
		myPlayers[index] = getPlayerInformation(myAgents);
	}
	cout << "===========================" << endl;
	return myPlayers;
}

/**
* Display a menu with the selections for the main menu.
*
* @param	none
* @return none
*/
void displayMenu() {
	cout << "--------------------- NBA TEAM MANAGER ---------------------" << endl;
	cout << "1" << "\t-\t" << "Change agent for player" << endl;
	cout << "2" << "\t-\t" << "Change salary for player" << endl;
	cout << "3" << "\t-\t" << "Generate paystub for all players and all agents" << endl;
	cout << "------------------------------------------------------------" << endl;
}

void updateAgentForPlayer(Player *myPlayers, Agent *myAgents) {

	// Display players
	displayPlayers(myPlayers);

	// Get the player we want to change
	Player *selectedPlayer = &myPlayers[getPlayerChoice(myPlayers)];

	cout << "Selected Player: ";

	// Prints out the agnet information for this player (currently)
	selectedPlayer->printBasic();

	// Formatting
	cout << endl;

	// Show all the agents
	displayAgents(myAgents);

	// Get the agent we want to update with
	Agent *selectedAgent = &myAgents[getAgentChoice(myAgents)];

	// Update the selected player with the agent
	selectedPlayer->setAgent(selectedAgent);
}

void updatePlayerSalary(Player *myPlayers) {

	// Display players
	displayPlayers(myPlayers);

	// Get the player we want to change
	Player *selectedPlayer = &myPlayers[getPlayerChoice(myPlayers)];

	// Current information displayed
	selectedPlayer->printBasic();

	// formatting
	cout << endl;

	// Set the salary to a new salary from the user
	selectedPlayer->setSalary(getValueFromUser("New Salary"));

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

int findPlayerByName(string name, Player *players) {
	int returnIndex = -1;
	for (int index = 0; index < PLAYER_COUNT; ++index) {
		if (players[index].nameEquals(name)) {
			if (returnIndex == -1)
				returnIndex = index;
			else
				returnIndex = -2;
		}
	}
	return returnIndex;
}

int findAgentByName(string name, Agent *agents) {
	int returnIndex = -1;
	for (int index = 0; index < AGENT_COUNT; ++index) {
		if (agents[index].nameEquals(name))  {
			if (returnIndex == -1)
				returnIndex = index;
			else
				returnIndex = -2;
		}
	}
	return returnIndex;
}

int getPlayerChoice(Player *players) {
	int choice = -1;
	while(choice == -1) {
		cout << "Select a Player (by name): ";
		string name;
		getline(cin, name);
		choice = findPlayerByName(name, players);
		//cin >> choice;
		if (cin.fail() || choice < 0) {
			cout << "Invalid player, please try again." << endl;
			cin.clear();
			choice = -1;
		}
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return choice;
}

int getAgentChoice(Agent *agents) {
	int choice = -1;
	while(choice == -1) {
		cout << "Select an Agent (by name): ";
		string name;
		getline(cin, name);
		choice = findAgentByName(name, agents);
		//cin >> choice;
		if (cin.fail() || choice < 0) {
			cout << "Invalid agent, please try again." << endl;
			cin.clear();
			choice = -1;
		}
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void displayAgents(Agent *agents) {
	cout << "=== Agents ===" << endl;
	for (int index = 0; index < AGENT_COUNT; ++index) {
		cout << "Agent #" << (index+1) << " | ";
		agents[index].printBasic();
		cout << endl;
	}
	cout << "==============" << endl;
}

void displayPlayers(Player *players) {
	cout << "=== Players ===" << endl;
	for (int index = 0; index < PLAYER_COUNT; ++index) {
		cout << "Player #" << (index+1) << " | ";
		players[index].printBasic();
		cout << " | ";
		players[index].printAgent();
	}
	cout << "===============" << endl;
}

Agent* getAgentFromUser(Agent *myAgents) {
	displayAgents(myAgents);
	return &myAgents[getAgentChoice(myAgents)];
}

bool valueWithin(double value, double min, double max) {
	return (value >= min && value <= max);
}

double getValueFromUser(string message) {
	double value = -1;
	double min_value = std::numeric_limits<double>::min();
	double max_value = std::numeric_limits<double>::max();

	if (message == "Stipend Ratio") {
		min_value = MIN_STIPEND_RATIO;
		max_value = MAX_STIPEND_RATIO;
	}

	while(value <= -1) {
		cout << message << ": ";
		cin >> value;
		if (cin.fail() || value <= -1) {
			cout << "Invalid input, please try again." << endl;
			cin.clear();
			value = -1;
		} else if (!valueWithin(value, min_value, max_value)) {
			cout << "Invalid input range (";
			cout << min_value << "-" << max_value;
			cout << "), please try again. " << endl;
			cin.clear();
			value = -1;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return value;
}



Player getPlayerInformation(Agent* myAgents) {
	return Player(getStringFromUser("Name"),
								getValueFromUser("Salary"),
								getAgentFromUser(myAgents));
}

void computePaymentAndDeductions(Player *players)
{
	for (int index = 0; index < PLAYER_COUNT; ++index) {
		players[index].calculateNetPayment();
	}
}

void generatePayStubs(Player *players, Agent *agents)
{
	computePaymentAndDeductions(players);
	generatePlayerPayStubs(players);
	generateAgentPayStubs(agents);
}

void generatePlayerPayStubs(Player *players) {
	cout << "==== Player Paystubs ====" << endl;
	for (int index = 0; index < PLAYER_COUNT; ++index) {
		players[index].generatePayStub();
	}
	cout << "=========================" << endl;
}

void generateAgentPayStubs(Agent *agents) {
	cout << "==== Agent Paystubs =====" << endl;
	for (int index = 0; index < AGENT_COUNT; ++index) {
		agents[index].generatePayStub();
	}
	cout << "=========================" << endl;
}

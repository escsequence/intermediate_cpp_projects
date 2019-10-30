/**
* NBATeam.cpp
* Written by:			James Johnston
* Written for: 		CS222 Project 2 (Runner app)
* Created on:			10/29/19
*/
#include "Functions.h"

/**
* Program for managing a NBA team
* @return int,	Program termination status.
*/
int main()
{
	//Create profiles for all agents
	Agent* myAgents = generateAgents();

	//Create profiles for players - and associate agent with the player
	Player* myPlayers = generatePlayers(myAgents);

	// Menu is open by default
	bool menuIsOpen = true;

	// Loop while menu is open
	while(menuIsOpen) {

		//Display a menu
		displayMenu();

		// Get the input, and decide what to do
		switch(getMenuInputChoice()) {

			//Choice 1: switch agent and then redisplay the menu
			case 1:

				// Update the agent for a player
				updateAgentForPlayer(myPlayers, myAgents);

				break;

			//Choice 2: change salary for a player, then redisplay the menu
			case 2:

				//Change salary for player
				updatePlayerSalary(myPlayers);

				break;
			//Choice 3: generate paystub for all players and agents, and then quit
			case 3:

				// Generate paystubs
				generatePayStubs(myPlayers, myAgents);

				// Close menu
				menuIsOpen = false;

				break;
			default:

				// Message to display for incorrect input
				displayInvalidInput();

		};
	}

	// Program terminated.
	return 0;
}

/**
 * Generate an Agent array out of thin air
 *
 * @param  none
 * @return Agent*,	Returns the Agent array
 */
Agent* generateAgents() {

	// Display what were doing, some nice formatting.
	cout << "===== Creating Agents =====" << endl;

	// Create a new Agent array based on a constant size
	Agent* myAgents = new Agent[AGENT_COUNT];

	// Loop through, and add the objects in the array
	for (int index = 0; index < AGENT_COUNT; ++index) {

		// Display the Agent number
		cout << "[ Agent #" << (index+1) << " ]: " << endl;

		// Get information for the agent
		myAgents[index] = getAgentInformation();

	}

	// Formatting.
	cout << "===========================" << endl;

	// Return the array.
	return myAgents;
}

/**
 * Generate a Player array out of thin air
 *
 * @param  none
 * @return Player*,	Returns the Player array
 */
Player* generatePlayers(Agent* myAgents) {

	// Display what were doing, some nice formatting.
	cout << "==== Creating Players =====" << endl;

	// Create a new Player array based on a constant size
	Player* myPlayers = new Player[PLAYER_COUNT];

	// Loop through, and add the objects in the array
	for (int index = 0; index < PLAYER_COUNT; ++index) {

		// Display the Player number
		cout << "[ Player #" << (index+1) << " ]: " << endl;

		// Get information for the Player
		myPlayers[index] = getPlayerInformation(myAgents);

	}

	// Formatting.
	cout << "===========================" << endl;

	// Return the array.
	return myPlayers;
}

/**
 * Create a Player object based on information from the user.
 *
 * @param 	Agent*,		The current Agent array to pick one.
 * @return	Player,		The Player based on Information from ther user.
 */
Player getPlayerInformation(Agent* myAgents) {
	return Player(getStringFromUser("Name"),
								getValueFromUser("Salary"),
								getAgentFromUser(myAgents));

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

/**
 * Updates the Agent for a specific Player
 *
 * @param		Player*,	The Players array
 * @param		Agent*,		The Agents array
 * @return	none
 */
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

/**
 * Updates the salary for a specific Player
 *
 * @param		Player*,	The Players array
 * @return	none
 */
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

/**
* Get a selection for the menu from the user.
*
* @param	none
* @return int,	Value of the menu to pick
*/
int getMenuInputChoice() {

	// Set default choice to -1
	int choice = INVALID_CHOICE_SELECTION;

	// While this choice is invalid
	while(choice == INVALID_CHOICE_SELECTION) {

		// Ask user to enter a command
		cout << "Enter a command: ";

		// Set var to the entered command
		cin >> choice;

		// If the value is invalid
		if (cin.fail() || choice == -1) {

			// Alert the user
			displayInvalidInput();

			// Clear the input
			cin.clear();

			// Set choice back to invalid
			choice = INVALID_CHOICE_SELECTION;

		}

		// Ignore enter
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Return a valid choice.
	return choice;
}

/**
* Search through the Players array to find a specific Player by name
*
* @param	string,		Name of the Player
* @param	Player*,	Array of the Players to search through
* @return int,			Index location of the specific Player
*/
int findPlayerByName(string name, Player *players) {

	// Set default choice to -1
	int returnIndex = INVALID_CHOICE_SELECTION;

	// Loop through the players
	for (int index = 0; index < PLAYER_COUNT; ++index) {

		// If player has a name that equals the argument
		if (players[index].nameEquals(name)) {
			returnIndex = (returnIndex == INVALID_CHOICE_SELECTION ? index : -2);
		}
	}

	// Return the index
	return returnIndex;
}

/**
* Search through the Agents array to find a specific Agent by name
*
* @param	string,		Name of the Agent
* @param	Agent*,	 	Array of the Agents to search through
* @return int,			Index location of the specific Agent
*/
int findAgentByName(string name, Agent *agents) {

	// Set default choice to -1
	int returnIndex = INVALID_CHOICE_SELECTION;

	// Loop through the agents
	for (int index = 0; index < AGENT_COUNT; ++index) {

		// If agent has a name that equals the argument
		if (agents[index].nameEquals(name))  {
			returnIndex = (returnIndex == INVALID_CHOICE_SELECTION ? index : -2);
		}
	}

	// Return the index
	return returnIndex;
}

/**
* Function is for obtaining a valid Player, calls findPlayerByName
* and asks the user to enter the name to search.
*
* @param	Player*,	 	Array of the Players to search through
* @return int,				Index location of the specific Agent
*/
int getPlayerChoice(Player *players) {

	// Set default choice to -1
	int choice = INVALID_CHOICE_SELECTION;

	// Name variable
	string name;

	// While the choice is invalid
	while(choice == INVALID_CHOICE_SELECTION) {
		// Ask user to enter a player name
		cout << "Select a Player (by name): ";

		// Get line from user and assign it to the name variable
		getline(cin, name);

		// Get choice
		choice = findPlayerByName(name, players);

		// If the input was invalid then re-loop
		if (cin.fail() || choice < 0) {

			// Alert the user
			cout << "Invalid player, please try again." << endl;

			// Clear the input
			cin.clear();

			// Set choice to invalid
			choice = INVALID_CHOICE_SELECTION;
		}
	}

	// Return a valid index of the player
	return choice;
}

/**
* Function is for obtaining a valid Agent, calls findAgentByName
* and asks the user to enter the name to search.
*
* @param	Agent*,	 		Array of the Agents to search through
* @return int,				Index location of the specific Agent
*/
int getAgentChoice(Agent *agents) {
	// Set default choice to -1
	int choice = INVALID_CHOICE_SELECTION;

	// Name variable
	string name;

	// While choice is invalid
	while(choice == INVALID_CHOICE_SELECTION) {

		// Display that we want to get the agent name to search for
		cout << "Select an Agent (by name): ";

		// Set name variable to the input line
		getline(cin, name);

		// Get the choice index from the user
		choice = findAgentByName(name, agents);

		// While choice is invalid, re-loop
		if (cin.fail() || choice < 0) {

			// Alert user the choice was invalid
			cout << "Invalid agent, please try again." << endl;

			// Clear the input
			cin.clear();

			// Set choice to default invalid
			choice = INVALID_CHOICE_SELECTION;
		}
	}

	// Return a valid index choice
	return choice;
}

/**
 * Create an Agent object based on information from the user.
 *
 * @param 	none
 * @return	Agent,		The Agent based on Information from ther user.
 */
Agent getAgentInformation() {
	// Returns a new Agent object
	return Agent(getStringFromUser("Name"), getValueFromUser("Stipend Ratio"));
}

/**
 * Returns a string based on an input from the user.
 *
 * @param 	string,		Value to print out before getting input
 * @return	string,		The string the user entered.
 */
string getStringFromUser(string print) {
	cout << print << ": ";
	string value;
	getline(cin, value);
	return value;
}

/**
 * Displays all the Agents in an Array of Agents
 *
 * @param 	Agent*,		Array of agents to loop
 * @return	none
 */
void displayAgents(Agent *agents) {
	cout << "=== Agents ===" << endl;
	for (int index = 0; index < AGENT_COUNT; ++index) {
		cout << "Agent #" << (index+1) << " | ";
		agents[index].printBasic();
		cout << endl;
	}
	cout << "==============" << endl;
}

/**
 * Displays all the Players in an Array of Players
 *
 * @param 	Player*,		Array of players to loop
 * @return	none
 */
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

/**
 * Select an Agent object based on information from the user.
 *
 * @param 	Agent*,		The current Agent array to display first.
 * @return	Agent*,   The agent the user selected.
 */
Agent* getAgentFromUser(Agent *myAgents) {
	displayAgents(myAgents);
	return &myAgents[getAgentChoice(myAgents)];
}

/**
 * Returns a flag if the "value" arg is within min and max
 *
 * @param int,		Value to check under the conditions
 * @param int,		Minimum value "value" can be (value >= min)
 * @param int,		Maximum value "value" can be (value <= max)
 * @return bool,	Flag if value is within bounds.
 */
bool valueWithin(double value, double min, double max) {
	return (value >= min && value <= max);
}

/**
 * Prints out an invalid message
 *
 * @param none
 * @return none
 */
void displayInvalidInput() {
	cout << "Invalid input, please try again." << endl;
}

/**
 * Returns a value based on an input from the user.
 * If the value param is "Stipend Ratio" then the number is based on
 * MIN_STIPEND_RATIO and MAX_STIPEND_RATIO, otherwise its the max/min double
 *
 * @param 	string,		Value to print out before getting input
 * @return	double,		The value from the user.
 */
double getValueFromUser(string message) {

	// Set value to -1 by default
	double value = INVALID_CHOICE_SELECTION;

	// By default set the min value to the double minimum
	double min_value = std::numeric_limits<double>::min();

	// By default set the maximum value to the double maximum
	double max_value = std::numeric_limits<double>::max();

	// If the message input is the stipendRatio, then set the limit to that.
	if (message == "Stipend Ratio") {
		min_value = MIN_STIPEND_RATIO;
		max_value = MAX_STIPEND_RATIO;
	}

	// While the value is invalid
	while(value <= INVALID_CHOICE_SELECTION) {
		// Prompt the user for info
		cout << message << ": ";

		// Get the value
		cin >> value;

		// If the user enters something weird, prompt them
		if (cin.fail() || value <= INVALID_CHOICE_SELECTION) {

			// Display it was invalid.
			displayInvalidInput();

			// CLear the input
			cin.clear();

			// Set the value back to invalid.
			value = INVALID_CHOICE_SELECTION;

		} else if (!valueWithin(value, min_value, max_value)) { //check within rng
			cout << "Invalid input range (";
			cout << min_value << "-" << max_value;
			cout << "), please try again. " << endl;

			// Clear the input
			cin.clear();

			// Set the value back to invalid.
			value = INVALID_CHOICE_SELECTION;
		}

		// Ignore a line break
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Return the value from the user.
	return value;
}

/**
 * Computes the payment and deductions for the Agents/Players
 *
 * @param 	Player*,	Array of Players
 * @return	none
 */
void computePaymentAndDeductions(Player *players)
{
	// Loop through all the players
	for (int index = 0; index < PLAYER_COUNT; ++index) {

		// Trigger the calculate net payment function
		players[index].calculateNetPayment();

	}
}

/**
 * Generate the PayStubs for Agents and Players
 *
 * @param 	Player*,	Array of Players
 * @param 	Agent*,		Array of Agents
 * @return	none
 */
void generatePayStubs(Player *players, Agent *agents)
{
	// Compute the payment and deductions for the players/agents
	computePaymentAndDeductions(players);

	// Generate the player paystubs.
	generatePlayerPayStubs(players);

	// Generate the Agent paystubs
	generateAgentPayStubs(agents);
}

/**
 * Generate the PayStubs for Players
 *
 * @param 	Player*,	Array of Players
 * @return	none
 */
void generatePlayerPayStubs(Player *players) {
	cout << "==== Player Paystubs ====" << endl;
	for (int index = 0; index < PLAYER_COUNT; ++index) {
		players[index].generatePayStub();
	}
	cout << "=========================" << endl;
}

/**
 * Generate the PayStubs for Agents
 *
 * @param 	Agent*,	Array of Agents
 * @return	none
 */
void generateAgentPayStubs(Agent *agents) {
	cout << "==== Agent Paystubs =====" << endl;
	for (int index = 0; index < AGENT_COUNT; ++index) {
		agents[index].generatePayStub();
	}
	cout << "=========================" << endl;
}

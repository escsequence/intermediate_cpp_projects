#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Player.h"
#include <limits>

using namespace std;

/**
 * Computes the payment and deductions for the Agents/Players
 *
 * @param 	Player*,	Array of Players
 * @return	none
 */
void computePaymentAndDeductions(Player*);

/**
 * Generate the PayStubs for Agents and Players
 *
 * @param 	Player*,	Array of Players
 * @param 	Agent*,		Array of Agents
 * @return	none
 */
void generatePayStubs(Player*, Agent*);

/**
 * Generate the PayStubs for Players
 *
 * @param 	Player*,	Array of Players
 * @return	none
 */
void generatePlayerPayStubs(Player*);

/**
 * Generate the PayStubs for Agents
 *
 * @param 	Agent*,	Array of Agents
 * @return	none
 */
void generateAgentPayStubs(Agent*);

/**
 * Displays all the Players in an Array of Players
 *
 * @param 	Player*,		Array of players to loop
 * @return	none
 */
void displayPlayers(Player*);

/**
 * Displays all the Agents in an Array of Agents
 *
 * @param 	Agent*,		Array of agents to loop
 * @return	none
 */
void displayAgents(Agent*);

/**
* Get a selection for the menu from the user.
*
* @param	none
* @return int,	Value of the menu to pick
*/
int getMenuInputChoice();

/**
* Function is for obtaining a valid Player, calls findPlayerByName
* and asks the user to enter the name to search.
*
* @param	Player*,	 	Array of the Players to search through
* @return int,				Index location of the specific Agent
*/
int getPlayerChoice(Player*);

/**
* Function is for obtaining a valid Agent, calls findAgentByName
* and asks the user to enter the name to search.
*
* @param	Agent*,	 		Array of the Agents to search through
* @return int,				Index location of the specific Agent
*/
int getAgentChoice(Agent*);

/**
* Search through the Players array to find a specific Player by name
*
* @param	string,		Name of the Player
* @param	Player*,	Array of the Players to search through
* @return int,			Index location of the specific Player
*/
int findPlayerByName(string, Player*);

/**
* Search through the Agents array to find a specific Agent by name
*
* @param	string,		Name of the Agent
* @param	Agent*,	  Array of the Agents to search through
* @return int,			Index location of the specific Agent
*/
int findAgentByName(string, Agent*);

/**
 * Generate an Agent array out of thin air
 *
 * @param  none
 * @return Agent*,	Returns the Agent array
 */
Agent* generateAgents();

/**
 * Create an Agent object based on information from the user.
 *
 * @param 	none
 * @return	Agent,		The Agent based on Information from ther user.
 */
Agent getAgentInformation();

/**
 * Generate a Player array out of thin air
 *
 * @param  none
 * @return Player*,	Returns the Player array
 */
Player* generatePlayers(Agent*);

/**
 * Create a Player object based on information from the user.
 *
 * @param 	Agent*,		The current Agent array to pick one.
 * @return	Player,		The Player based on Information from ther user.
 */
Player getPlayerInformation(Agent*);

/**
 * Select an Agent object based on information from the user.
 *
 * @param 	Agent*,		The current Agent array to display first.
 * @return	Agent*,   The agent the user selected.
 */
Agent* getAgentFromUser(Agent *myAgents)

/**
 * Returns a string based on an input from the user.
 *
 * @param 	string,		Value to print out before getting input
 * @return	string,		The string the user entered.
 */
string getStringFromUser(string);

/**
 * Returns a value based on an input from the user.
 * If the value param is "Stipend Ratio" then the number is based on
 * MIN_STIPEND_RATIO and MAX_STIPEND_RATIO, otherwise its the max/min double
 *
 * @param 	string,		Value to print out before getting input
 * @return	double,		The value from the user.
 */
double getValueFromUser(string);

/**
 * Updates the Agent for a specific Player
 *
 * @param		Player*,	The Players array
 * @param		Agent*,		The Agents array
 * @return	none
 */
void updateAgentForPlayer(Player*, Agent*);

/**
 * Updates the salary for a specific Player
 *
 * @param		Player*,	The Players array
 * @return	none
 */
void updatePlayerSalary(Player*);

/**
* Display a menu with the selections for the main menu.
*
* @param	none
* @return none
*/
void displayMenu();

/**
 * Returns a flag if the "value" arg is within min and max
 *
 * @param int,		Value to check under the conditions
 * @param int,		Minimum value "value" can be (value >= min)
 * @param int,		Maximum value "value" can be (value <= max)
 * @return bool,	Flag if value is within bounds.
 */
bool valueWithin(double, double, double);

#endif

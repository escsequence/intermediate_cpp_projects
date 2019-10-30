/**
* Player.h
* Written by:		James Johnston
* Written for:	CS222 Project 2
* Created on:		10/29/19
*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Agent.h"


/**
* Player class definition
*/

class Player
{
//Data members
private:
	std::string	name;		// name of player
	double		salary;		//Salary of the player in million $
	Agent		*myAgent;	//Pointer to the agent of this player, this makes sure
							//multiple players can poin to a same agent
//Member functions
public:

	//Constructor, setters and getters
	/**
	 * Default Constructor
	 *
	 * @param 	none
	 * @return	Player obj
	 */
	Player(){}

	/**
	 * Overloading Constructor
	 *
	 * @param 	string,		Name
	 * @param		double,		Salary
	 * @param		Agent*,		Agent to link up withn
	 * @return	Player obj
	 */
	Player(std::string, double, Agent*);

	/**
	* Setter for Agent, pass the pointer of the agent so that different player
	* can operate (e.g add income) on the same agent
	*
	* @param:	pointer for the agent
	* @return:	none
	*/
	void setAgent(Agent *);

	/**
	* Getter for Agent, return the pointer of the agent so that operation
	* on the agent is really this player's agent
	*
	* @param:	none
	* @return:	pointer for the agent of this plaer
	*/
	Agent *getAgent();

	/**
	* Calculate payment to the agent by multiplying player's salary with
	* the agent's stipend ratio
	*
	* @param:	none
	* @return	payment to the agent
	*/
	double calculateAgentPayment();

	/**
	* Calculate the net payment to the player, which is salary minus agent stipend
	*
	* @param	none
	* @return	net payment of the player
	*/
	void calculateNetPayment();

	/**
	* Generate pay stub for the player, including name, salary, agent name, and net
		payment information

	* @param	none
	* @return	none
	*/
	void generatePayStub();

	/**
	 * Returns a flag if the name equals a string value.
	 *
	 * @param string,		Value to check if the name equals
	 * @return bool,		Flag if the value equals the string
	 */
	bool nameEquals(std::string);

	/**
	 * Prints out basic information about the Player.
	 *
	 * @param 	none
	 * @return 	none
	 */
	void printBasic();

	/**
	 * Prints out a full length information about the Player's Agent.
	 *
	 * @param 	none
	 * @return 	none
	 */
	void printAgent();

	/**
	 * Set the salary
	 * @param double, New salary
	 */
	void setSalary(double);

};

#endif

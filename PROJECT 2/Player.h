#ifndef PLAYER_H
#define PLAYER_H
#include "Agent.h"

/*
* Player.h
* Written by:
* Written for:	COMPSCI 222 Project 2
* Created on:
*/

/**
* Player class definition
*/

class Player
{
//Data members
private:
	std::string	name;
	double		salary;		//Salary of the player in million $
	Agent		*myAgent;	//Pointer to the agent of this player, this makes sure
							//multiple players can poin to a same agent
//Member functions
public:

	Player() {

	}

	Player(std::string name, double salary, Agent* myAgent) {
		this->name = name;
		this->salary = salary;
		this->myAgent = myAgent;
	}
	//Constructor, setters and getters
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
	 * Prints out an invalid message
	 *
	 * @param none
	 * @return none
	 */
	void displayInvalidInput();

	bool nameEquals(std::string name) { return (name == this->name); }

	void printBasic() {
		printf("Name: %s | Salary: %.2f", name.c_str(), salary);
	}

	void printAgent() {
		std::cout << "[ Current Agent: ";
		myAgent->printBasic();
		std::cout << " ]" << std::endl;
	}

	void setSalary(double salary) {
		this->salary = salary;
	}

};

#endif

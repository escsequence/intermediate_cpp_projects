#ifndef AGENT_H
#define AGENT_H
#include <iostream>
/**
* Agent.h
* Written by:
* Written for:		CS222 Project 2
* Created on:
*/
/**
* Agent class definition
*/

class Agent
{
//Data members
private:
	std::string	name;					//Full name of the agent
	double			income;				//Total income
	double			stipendRatio;	//Stipend percentage on player's salary
//Member functions
	//Constructor and getters/setters
public:

	Agent() {

	}

	Agent(std::string name, double stipendRatio) {
		this->name = name;
		this->stipendRatio = stipendRatio;
	}

	void printBasic() {
		printf("Name: %s | Stipend Ratio: %.2f", name.c_str(), stipendRatio);
	}

	void printFull() {
		printf(	"Name: %s | Stipend Ratio: %.2f | Income: $%.2f",
						name.c_str(),
						stipendRatio,
						income);
	}
	/**
	* Add payment to an agent
	*
	* @param	payment to be added to the agent's total income
	* @return	none
	*/
	void	addPayment(double);

	/**
	* Generate pay stub for an agent
	*
	* @param	none
	* @return	none
	*/
	void	generatePayStub();

	bool nameEquals(std::string name) { return (name == this->name); }
};
#endif

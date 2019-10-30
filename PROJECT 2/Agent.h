/**
* Agent.h
* Written by:			James Johnston
* Written for:		CS222 Project 2
* Created on:			10/29/19
*/

#ifndef AGENT_H
#define AGENT_H
#include <iostream>
#include "Constants.h"


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

	/**
	 * Default Constructor
	 *
	 * @param 	none
	 * @return	Agent obj
	 */
	Agent(){}

	/**
	 * Overloading Constructor
	 *
	 * @param 	string,		Name
	 * @param		double,		Stipend Ratio
	 * @return	Agent obj
	 */
	Agent(std::string, double);

	/**
	 * Prints out basic information about the Agent.
	 *
	 * @param 	none
	 * @return 	none
	 */
	void printBasic();

	/**
	 * Prints out a full length information about the Agent.
	 *
	 * @param 	none
	 * @return 	none
	 */
	void printFull();

	/**
	 * Returns the Stipend value
	 *
	 * @return double,	Stipend ratio value
	 */
	double getStipendRatio();

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

	/**
	 * Returns a flag if the name equals a string value.
	 *
	 * @param string,		Value to check if the name equals
	 * @return bool,		Flag if the value equals the string
	 */
	bool nameEquals(std::string);

};
#endif

/**
* Agent.cpp
* Written by:			James Johnston
* Written for: 		CS222 Project 2 (Agent.h)
* Created on:			10/29/19
*/
#include "Agent.h"

/**
 * Overloading Constructor
 *
 * @param 	string,		Name
 * @param		double,		Stipend Ratio
 * @return	Agent obj
 */
Agent::Agent(std::string name, double stipendRatio) {
  this->name = name;
  this->stipendRatio = stipendRatio;
}

/**
* Add payment to an agent
*
* @param	payment to be added to the agent's total income
* @return	none
*/
void Agent::addPayment(double payment) {
  income += payment;
}

/**
* Generate pay stub for an agent
*
* @param	none
* @return	none
*/
void Agent::generatePayStub() {
  printFull();
}

/**
 * Returns the Stipend value
 *
 * @return double,	Stipend ratio value
 */
double Agent::getStipendRatio() {
  return this->stipendRatio;
}

/**
 * Prints out basic information about the Agent.
 *
 * @param 	none
 * @return 	none
 */
void Agent::printBasic() {
  printf("Name: %s | Stipend Ratio: %.2f", name.c_str(), stipendRatio);
}

/**
 * Prints out a full length information about the Agent.
 *
 * @param 	none
 * @return 	none
 */
void Agent::printFull() {
  printf(	"Name: %s | Stipend Ratio: %.2f | Income: $%.2f\n",
          name.c_str(),
          stipendRatio,
          income);
}

/**
 * Returns a flag if the name equals a string value.
 *
 * @param string,		Value to check if the name equals
 * @return bool,		Flag if the value equals the string
 */
bool Agent::nameEquals(std::string name) {
  return (name == this->name);
}

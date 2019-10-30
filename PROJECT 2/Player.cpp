/**
* Player.cpp
* Written by:			James Johnston
* Written for: 		CS222 Project 2 (Player.h)
* Created on:			10/29/19
*/
#include "Player.h"

/**
 * Overloading Constructor
 *
 * @param 	string,		Name
 * @param		double,		Salary
 * @param		Agent*,		Agent to link up withn
 * @return	Player obj
 */
Player::Player(std::string name, double salary, Agent* myAgent) {
  this->name = name;
  this->salary = salary;
  this->myAgent = myAgent;
}

/**
* Setter for Agent, pass the pointer of the agent so that different player
* can operate (e.g add income) on the same agent
*
* @param:	pointer for the agent
* @return:	none
*/
void Player::setAgent(Agent *agent) {
  this->myAgent = agent;
}

/**
* Getter for Agent, return the pointer of the agent so that operation
* on the agent is really this player's agent
*
* @param:	none
* @return:	pointer for the agent of this plaer
*/
Agent* Player::getAgent() {
  return myAgent;
}

/**
* Calculate the net payment to the player, which is salary minus agent stipend
*
* @param	none
* @return	net payment of the player
*/
void Player::calculateNetPayment() {
  double agentPayment = calculateAgentPayment();
  myAgent->addPayment(agentPayment);
  salary -= agentPayment;
}

/**
* Calculate payment to the agent by multiplying player's salary with
* the agent's stipend ratio
*
* @param:	none
* @return	payment to the agent
*/
double Player::calculateAgentPayment() {
  return (salary * (myAgent->getStipendRatio() / 100));

}

/**
* Generate pay stub for the player, including name, salary, agent name, and net
  payment information

* @param	none
* @return	none
*/
void Player::generatePayStub() {
  printBasic();
  std::cout << std::endl;
}

/**
 * Returns a flag if the name equals a string value.
 *
 * @param string,		Value to check if the name equals
 * @return bool,		Flag if the value equals the string
 */
bool Player::nameEquals(std::string name) {
  return (name == this->name);
}

/**
 * Prints out basic information about the Player.
 *
 * @param 	none
 * @return 	none
 */
void Player::printBasic() {
  printf("Name: %s | Salary: %.2f", name.c_str(), salary);
}

/**
 * Prints out a full length information about the Player's Agent.
 *
 * @param 	none
 * @return 	none
 */
void Player::printAgent() {
  std::cout << "[ Current Agent: ";
  myAgent->printBasic();
  std::cout << " ]" << std::endl;
}

/**
 * Set the salary
 * @param double, New salary
 */
void Player::setSalary(double salary) {
  this->salary = salary;
}

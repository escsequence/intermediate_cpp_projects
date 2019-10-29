#include "Player.h"

void Player::setAgent(Agent *agent) {
  this->myAgent = agent;
}

Agent* Player::getAgent() {
  return myAgent;
}

void Player::calculateNetPayment() {
  double agentPayment = calculateAgentPayment();
  myAgent->addPayment(agentPayment);
  salary -= agentPayment;
}

double Player::calculateAgentPayment() {
  return (salary * (myAgent->getStipendRatio() / 100));

}

void Player::generatePayStub() {
  printBasic();
  std::cout << std::endl;
}

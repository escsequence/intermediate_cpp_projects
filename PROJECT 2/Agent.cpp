#include "Agent.h"

void Agent::addPayment(double payment) {
  income += payment;
}

void Agent::generatePayStub() {
  printFull();
}
double Agent::getStipendRatio() {
  return this->stipendRatio;
}

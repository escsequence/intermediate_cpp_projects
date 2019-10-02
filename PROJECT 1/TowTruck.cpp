#include "TowTruck.h"

TowTruck::TowTruck() {

}

TowTruck::TowTruck(std::string name, Point homePoint) {
  this->name = name;
  this->homePoint = homePoint;
  revenue = 0;
  milesDriven = 0;
}

void TowTruck::setHomePoint(Point point) {
  homePoint = point;
}

Point TowTruck::getHomePoint() {
  return homePoint;
}

void TowTruck::setName(std::string name) {
  this->name = name;
}

std::string TowTruck::getName() {
  return name;
}

double TowTruck::getRevenue() {
  return revenue;
}

double TowTruck::getMilesDriven() {
  return milesDriven;
}

void TowTruck::driveToPoint(Point point) {
  if (point.getX() <= MAX_DRIVING_BOUNDS_X &&
      point.getY() <= MAX_DRIVING_BOUNDS_Y) {

    milesDriven += homePoint.distanceTo(point);
    revenue += homePoint.distanceTo(point) * payRatePerMile;
  }
}

void TowTruck::printSummary() {
  std::cout << "Truck driver (" << name << ") has driven " << milesDriven << " miles and has accumulated $" << revenue << " in revenue." << std::endl;
}

/**
* Member function definitions for class TowTruck
*
* @Author:      James Johnston
* @Version:     1.0
* @Assignment:  Project 1
*************************/
#include "TowTruck.h"

/**
 * The standard TowTruck constructor
 */
TowTruck::TowTruck() {

}

/**
 * The TowTruck constructor. Takes in a name and a homePoint
 * @param name, the name
 * @param homePoint, the home point
 */
TowTruck::TowTruck(std::string name, Point homePoint) {
  this->name = name;
  this->homePoint = homePoint;
  revenue = 0;
  milesDriven = 0;
}

/**
 * Sets the home point
 * @param home point
 */
void TowTruck::setHomePoint(Point point) {
  homePoint = point;
}

/**
 * Returns the Home Point value
 * @return the Home Point value
 */
Point TowTruck::getHomePoint() {
  return homePoint;
}

/**
 * Sets the name
 * @param name, the name value
 */
void TowTruck::setName(std::string name) {
  this->name = name;
}

/**
 * Returns the name value
 * @return the name
 */
std::string TowTruck::getName() {
  return name;
}

/**
 * Returns the revenue
 * @return the name
 */
double TowTruck::getRevenue() {
  return revenue;
}

/**
 * Returns the miles driven
 * @return the miles driven
 */
double TowTruck::getMilesDriven() {
  return milesDriven;
}

/**
 * Calculates the wages collected
 * @param Point to drive to
 */
void TowTruck::driveToPoint(Point point) {
  if (point.getX() <= MAX_DRIVING_BOUNDS_X &&
      point.getY() <= MAX_DRIVING_BOUNDS_Y &&
      point.getX() >= MIN_DRIVING_BOUNDS_X &&
      point.getY() >= MIN_DRIVING_BOUNDS_Y) {

    milesDriven += homePoint.distanceTo(point);
    revenue += homePoint.distanceTo(point) * PAY_RATE_PER_MILE;
  }
}

/**
 * Prints out the summary of the tow truck
 */
void TowTruck::printSummary() {
  std::cout << "Truck driver (" << name << ") has driven " << milesDriven << " miles and has accumulated $" << revenue << " in revenue." << std::endl;
}

#ifndef TOW_TRUCK_HOME_H
#define TOW_TRUCK_HOME_H
#include "Point.h"
#include "ObjectArrayFunctions.h"
#include <iostream>

class TowTruck {
private:
  std::string name;
  Point homePoint;
  double revenue;
  double milesDriven;
public:
  /**
   * The standard TowTruck constructor
   */
  TowTruck();
  /**
   * The TowTruck constructor. Takes in a name and a homePoint
   * @param name, the name
   * @param homePoint, the home point
   */
  TowTruck(std::string name, Point homePoint);

  /**
   * Returns the name value
   * @return the name
   */
  std::string getName();
  /**

   * Sets the name
   * @param name, the name value
   */
  void setName(std::string name);

  /**
   * Returns the Home Point value
   * @return the Home Point value
   */
  Point getHomePoint();

  /**
   * Sets the home point
   * @param home point
   */
  void setHomePoint(Point point);
  /**
   * Returns the revenue
   * @return the name
   */
  double getRevenue();
  /**
   * Returns the miles driven
   * @return the miles driven
   */
  double getMilesDriven();

  /**
   * Calculates the wages collected
   * @param Point to drive to
   */
  void driveToPoint(Point point);

  /**
   * Prints out the summary of the tow truck
   */
  void printSummary();

};

#endif

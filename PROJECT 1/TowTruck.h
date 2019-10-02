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
  TowTruck();
  TowTruck(std::string name, Point homePoint);

  std::string getName();
  void setName(std::string name);

  Point getHomePoint();
  void setHomePoint(Point point);

  double getRevenue();
  double getMilesDriven();

  void driveToPoint(Point point);

  void printSummary();

};

#endif

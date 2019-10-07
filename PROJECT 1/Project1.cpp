/*
* Project1.cpp
* Written by:	  James Johnston
* Date:         10/4/19
* Version:		  1.0
*/

/**
* Test program for TowTruck, and Point class.
*
* @Author:      James Johnston
* @Version:     1.0
* @Assignment:	Project 1
*/
#include <iostream>
#include "TowTruck.h"
using namespace std;

/**
 * Returns a point a user enters
 * @return Returns the Point the user has entered
 */
Point getPointFromUser() {
  double x, y;

  cout << "Point X: ";
  cin >> x;

  cout << "Point Y: ";
  cin >> y;

  return Point(x, y);
}

/**
 * Prints out the standard menu
 */
void printMenu() {
  cout << "Add another? (y/n): ";
}

/**
 * This function will add a point to the closest truck
 * @param trucks, The truck array
 * @param point, The point we are checking
 */
void addPointToClosestTowTruck(TowTruck* trucks, Point point) {

  TowTruck* closestTruck = NULL;
  double closestDistance = MAX_DRIVING_BOUNDS_X; // Distance cannot exceed

  for (int index = 0; index < TRUCK_DRIVER_COUNT; ++index) {
    if (trucks[index].getHomePoint().distanceTo(point) < closestDistance) {
      closestDistance = trucks[index].getHomePoint().distanceTo(point);
      closestTruck = &trucks[index];
    }
  }
  if (closestTruck != NULL)
    closestTruck->driveToPoint(point);
}


/**
 * Prints the summary of a truck array
 * @param trucks, The truck array to print
 */
void printSummaryOfAllTrucks(TowTruck *trucks) {
  cout << endl << "===================== Summary =====================" << endl;
  for (int index = 0; index < TRUCK_DRIVER_COUNT; ++index) {
    trucks[index].printSummary();
  }
  cout << "===================================================" << endl;

}

/**
 * Main method
 * @return the value of success
 */
int main() {
  TowTruck towTrucks[TRUCK_DRIVER_COUNT];

  towTrucks[0] = TowTruck("William Rufus", Point(3.5, 3.5));
  towTrucks[1] = TowTruck("Robert Amtrak", Point(3.5, 7));
  towTrucks[2] = TowTruck("Tim Roberts", Point(6, 4));
  towTrucks[3] = TowTruck("Colton Johnson", Point(7, 7));

  bool programActive = true;
  char option;
  Point userEnteredPoint = getPointFromUser();
  addPointToClosestTowTruck(towTrucks, userEnteredPoint);

  while(programActive) {


    printMenu();
    cin >> option;
    cin.clear();

    switch(option) {
      case 'y':
        userEnteredPoint = getPointFromUser();
        addPointToClosestTowTruck(towTrucks, userEnteredPoint);
        break;
      case 'n':
        programActive = false;
        break;
      default:
        cout << "Invalid input, try again" << endl;
    }
  }

  printSummaryOfAllTrucks(towTrucks);

  return 0;
}

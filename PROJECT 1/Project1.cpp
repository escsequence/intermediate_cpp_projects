#include <iostream>
#include "TowTruck.h"
using namespace std;


Point getPointFromUser() {
  double x, y;

  cout << "Point X: ";
  cin >> x;

  cout << "Point Y: ";
  cin >> y;

  return Point(x, y);
}

void printMenu() {
  cout << "Add another? (y/n): ";
}

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

void printSummaryOfAllTrucks(TowTruck *trucks) {
  cout << endl << "===================== Summary =====================" << endl;
  for (int index = 0; index < TRUCK_DRIVER_COUNT; ++index) {
    trucks[index].printSummary();
  }
  cout << "===================================================" << endl;

}


int main() {
  TowTruck towTrucks[TRUCK_DRIVER_COUNT];

  towTrucks[0] = TowTruck("William Rufus", Point(3.5, 3.5));
  towTrucks[1] = TowTruck("Robert Amtrak", Point(3.5, 7));
  towTrucks[2] = TowTruck("Tim Roberts", Point(6, 4));
  towTrucks[3] = TowTruck("Colton Johnson", Point(7, 7));

  bool programActive = true;

  while(programActive) {
    char option;
    Point userEnteredPoint = getPointFromUser();
    addPointToClosestTowTruck(towTrucks, userEnteredPoint);

    printMenu();
    cin >> option;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

  //Point user = getPointFromUser();
  //cout << p1.distanceTo(user) << endl;
  //towTruckOne.printSummary();


  return 0;
}

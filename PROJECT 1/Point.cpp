#include "Point.h"
#include <cmath>

Point::Point() {
  
}

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

double Point::getX() {
  return x;
}

void Point::setX(double x) {
  this->x = x;
}

double Point::getY() {
  return y;
}

void Point::setY(double y) {
  this->y = y;
}

Point Point::differenceOf(Point pointTwo) {
  return Point( pointTwo.getX() - getX(),
                pointTwo.getY() - getY());
}

double Point::distanceTo(Point pointTwo) {
  return abs(sqrt(pow(pointTwo.getX() - getX(), 2) +
                  pow(pointTwo.getY() - getY(), 2)));
}

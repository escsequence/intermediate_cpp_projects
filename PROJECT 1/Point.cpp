/**
* Member function definitions for class Point
*
* @Author:      James Johnston
* @Version:     1.0
* @Assignment:  Project 1
*************************/
#include "Point.h"
#include <cmath>

/**
 * The default Point constructor, takes nothing
 */
Point::Point() {

}

/**
 * The second Point constructor - initalizes x and y
 * @param x, the x value
 * @param y, the y value
 */
Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

/**
 * Returns the X value
 * @return the x value
 */
double Point::getX() {
  return x;
}

/**
 * Sets the X value
 * @param x, the x value
 */
void Point::setX(double x) {
  this->x = x;
}

/**
 * Returns the Y value
 * @return the Y value
 */
double Point::getY() {
  return y;
}
/**
 * Sets the Y value
 * @param Y, the x value
 */
void Point::setY(double y) {
  this->y = y;
}

/**
 * This function returns the distance between this point and another.
 * @param pointTwo, the second point to analyze
 * @return returns the value which this point is to another
 */
double Point::distanceTo(Point pointTwo) {
  return abs(sqrt(pow(pointTwo.getX() - getX(), 2) +
                  pow(pointTwo.getY() - getY(), 2)));
}

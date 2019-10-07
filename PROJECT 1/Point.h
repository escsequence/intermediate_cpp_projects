#ifndef POINT_H
#define POINT_H

/**
 * Class Point
 */
class Point {
  private:
    // X value
    double x;

    // Y value
    double y;

  public:
    /**
     * The default constructor, does not set the x or the y.
     */
    Point();
    /**
     * The second Point constructor - initalizes x and y
     * @param x, the x value
     * @param y, the y value
     */
    Point(double x, double y);

    /**
     * Returns the X value
     * @return the x value
     */
    double getX();

    /**
     * Sets the X value
     * @param x, the x value
     */
    void setX(double x);

    /**
     * Returns the Y value
     * @return the Y value
     */
    double getY();

    /**
     * Sets the Y value
     * @param Y, the x value
     */
    void setY(double y);

    /**
     * This function returns the distance between this point and another.
     * @param pointTwo, the second point to analyze
     * @return returns the value which this point is to another
     */
    double distanceTo(Point pointTwo);
};

#endif

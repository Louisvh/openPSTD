//
// Created by omar on 10-9-15.
//

#include "Geometry.h"

Point::Point(const int x, const int y, const int z = 0) {
    this.x = x;
    this.y = y;
    this.z = z;

}

friend Point::Point operator+(const Point a, const Point b) {
    return Point(a.x + b.x, a.y + b.y,a.z+b.z);
}

friend Point::Point operator-(const Point a, const Point b) {
    return Point(a.x - b.x, a.y - b.y,a.z-b.z);
}
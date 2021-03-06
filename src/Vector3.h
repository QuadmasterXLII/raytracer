/*
 * Vector3.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <string>

class Vector3 {
public:
	double x;
	double y;
	double z;
	Vector3(double x, double y, double z);
	Vector3();
	Vector3 add(Vector3 other);
	Vector3 sub(Vector3 other);
	Vector3 mul(double k);
	double dot(Vector3 other);
	Vector3 cross(Vector3 other);
	double length();
    Vector3 unit();
    std::string repr();

    static Vector3 randUnit(Vector3 center);
    static Vector3 randSphere();
};







#endif /* VECTOR3_H_ */

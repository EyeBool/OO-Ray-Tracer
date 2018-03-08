#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"
#include "VisibleObject.h"
#include <float.h>

class Ray {
	Vector3D tail;
	Vector3D head;

public:
	Ray(const Vector3D& tail, const Vector3D& head);

	Vector3D getDirection() const;

	double getDistanceToIntersection(const VisibleObject& visibleObject) const;
};

#endif RAY_H
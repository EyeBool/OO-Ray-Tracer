#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3D.h"

class Camera {
	Vector3D position;
	Vector3D orientation;
	Vector3D centerOfInterest;

public:
	Camera(const Vector3D& position, const Vector3D& orientation, const Vector3D& centerOfInterest);

	// getter methods
	Vector3D getPosition() const;
	Vector3D getOrientation() const;
	Vector3D getCenterOfInterest() const;

	Vector3D getDirection() const;
	Vector3D getViewingPlanRight() const;
	Vector3D getViewingPlanUp() const;
};

#endif CAMERA_H
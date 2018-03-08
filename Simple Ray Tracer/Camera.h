#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3D.h"

class Camera {
	Vector3D position;
	Vector3D orientation;
	Vector3D centerOfInterest;

public:
	// getter methods
	Vector3D getPosition();
	Vector3D getOrientation();
	Vector3D getCenterOfInterest();

	// 
	Vector3D getDirection();
	Vector3D getViewingPlanRight();
	Vector3D getViewingPlanUp();
};

#endif CAMERA_H
#include "Camera.h"

Vector3D Camera::getPosition() {
	return position;
}

Vector3D Camera::getOrientation() {
	return orientation;
}

Vector3D Camera::getCenterOfInterest() {
	return centerOfInterest;
}

Vector3D Camera::getDirection() {
	return (centerOfInterest - position).unitVector();
}

Vector3D Camera::getViewingPlanRight() {
	return (crossProduct(Camera::getDirection(), Camera::getOrientation())).unitVector();
}

Vector3D Camera::getViewingPlanUp() {
	return (crossProduct(Camera::getViewingPlanRight(), Camera::getDirection())).unitVector();
}
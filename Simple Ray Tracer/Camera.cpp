#include "Camera.h"

Camera::Camera(const Vector3D& position, const Vector3D& orientation, const Vector3D& centerOfInterest) 
	: position(position), orientation(orientation), centerOfInterest(centerOfInterest) {}

Vector3D Camera::getPosition() const {
	return position;
}

Vector3D Camera::getOrientation() const {
	return orientation;
}

Vector3D Camera::getCenterOfInterest() const {
	return centerOfInterest;
}

Vector3D Camera::getDirection() const {
	return (centerOfInterest - position).unitVector();
}

Vector3D Camera::getViewingPlanRight() const {
	return (crossProduct(Camera::getDirection(), Camera::getOrientation())).unitVector();
}

Vector3D Camera::getViewingPlanUp() const {
	return (crossProduct(Camera::getViewingPlanRight(), Camera::getDirection())).unitVector();
}
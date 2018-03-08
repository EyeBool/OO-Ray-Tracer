#include "VisibleObject.h"

Vector3D VisibleObject::getCenter() const {
	return center;
}

double VisibleObject::getRadius() const {
	return radius;
}

Material VisibleObject::getMaterial() const {
	return material;
}

Vector3D VisibleObject::getNormal(const Vector3D& position) const {
	return (position - center).unitVector();
}
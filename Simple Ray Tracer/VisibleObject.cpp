#include "VisibleObject.h"

VisibleObject::VisibleObject(const Vector3D& center, double radius, const Material& material)
	: center(center), radius(radius), material(material) {}

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
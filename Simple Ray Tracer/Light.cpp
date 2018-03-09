#include "Light.h"

Light::Light(const Vector3D& position) : position(position) {}

Vector3D Light::getPosition() const {
	return position;
}
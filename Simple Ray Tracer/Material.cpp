#include "Material.h"

double Material::getRed() const {
	return red;
}

double Material::getGreen() const {
return green;
}

double Material::getBlue() const {
	return blue;
}

Vector3D Material::getColor() const {
	return Vector3D(red, blue, green);
}

double Material::getSpecular() const {
	return specular;
}

double Material::getLambert() const {
	return lambert;
}

double Material::getAmbient() const {
	return ambient;
}

double Material::getRadius() const {
	return radius;
}

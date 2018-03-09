#include "Material.h"

// TODO: factor out the "empty" material that is needed for the object at infinity
Material::Material() {}

Material::Material(
	double red, double green, double blue,
	double specular, double lambert, double ambient, double radius
)
	: red(red), green(green), blue(blue),
	specular(specular), lambert(lambert), ambient(ambient), radius(radius) {}

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
	return Vector3D(red, green, blue);
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

#ifndef MATERIAL_H
#define MATERIAL_H

#include "Vector3D.h"

class Material {
	double red, green, blue;
	double specular, lambert, ambient, radius;
public:
	double getRed() const;
	double getGreen() const;
	double getBlue() const;
	Vector3D getColor() const;
	double getSpecular() const;
	double getLambert() const;
	double getAmbient() const;
	double getRadius() const;
};

#endif
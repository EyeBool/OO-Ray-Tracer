#ifndef LIGHT_H
#define LIGHT_H

#include "Vector3D.h"

class Light {
	Vector3D position;

public:
	Light(const Vector3D& position);

	Vector3D getPosition() const;
};

#endif LIGHT_H
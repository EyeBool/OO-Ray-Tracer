#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include "Vector3D.h"
#include "Material.h"

class VisibleObject {
	Vector3D center;
	double radius;
	Material material;

public:
	VisibleObject(const Vector3D& center, double radius, const Material& material);

	Vector3D getCenter() const;
	double getRadius() const;
	Material getMaterial() const;

	Vector3D getNormal(const Vector3D& position) const;
};

#endif
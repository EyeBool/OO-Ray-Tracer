#include "Ray.h"
#include <cmath>

inline double square(double x) {
	return x * x;
}

Ray::Ray(const Vector3D& tail, const Vector3D& head) : tail(tail), head(head) {}

Vector3D Ray::getDirection() const {
	return (head - tail).unitVector();
}

double Ray::getDistanceToIntersection(const VisibleObject& visibleObject) const {
	Vector3D rayDirection = getDirection();
	Vector3D relativePosition = tail - visibleObject.getCenter();
	double discriminant = 
		4.0 * (
			square(dotProduct(rayDirection, relativePosition))
			- relativePosition.lengthSquared()
			+ square(visibleObject.getRadius())
			);

	if (discriminant < 0)
		return DBL_MAX;
	else
		return -dotProduct(rayDirection, relativePosition) - 0.5 * std::sqrt(discriminant);

} 
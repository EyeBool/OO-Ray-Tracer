#include "Tracer.h"

std::pair<double, VisibleObject*> Tracer::trace(const Ray& ray) const {
	std::make_pair<double, VisibleObject*> nearestObjectInfo;
	nearestObjectInfo.first = DBL_MAX;
	nearestObjectInfo.second = NULL;

	for (VisibleObject visibleObject : scene.getVisibleObjects()) {
		double distance = ray.getDistanceToIntersection(visibleObject);

		if (distance < nearestObjectInfo.first) {
			nearestObjectInfo.first = distance;
			nearestObjectInfo.second = &visibleObject;
		}
	}

	return nearestObjectInfo;
}

bool Tracer::isRayBlocked(const Ray& ray, double tolerance = -0.01) {
	std::pair<double, VisibleObject*> nearestObjectInfo = trace(ray);
	return nearestObjectInfo.first > tolerance;
}
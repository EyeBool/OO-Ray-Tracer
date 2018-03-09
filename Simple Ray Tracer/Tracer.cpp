#include "Tracer.h"

Tracer::Tracer(const Scene& scene) : scene(scene) {}

// TODO: deal with the "object at infinity" better
std::pair<double, VisibleObject> Tracer::trace(const Ray& ray) const {
	std::pair<double, VisibleObject> nearestObjectInfo;
	nearestObjectInfo.first = DBL_MAX;
	nearestObjectInfo.second = VisibleObject();

	for (VisibleObject visibleObject : scene.getVisibleObjects()) {
		double distance = ray.getDistanceToIntersection(visibleObject);

		if (distance < nearestObjectInfo.first) {
			nearestObjectInfo.first = distance;
			nearestObjectInfo.second = visibleObject;
		}
	}

	return nearestObjectInfo;
}

bool Tracer::isRayBlocked(const Ray& ray, double tolerance) const {
	std::pair<double, VisibleObject> nearestObjectInfo = trace(ray);
	return nearestObjectInfo.first < tolerance;
}
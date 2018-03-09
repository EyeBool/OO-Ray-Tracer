#include "Tracer.h"

Tracer::Tracer(const Scene& scene) : scene(scene) {}

std::pair<double, Vector3D> Tracer::trace(const Ray& ray) const {
	std::pair<double, Vector3D> nearestObjectInfo;
	nearestObjectInfo.first = DBL_MAX;
	nearestObjectInfo.second = Vector3D();

	for (VisibleObject visibleObject : scene.getVisibleObjects()) {
		double distance = ray.getDistanceToIntersection(visibleObject);

		if (distance < nearestObjectInfo.first) {
			nearestObjectInfo.first = distance;
			nearestObjectInfo.second = visibleObject.getMaterial().getColor();
		}
	}

	return nearestObjectInfo;
}

bool Tracer::isRayBlocked(const Ray& ray, double tolerance) const {
	std::pair<double, Vector3D> nearestObjectInfo = trace(ray);
	return nearestObjectInfo.first > tolerance;
}
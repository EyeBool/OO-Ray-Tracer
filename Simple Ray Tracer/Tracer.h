#ifndef TRACER_H
#define TRACER_H

#define MAX_DEPTH 5;

#include "Vector3D.h"
#include "Ray.h"
#include "Scene.h"
#include <utility>

class Tracer {
	Vector3D backgroundColor = Vector3D(0.0, 0.0, 0.0);
	Scene scene;
public:
	std::pair<double, VisibleObject*> trace(const Ray& ray, unsigned int depth) const;
	bool isRayBlocked(const Ray& ray, double tolerance = -0.01) const;
};

#endif
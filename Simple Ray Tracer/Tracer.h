#ifndef TRACER_H
#define TRACER_H

#define MAX_DEPTH 5

#include "Vector3D.h"
#include "Ray.h"
#include "Scene.h"
#include <utility>

class Tracer {
	Scene scene;

public:
	Tracer(const Scene& scene);

	std::pair<double, Vector3D> trace(const Ray& ray) const;
	bool isRayBlocked(const Ray& ray, double tolerance = -0.01) const;
};

#endif
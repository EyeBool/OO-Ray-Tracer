#ifndef TRACER_H
#define TRACER_H

#define MAX_DEPTH 5;

#include "Vector3D.h"
#include "Ray.h"
#include "Scene.h"

const Vector3D backgroundColor = Vector3D(0.0, 0.0, 0.0);

Vector3D trace(const Ray& ray, const Scene& scene, unsigned int depth);

#endif
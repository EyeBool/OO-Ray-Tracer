#include "Shader.h"

Shader::Shader(const Scene& scene, const Tracer& tracer) : scene(scene), tracer(tracer) {}


// TODO: finish shader
Vector3D Shader::shade(unsigned int pixel_x, unsigned int pixel_y) {
	Ray viewRay = scene.getRay(pixel_x, pixel_y);

	std::pair<double, VisibleObject*> nearestObjectInfo = tracer.trace(viewRay);

	VisibleObject* nearestObject_ptr = nearestObjectInfo.second;

	if (!nearestObject_ptr)
		return backgroundColor;

	Vector3D objectColor = nearestObject_ptr->getMaterial().getColor();

	return objectColor;
}
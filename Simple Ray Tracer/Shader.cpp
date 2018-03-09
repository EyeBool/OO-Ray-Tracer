#include "Shader.h"

Shader::Shader(const Scene& scene, const ImagePlane& imagePlane, const Tracer& tracer)
	: scene(scene), imagePlane(imagePlane), tracer(tracer) {}


// TODO: finish shader
Vector3D shade(unsigned int pixel_x, unsigned int pixel_y) {
	Ray viewRay = imagePlane.getRay(pixel_x, pixel_y);

	std::pair<double, VisibleObject*> nearestObjectInfo = tracer.trace(viewRay);

	VisibleObject* nearestObject_ptr = nearestObjectInfo.second;

	if (!nearestObject_ptr)
		return backgroundColor;

	Vector3D objectColor = nearestObject_ptr->getMaterial().getColor();

	return objectColor;
}
#include "Shader.h"

Shader::Shader(const Scene& scene, const Tracer& tracer) : scene(scene), tracer(tracer) {}


// TODO: finish shader (light + reflection)
Vector3D Shader::shade(unsigned int pixel_x, unsigned int pixel_y) {
	Ray viewRay = scene.getRay(pixel_x, pixel_y);

	std::pair<double, Vector3D> nearestObjectInfo = tracer.trace(viewRay);

	if (nearestObjectInfo.first == DBL_MAX)
		return backgroundColor;

	return nearestObjectInfo.second;
}
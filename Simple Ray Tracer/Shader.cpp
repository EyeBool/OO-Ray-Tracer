#include "Shader.h"

Shader::Shader(const Scene& scene, const Tracer& tracer) : scene(scene), tracer(tracer) {}


// TODO: add specular
// TODO: decouple the shader code from the Shader class implementation
Vector3D Shader::shade(unsigned int pixel_x, unsigned int pixel_y) {
	Ray viewRay = scene.getRay(pixel_x, pixel_y);

	std::pair<double, VisibleObject> nearestObjectInfo = tracer.trace(viewRay);

	if (nearestObjectInfo.first == DBL_MAX)
		return backgroundColor;

	VisibleObject object = nearestObjectInfo.second;

	double lambert = 0.0;
	Vector3D color = object.getMaterial().getColor();
	Vector3D position = scene.getCamera().getPosition() + nearestObjectInfo.first * viewRay.getDirection();

	// TODO: rethink if the isRayBlocked() method is the best way to figure out if a point is shadowed
	for (Light light : scene.getLights()) {
		// TODO: implement Ray::reverse()
		Ray pointToLightRay = Ray(position, light.getPosition());
		Ray lightToPointRay = Ray(light.getPosition(), position);

		if (!tracer.isRayBlocked(lightToPointRay)) {
			double contribution = dotProduct(pointToLightRay.getDirection(), object.getNormal(position));

			if (contribution > 0)
				lambert += contribution;
		}
	}

	return (lambert * object.getMaterial().getLambert() + object.getMaterial().getAmbient()) * color;
}
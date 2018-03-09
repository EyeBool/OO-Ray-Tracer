#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "ImagePlane.h"
#include "Light.h"
#include "VisibleObject.h"
#include "Ray.h"
#include <vector>

class Scene {
	Camera camera;
	ImagePlane imagePlane;
	std::vector<Light> lights;
	std::vector<VisibleObject> objects;

public:
	Scene(const Camera& camera, const ImagePlane& imagePlane);

	// setters and getters
	Camera getCamera() const;

	ImagePlane getImagePlane() const;

	void addLight(const Light& light);
	std::vector<Light> getLights() const;

	void addVisibleObject(const VisibleObject& visibleObject);
	std::vector<VisibleObject> getVisibleObjects() const;

	Ray getRay(unsigned int pixel_x, unsigned int pixel_y) const;
};

#endif SCENE_H
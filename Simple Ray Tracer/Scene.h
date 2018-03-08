#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "Light.h"
#include "VisibleObject.h"
#include "Ray.h"
#include <vector>

class Scene {
	Camera camera;
	std::vector<Light> lights;
	std::vector<VisibleObject> objects;

public:
	// setters and getters
	Camera getCamera() const;
	void addVisibleObject(const VisibleObject& visibleObject);
	std::vector<VisibleObject> getVisibleObjects() const;
};

#endif SCENE_H
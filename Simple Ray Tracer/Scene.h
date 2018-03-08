#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "Light.h"
#include "VisibleObject.h"
#include <vector>

class Scene {
	Camera camera;
	std::vector<Light> lights;
	std::vector<VisibleObject> objects;

public:
	Camera getCamera();
	void addVisibleObject(VisibleObject visibleObject);
};

#endif SCENE_H
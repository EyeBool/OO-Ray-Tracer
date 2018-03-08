#include "Scene.h"

Camera Scene::getCamera() const {
	return camera;
}

void Scene::addVisibleObject(const VisibleObject & visibleObject) {
	objects.push_back(visibleObject);
}

std::vector<VisibleObject> Scene::getVisibleObjects() const {
	return objects;
}
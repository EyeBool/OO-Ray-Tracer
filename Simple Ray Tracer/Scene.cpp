#include "Scene.h"

Scene::Scene(const Camera& camera, const ImagePlane& imagePlane) : camera(camera), imagePlane(imagePlane) {}

Camera Scene::getCamera() const {
	return camera;
}

ImagePlane Scene::getImagePlane() const {
	return imagePlane;
}

void Scene::addLight(const Light& light) {
	lights.push_back(light);
}

std::vector<Light> Scene::getLights() const {
	return lights;
}

void Scene::addVisibleObject(const VisibleObject & visibleObject) {
	objects.push_back(visibleObject);
}

std::vector<VisibleObject> Scene::getVisibleObjects() const {
	return objects;
}

Ray Scene::getRay(unsigned int pixel_x, unsigned int pixel_y) const {
	Vector3D tail = camera.getPosition();
	Vector3D head =
		imagePlane.getBottomLeftCornerPosition()
		+ double(pixel_x) * imagePlane.getPixelWidth() * camera.getViewingPlanRight()
		+ double(pixel_y) * imagePlane.getPixelHeight() * camera.getViewingPlanUp();

	return Ray(tail, head);
}
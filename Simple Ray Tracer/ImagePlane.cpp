#include "ImagePlane.h"

double ImagePlane::getPixelWidth() {
	return width / double(horizontalResolution);
}

double ImagePlane::getPixelHeight() {
	return height / double(verticalResolution);
}

Vector3D ImagePlane::getCenterPosition() {
	return camera.getPosition() + distanceFromCamera * camera.getDirection();
}

Vector3D ImagePlane::getBottomLeftCornerPosition() {
	return getCenterPosition() - 0.5 * width * camera.getViewingPlanRight() - 0.5 * height * camera.getViewingPlanUp();
}

Ray ImagePlane::getRay(unsigned int pixel_x, unsigned int pixel_y) {
	Vector3D tail = camera.getPosition();
	Vector3D head =
		getBottomLeftCornerPosition()
		+ double(pixel_x) * getPixelWidth() * camera.getViewingPlanRight()
		+ double(pixel_y) * getPixelHeight() * camera.getViewingPlanUp();

	return Ray(tail, head);
}
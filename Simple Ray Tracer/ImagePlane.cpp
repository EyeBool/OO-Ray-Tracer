#include "ImagePlane.h"

ImagePlane::ImagePlane(
	const Camera& camera, double distanceFromCamera,
	double width, double height,
	unsigned int horizontalResolution, unsigned int verticalResolution
)
	: camera(camera), distanceFromCamera(distanceFromCamera),
	width(width), height(height),
	horizontalResolution(horizontalResolution), verticalResolution(verticalResolution) {}

double ImagePlane::getPixelWidth() const {
	return width / double(horizontalResolution);
}

double ImagePlane::getPixelHeight() const {
	return height / double(verticalResolution);
}

Vector3D ImagePlane::getCenterPosition() const {
	return camera.getPosition() + distanceFromCamera * camera.getDirection();
}

Vector3D ImagePlane::getBottomLeftCornerPosition() const {
	return getCenterPosition() - 0.5 * width * camera.getViewingPlanRight() - 0.5 * height * camera.getViewingPlanUp();
}

unsigned int ImagePlane::getHorizontalResolution() const {
	return horizontalResolution;
}

unsigned int ImagePlane::getVerticalResolution() const {
	return verticalResolution;
}
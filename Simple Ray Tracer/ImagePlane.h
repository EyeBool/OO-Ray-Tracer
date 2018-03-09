#ifndef  IMAGEPLANE_H
#define IMAGEPLANE_H

#include "Camera.h"

class ImagePlane {
	Camera camera;
	double distanceFromCamera;
	double width;
	double height;
	unsigned int horizontalResolution;		// in pixels
	unsigned int verticalResolution;		// in pixels

public:
	ImagePlane(
		const Camera& camera, double distanceFromCamera,
		double width, double height,
		unsigned int horizontalResolution, unsigned int verticalResolution
	);

	double getPixelWidth() const;
	double getPixelHeight() const;

	Vector3D getCenterPosition() const;
	Vector3D getBottomLeftCornerPosition() const;

	unsigned int getHorizontalResolution() const;
	unsigned int getVerticalResolution() const;
};

#endif
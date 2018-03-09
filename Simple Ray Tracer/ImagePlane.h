#ifndef  IMAGEPLANE_H
#define IMAGEPLANE_H

#include "Camera.h"
#include "Ray.h"

class ImagePlane {
	Camera camera;
	double distanceFromCamera;
	double width;
	double height;
	unsigned int horizontalResolution;		// in pixels
	unsigned int verticalResolution;		// in pixels

public:
	double getPixelWidth() const;
	double getPixelHeight() const;
	Vector3D getCenterPosition() const;
	Vector3D getBottomLeftCornerPosition() const;
	Ray getRay(unsigned int pixel_x, unsigned int pixel_y) const;
};

#endif
#include "VisibleObject.h"
#include "ImagePlane.h"
#include "Scene.h"
#include "Tracer.h"
#include "Utility.h"

class Shader {
	Scene scene;
	ImagePlance imagePlane;
	Tracer tracer;
	Vector3D backgroundColor = Vector3D(0.0, 0.0, 0.0);

public:
	Shader(const Scene& scene, const ImagePlane& imagePlane, const Tracer& tracer);

	Vector3D shade(unsigned int pixel_x, unsigned int pixel_y);
};
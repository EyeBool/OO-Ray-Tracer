#include "VisibleObject.h"
#include "ImagePlane.h"
#include "Scene.h"
#include "Tracer.h"

class Shader {
	Scene scene;
	Tracer tracer;
	Vector3D backgroundColor = Vector3D(1.0, 1.0, 1.0);

public:
	Shader(const Scene& scene, const Tracer& tracer);

	Vector3D shade(unsigned int pixel_x, unsigned int pixel_y);
};
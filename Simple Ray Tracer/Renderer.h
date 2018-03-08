#ifndef RENDERER_H
#define RENDERER_H

#include "VisibleObject.h"
#include "Scene.h"

class Renderer {
	Vector3D shade(const Scene& scene, const VisibleObject& visibleObject);

public:
	Renderer(Scene scene);
	void render(Scene scene);
};

#endif
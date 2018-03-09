#ifndef RENDERER_H
#define RENDERER_H

#include "VisibleObject.h"
#include "Scene.h"
#include "Shader.h"

class Renderer {
	Scene scene;
	Shader shader;
public:
	Renderer(const Scene& scene, const Shader& shader);
	void render(Scene scene);
};

#endif
#define _SCL_SECURE_NO_WARNINGS 

#ifndef RENDERER_H
#define RENDERER_H

#include "Scene.h"
#include "Tracer.h"
#include "Shader.h"
#include "bitmap_image.hpp"
#include <string>

class Renderer {
	Scene scene;
	Tracer tracer;
	Shader shader;
	bitmap_image image;

public:
	Renderer(const Scene& scene);

	void render(const std::string& file_name);
};

#endif
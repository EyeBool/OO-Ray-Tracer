#include "Renderer.h"

Renderer::Renderer(const Scene & scene)
	: scene(scene), tracer(Tracer(scene)), shader(Shader(scene, tracer))
{
	image = bitmap_image(scene.getImagePlane().getHorizontalResolution(), scene.getImagePlane().getVerticalResolution());
}

void Renderer::render(const std::string& file_name) {
	image.clear();

	for (unsigned x = 0; x < scene.getImagePlane().getHorizontalResolution(); x++) {
		for (unsigned y = 0; y < scene.getImagePlane().getVerticalResolution(); y++) {
			Vector3D color = shader.shade(x, y);
			image.set_pixel(x, y, (unsigned char)color.x, (unsigned char)color.y, (unsigned char)color.z);
		}
	}

	image.save_image(file_name);
}
#define _SCL_SECURE_NO_WARNINGS 

#include "Renderer.h"

#include <iostream>

int main() {
	// set things up

	// create camera
	Camera camera = Camera(Vector3D(0.0, 0.0, -1.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.0, 0.0, 1.0));

	// create image plane
	ImagePlane imagePlane = ImagePlane(camera, 1.0, 2.0, 2.0, 100, 100);

	// create scene
	Scene scene = Scene(camera, imagePlane);

	// create and add lights
	Light light = Light(Vector3D(0.0, 2.0, 0.0));
	scene.addLight(light);

	// create and add objects
	Material sphereMaterial = Material(100, 100, 200, 1, 1, 1, 1);
	VisibleObject sphere = VisibleObject(Vector3D(0.0, 2.0, 0.0), 0.5, sphereMaterial);
	scene.addVisibleObject(sphere);


	// render

	// create a renderer
	Renderer renderer = Renderer(scene);
	renderer.render("first.bmp");

	return 0;
}
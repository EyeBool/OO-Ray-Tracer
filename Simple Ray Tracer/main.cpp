#define _SCL_SECURE_NO_WARNINGS 

#include "Renderer.h"

#include <iostream>

// TODO: fix orientation


int main() {
	// set things up

	// create camera
	Camera camera = Camera(Vector3D(0.0, 0.0, -2.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.0, 0.0, 0.0));

	// create image plane
	ImagePlane imagePlane = ImagePlane(camera, 1.0, 2.0, 2.0, 1000, 1000);

	// create scene
	Scene scene = Scene(camera, imagePlane);

	// create and add lights
	Light light = Light(Vector3D(0.0, 1.0, 0.0));
	scene.addLight(light);

	// create and add objects
	// red
	Material sphere1Material = Material(100.0, 0.0, 0.0, 1, 1.0, 0.1, 1);
	VisibleObject sphere1 = VisibleObject(Vector3D(0.0, 0.0, 0.0), 0.1, sphere1Material);
	scene.addVisibleObject(sphere1);

	// green
	Material sphere2Material = Material(000.0, 200.0, 0.0, 1, 1.0, 0.1, 1);
	VisibleObject sphere2 = VisibleObject(Vector3D(0.75, 0.75, 0.75), .5, sphere2Material);
	scene.addVisibleObject(sphere2);

	// blue
	Material sphere3Material = Material(0.0, 0.0, 200.0, 1, 1.0, 0.1, 1);
	VisibleObject sphere3 = VisibleObject(Vector3D(0.75, -0.5, 0.5), .5, sphere3Material);
	scene.addVisibleObject(sphere3);

	// render

	// create a renderer
	Renderer renderer = Renderer(scene);
	renderer.render("first.bmp");

	return 0;
}
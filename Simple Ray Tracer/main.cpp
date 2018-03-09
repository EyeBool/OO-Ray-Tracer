#define _SCL_SECURE_NO_WARNINGS 

#include "Renderer.h"

#include <iostream>

int main() {
	// set things up

	// create camera
	Camera camera = Camera(Vector3D(0.0, 0.0, -1.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.0, 0.0, 0.0));

	// create image plane
	ImagePlane imagePlane = ImagePlane(camera, 1.0, 2.0, 2.0, 100, 100);

	// create scene
	Scene scene = Scene(camera, imagePlane);

	// create and add lights
	Light light = Light(Vector3D(0.0, 2.0, 0.0));
	scene.addLight(light);

	// create and add objects
	Material sphere1Materia2 = Material(000.0, 200.0, 0.0, 1, 1, 1, 1);
	VisibleObject sphere2 = VisibleObject(Vector3D(0.0, 0.0, 0.75), 0.5, sphere1Materia2);
	scene.addVisibleObject(sphere2);

	Material sphere1Material = Material(100.0, 0.0, 0.0, 1, 1, 1, 1);
	VisibleObject sphere1 = VisibleObject(Vector3D(0.0, 0.0, 0.0), 0.25, sphere1Material);
	scene.addVisibleObject(sphere1);


	// render

	// create a renderer
	Renderer renderer = Renderer(scene);
	renderer.render("first.bmp");

	return 0;
}
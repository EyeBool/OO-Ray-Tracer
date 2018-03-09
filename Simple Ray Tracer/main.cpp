#include "Renderer.h"
#include "bitmap_image.hpp"

#include <iostream>

int main() {
	bitmap_image image(250, 250);
	image.set_all_channels(100, 140, 200);
	image.save_image("test.bmp");

	return 0;
}
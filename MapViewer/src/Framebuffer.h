// Framebuffer.h
//
// Holds the data to determine a frame (as well as providing quick functions
// for modifying and accessing the buffer).

#pragma once

#include <cstdint>
#include <vector>

#include "Color.h"

class Framebuffer {
	public:
	Framebuffer(uint16_t width, uint16_t height);
	~Framebuffer();
	
	Color Get(uint16_t x, uint16_t y);
	void Set(uint16_t x, uint16_t y, Color c);

	uint16_t Width();
	uint16_t Height();

	void Flush();
	void Flush(Color c);

	void Resize(uint16_t width, uint16_t height);

	void *Data();

	private:
	Color *data;
	uint16_t width;
	uint16_t height;
};
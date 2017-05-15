// Framebuffer.cpp
//
// Holds the data to determine a frame (as well as providing quick functions
// for modifying and accessing the buffer).

#include "Framebuffer.h"

Framebuffer::Framebuffer(uint16_t width, uint16_t height) {
	this->data = nullptr;
	Resize(width, height);
}

Framebuffer::~Framebuffer() {
	delete[] data;
}

Color Framebuffer::Get(uint16_t x, uint16_t y) {
	return data[x + y * width];
}

void Framebuffer::Set(uint16_t x, uint16_t y, Color c) {
	data[x + y * width] = c;
}

uint16_t Framebuffer::Width() {
	return width;
}

uint16_t Framebuffer::Height() {
	return height;
}

void Framebuffer::Flush() {
	Flush(0);
}

void Framebuffer::Flush(Color c) {
	memset(Data(), c.ARGB(), sizeof(Color) * width * height);
}

void Framebuffer::Resize(uint16_t width, uint16_t height) {
	if (data != nullptr) {
		delete[] data;
	}

	data = new Color[width * height];

	this->width = width;
	this->height = height;
	Flush();
}

void *Framebuffer::Data() {
	return data;
}

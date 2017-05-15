// Color.h
//
// Determines a color based on 8-bit values. This is condensed into a 32-bit
// value for quick modification.

#include "Color.h"

Color::Color() : Color(0, 0, 0, 0) {}

Color::Color(uint8_t r, uint8_t g, uint8_t b) : Color(0, 0, 0, 0) {
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	argb = (a << 24) | (r << 16) | (g << 8) | (b << 0);
}

Color::Color(uint32_t argb) {
	this->argb = argb;
}

Color::~Color() {
}

uint8_t Color::R() {
	return (argb & 0x00FF0000) >> 16;
}

uint8_t Color::G() {
	return (argb & 0x0000FF00) >> 8;
}

uint8_t Color::B() {
	return (argb & 0x000000FF);
}

uint8_t Color::A() {
	return (argb & 0xFF000000) >> 24;
}

uint32_t Color::ARGB() {
	return argb;
}

uint8_t Color::R(uint8_t r) {
	argb = (r << 16) | (argb & 0xFF00FFFF);
	return R();
}

uint8_t Color::G(uint8_t g) {
	argb = (g << 8) | (argb & 0xFFFF00FF);
	return G();
}

uint8_t Color::B(uint8_t b) {
	argb = (b) | (argb & 0xFFFFFF00);
	return B();
}

uint8_t Color::A(uint8_t a) {
	argb = (a << 24) | (argb & 0x00FFFF00);
	return A();
}

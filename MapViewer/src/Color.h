// Color.h
//
// Determines a color based on 8-bit values. This is condensed into a 32-bit
// value for quick modification.

#pragma once

#include <cstdint>

class Color {
	public:
	Color();
	Color(uint8_t r, uint8_t g, uint8_t b);
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	Color(uint32_t argb);
	~Color();

	uint8_t R();
	uint8_t G();
	uint8_t B();
	uint8_t A();

	uint8_t R(uint8_t r);
	uint8_t G(uint8_t g);
	uint8_t B(uint8_t b);
	uint8_t A(uint8_t a);

	private:
	uint32_t argb;
};


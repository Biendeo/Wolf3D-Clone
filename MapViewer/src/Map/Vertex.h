// Vertex.h
//
// Contains details about a vertex of a map.

#pragma once

#include <cstdint>

class Vertex {
	public:
	Vertex();
	Vertex(int32_t x, int32_t z);
	~Vertex();

	private:
	int32_t x;
	int32_t z;
};


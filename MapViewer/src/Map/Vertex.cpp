// Vertex.cpp
//
// Contains details about a vertex of a map.

#include "Vertex.h"



Vertex::Vertex() : Vertex(0, 0) {}

Vertex::Vertex(int32_t x, int32_t z) {
	this->x = x;
	this->z = z;
}


Vertex::~Vertex() {
}

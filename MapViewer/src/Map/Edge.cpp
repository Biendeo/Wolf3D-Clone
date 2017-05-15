// Edge.cpp
//
// Contains details about an edge of a map.

#include "Edge.h"

Edge::Edge(Vertex * v1, Vertex * v2, Color c) {
	this->v1 = v1;
	this->v2 = v2;
	this->color = c;
}

Edge::~Edge() {

}

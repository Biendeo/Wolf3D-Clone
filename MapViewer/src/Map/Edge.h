// Edge.h
//
// Contains details about an edge of a map.

#pragma once

#include "../Color.h"
#include "Vertex.h"

class Edge {
	public:
	Edge(Vertex *v1, Vertex *v2, Color c);
	~Edge();

	private:
	Vertex *v1;
	Vertex *v2;
	Color color;
};


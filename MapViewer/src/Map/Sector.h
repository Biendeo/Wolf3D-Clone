// Sector.h
//
// Contains details about a sector of the map.

#pragma once

#include <cstdint>
#include <set>

#include "../Color.h"
#include "Edge.h"

class Sector {
	public:
	Sector(std::set<Edge *> edges, Color floorColor, Color ceilingColor, int16_t floorHeight, int16_t ceilingHeight);
	~Sector();

	private:
	std::set<Edge *> edges;
	Color floorColor;
	Color ceilingColor;
	int16_t floorHeight;
	int16_t ceilingHeight;
};


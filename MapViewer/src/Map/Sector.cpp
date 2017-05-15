// Sector.cpp
//
// Contains details about a sector of the map.

#include "Sector.h"



Sector::Sector(std::set<Edge *> edges, Color floorColor, Color ceilingColor, int16_t floorHeight, int16_t ceilingHeight) {
	this->edges = edges;
	this->floorColor = floorColor;
	this->ceilingColor = ceilingColor;
	this->floorHeight = floorHeight;
	this->ceilingHeight = ceilingHeight;
}


Sector::~Sector() {
}

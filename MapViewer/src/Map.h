// Map.h
//
// Handles loading Map data from files, as well as functions to access the map,
// and modify its contents.

#pragma once
#include <string>
#include <vector>

#include "Map/Edge.h"
#include "Map/Sector.h"
#include "Map/Vertex.h"

class Map {
	public:
	Map();
	Map(std::string filePath);
	~Map();

	private:
	std::vector<Vertex> vertices;
	std::vector<Edge> edges;
	std::vector<Sector> sectors;
	void Open(std::string filePath);
	
};


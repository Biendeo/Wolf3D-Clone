// Map.cpp
//
// Handles loading Map data from files, as well as functions to access the map,
// and modify its contents.

#include "Map.h"

#include <fstream>
#include <set>

#include "json.hpp"

Map::Map() {

}

Map::Map(std::string filePath) {
	Open(filePath);
}


Map::~Map() {

}

void Map::Open(std::string filePath) {
	using json = nlohmann::json;
	std::ifstream mapFile(filePath);
	json mapJson;
	mapFile >> mapJson;
	mapFile.close();

	for (auto &v : mapJson["vertices"]) {
		vertices.emplace_back(Vertex(v["x"], v["z"]));
	}
	for (auto &e : mapJson["edges"]) {
		edges.emplace_back(Edge(&vertices[e["vertex1"]], &vertices[e["vertex2"]], Color((uint32_t)e["color"])));
	}
	for (auto &s : mapJson["sectors"]) {
		std::set<Edge *> sectorEdges;
		for (auto &e : s["edges"]) {
			sectorEdges.insert(&edges[e]);
		}
		sectors.emplace_back(Sector(sectorEdges, Color((uint32_t)s["floorColor"]), Color((uint32_t)s["ceilingColor"]), s["floor"], s["ceiling"]));
	}
}

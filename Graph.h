#pragma once
#include <vector>
#include "Arches.h"
class Graph
{
public:
	Graph();
	
	std::vector<Node> getNodes();
	std::vector<Arch> getArches();

	void addNode(Node node);
	void addNode(QPoint coordinate);
	void addArch(Arch arch);
	void addArch(Node firstNode, Node secondNode);




private:
	std::vector<Node> m_nodes;
	std::vector<Arch> m_arches;

};


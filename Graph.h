#pragma once
#include <vector>
#include "Arches.h"
#include <fstream>
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
	void createNewSpace();
	void createNewDirectedArch(Arch arch);
	void createNewNonDirectedArch(Arch arch);


private:
	
	void updateFile();

	std::vector<Node> m_nodes;
	std::vector<Arch> m_arches;
	std::vector<std::vector<int>> m_adjacencyMatrix;
};


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
	void addArch(Arch arch, bool typeOfGraph);
	void addArch(Node firstNode, Node secondNode,bool typeOfGraph);
	void createNewSpace();
	void createNewDirectedArch(Arch arch);
	void createNewNonDirectedArch(Arch arch);


private:

	bool validateDirectedArch(Arch arch);
	bool validateNonDirectedArch(Arch arch);
	void updateFile();
	std::vector<Node> m_nodes;
	std::vector<Arch> m_arches;
	std::vector<std::vector<int>> m_adjacencyMatrix;
};


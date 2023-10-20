#include "Graph.h"

Graph::Graph()
{
}

std::vector<Node> Graph::getNodes()
{
    return m_nodes;
}

std::vector<Arch> Graph::getArches()
{
    return m_arches;
}

void Graph::addNode(Node node)
{
    m_nodes.push_back(node);
}

void Graph::addNode(QPoint coordinate)
{
    Node node;
    node.setValue(m_nodes.size());
    node.setCoordinates(coordinate);
    m_nodes.push_back(node);


}

void Graph::addArch(Arch arch)
{
    m_arches.push_back(arch);
}

void Graph::addArch(Node firstNode, Node secondNode)
{
    Arch arch(firstNode, secondNode);
    m_arches.push_back(arch);
}

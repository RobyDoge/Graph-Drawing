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
    createNewSpace();
}

void Graph::addNode(QPoint coordinate)
{
    Node node;
    node.setValue(m_nodes.size());
    node.setCoordinates(coordinate);
    m_nodes.push_back(node);
    createNewSpace();

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

void Graph::createNewSpace()
{
    std::vector<int> newCollom(m_adjacencyMatrix.size() + 1, 0);
    if(m_adjacencyMatrix.size())
    {
        for (int i = 0; i < m_adjacencyMatrix.size(); i++)
        {
            m_adjacencyMatrix[i].push_back(0);
        }
    }
    m_adjacencyMatrix.emplace_back(newCollom);
    updateFile();
}

void Graph::createNewNonDirectedArch(Arch arch)
{
    m_adjacencyMatrix[arch.getFirstNode().getValue()][arch.getSecondNode().getValue()] = 1;
    m_adjacencyMatrix[arch.getSecondNode().getValue()][arch.getFirstNode().getValue()] = 1;
    updateFile();
}

void Graph::createNewDirectedArch(Arch arch)
{
    m_adjacencyMatrix[arch.getFirstNode().getValue()][arch.getSecondNode().getValue()] = 1;
    updateFile();
}

void Graph::updateFile()
{
    std::ofstream fileOut("adjacencyMatrix.txt",std::ios::trunc);
    if (fileOut.is_open())
    {
        fileOut << m_nodes.size()<<std::endl;
        for(auto aux: m_adjacencyMatrix)
        {
            for (auto aux2 : aux)
                fileOut << aux2 << " ";
            fileOut << std::endl;
        }    
    }
}


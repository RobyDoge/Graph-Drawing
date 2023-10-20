#include "Arches.h"

Arch::Arch()
{
}

Arch::Arch(Node firstNode, Node secondNode)
{
    m_firstNode = firstNode;
    m_secondNode = secondNode;
}

void Arch::setFirstNode(Node firstNode)
{
    m_firstNode = firstNode;
}

void Arch::setSecondNode(Node secondNode)
{
    m_secondNode = secondNode;
}

Node Arch::getFirstNode()
{
    return m_firstNode;
}

Node Arch::getSecondNode()
{
    return m_secondNode;
}

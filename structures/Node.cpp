#include "../pch.h"
#include "Node.h"

bool Node::operator==(Node node) const
{
    return (positionX == node.positionX and positionY == node.positionY);
}

bool Node::operator!=(Node node) const
{
    return !(positionX == node.positionY and positionY == node.positionY);
}

bool Node::operator<(Node node) const
{
    return std::tie(positionX, positionY) < std::tie(node.positionX, node.positionY);
}

std::basic_iostream<char>::basic_ostream &Node::operator<<(std::basic_iostream<char>::basic_ostream &out) const
{
    out << '(' << positionX << ',' << positionY << ')';
    return out;
}
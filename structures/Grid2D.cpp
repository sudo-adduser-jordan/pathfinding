#include "../pch.h"
#include "Grid2D.h"

std::array<Node, 4> Grid2D::DIRS = {
    Node{1, 0}, Node{-1, 0},
    Node{0, -1}, Node{0, 1}};

bool Grid2D::in_bounds(Node node) const
{
    return 0 <= node.positionX and node.positionX < width and 0 <= node.positionY and node.positionY < height;
}

bool Grid2D::passable(Node node) const
{
    return walls.find(node) == walls.end();
}

std::vector<Node> Grid2D::neighbors(Node node) const
{
    std::vector<Node> results;
    for (Node direction : DIRS)
    {
        Node next{node.positionX + direction.positionX, node.positionY + direction.positionY};
        if (in_bounds(next) and passable(next))
        {
            results.push_back(next);
        }
    }
    if ((node.positionX + node.positionY) % 2 == 0)
    {
        // see "Ugly paths" section for an explanation:
        std::reverse(results.begin(), results.end());
    }
    return results;
}

double GridWithWeights::cost(Node from_node, Node to_node) const
{
    return forests.find(to_node) != forests.end() ? 5 : 1;
}

void add_rect(Grid2D &grid, int x1, int y1, int x2, int y2)
{
    for (int x = x1; x < x2; ++x)
    {
        for (int y = y1; y < y2; ++y)
        {
            grid.walls.insert(Node{x, y});
        }
    }
}

Grid2D make_diagram1()
{
    Grid2D grid(30, 15);
    add_rect(grid, 3, 3, 5, 12);
    add_rect(grid, 13, 4, 15, 15);
    add_rect(grid, 21, 0, 23, 7);
    add_rect(grid, 23, 5, 26, 7);
    return grid;
}

GridWithWeights make_diagram4()
{
    GridWithWeights grid(10, 10);
    add_rect(grid, 1, 7, 4, 9);
    typedef Node L;
    grid.forests = std::unordered_set<Node>{
        L{3, 4}, L{3, 5}, L{4, 1}, L{4, 2},
        L{4, 3}, L{4, 4}, L{4, 5}, L{4, 6},
        L{4, 7}, L{4, 8}, L{5, 1}, L{5, 2},
        L{5, 3}, L{5, 4}, L{5, 5}, L{5, 6},
        L{5, 7}, L{5, 8}, L{6, 2}, L{6, 3},
        L{6, 4}, L{6, 5}, L{6, 6}, L{6, 7},
        L{7, 3}, L{7, 4}, L{7, 5}};
    return grid;
}

GridWithWeights make_diagram_nopath()
{
    GridWithWeights grid(10, 10);
    add_rect(grid, 5, 0, 6, 10);
    return grid;
}
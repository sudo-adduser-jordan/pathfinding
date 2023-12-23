#pragma once
#include "../pch.h"

#include "../structures/Node.h"

struct Grid2D {
    int width; 
    int height;
    std::unordered_set<Node> walls;
    static std::array<Node, 4> DIRS;

    Grid2D(int x, int y) : width(x), height(y) {}

    bool in_bounds(Node node) const;
    bool passable(Node node) const;
    std::vector<Node> neighbors(Node node) const;
};


struct GridWithWeights : Grid2D {
    std::unordered_set<Node> forests;

    GridWithWeights(int w, int h) : Grid2D(w, h) {}

    double cost(Node from_node, Node to_node) const;
};


void add_rect(Grid2D& grid, int x1, int y1, int x2, int y2);
Grid2D make_diagram1();
GridWithWeights make_diagram4();
GridWithWeights make_diagram_nopath();
#pragma once
#include "../pch.h"

#include "../structures/Node.h"

struct Graph {
    std::unordered_map<char, std::vector<char> > edges;

    std::vector<char> neighbors(char id) {
        return edges[id];
    }
};

// This outputs a grid. Pass in a distances map if you want to print
// the distances, or pass in a point_to map if you want to print
// arrows that point to the parent location, or pass in a path vector
// if you want to draw the path.
template<class Graph>
void draw_grid(const Graph& graph,
               std::unordered_map<Node, double>* distances = nullptr,
               std::unordered_map<Node, Node>* point_to = nullptr,
               std::vector<Node>* path = nullptr,
               Node* start = nullptr,
               Node* goal = nullptr) {
    const int field_width = 3;
    std::cout << std::string(field_width * graph.width, '_') << '\n';
    for (int y = 0; y != graph.height; ++y) {
        for (int x = 0; x != graph.width; ++x) {
            Node id{ x, y };
            if (graph.walls.find(id) != graph.walls.end()) {
                std::cout << std::string(field_width, '#');
            }
            else if (start and id == *start) {
                std::cout << " A ";
            }
            else if (goal and id == *goal) {
                std::cout << " Z ";
            }
            else if (path != nullptr and find(path->begin(), path->end(), id) != path->end()) {
                std::cout << " @ ";
            }
            else if (point_to != nullptr and point_to->count(id)) {
                Node next = (*point_to)[id];
                if (next.positionX == x + 1) { std::cout << " > "; }
                else if (next.positionX == x - 1) { std::cout << " < "; }
                else if (next.positionY == y + 1) { std::cout << " v "; }
                else if (next.positionY == y - 1) { std::cout << " ^ "; }
                else { std::cout << " * "; }
            }
            else if (distances != nullptr and distances->count(id)) {
                std::cout << ' ' << std::left << std::setw(field_width - 1) << (*distances)[id];
            }
            else {
                std::cout << " . ";
            }
        }
        std::cout << '\n';
    }
    std::cout << std::string(field_width * graph.width, '~') << '\n';
}
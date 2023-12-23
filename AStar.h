#pragma once
#include "pch.h"
#include "Pq.h"
#include "Node.h"

inline double heuristic(Node a, Node b) {
    return std::abs(a.positionX - b.positionX) + std::abs(a.positionY - b.positionY);
}

template<typename Location, typename Graph>
void a_star_search
(Graph graph,
 Location start,
 Location goal,
 std::unordered_map<Location, Location>& came_from,
 std::unordered_map<Location, double>& cost_so_far) {
    PriorityQueue<Location, double> frontier;
    frontier.put(start, 0);

    came_from[start] = start;
    cost_so_far[start] = 0;

    while (!frontier.empty()) {
        Location current = frontier.get();

        if (current == goal) {
            break;
        }

        for (Location next : graph.neighbors(current)) {
            double new_cost = cost_so_far[current] + graph.cost(current, next);
            if (cost_so_far.find(next) == cost_so_far.end()
                || new_cost < cost_so_far[next]) {
                cost_so_far[next] = new_cost;
                double priority = new_cost + heuristic(next, goal);
                frontier.put(next, priority);
                came_from[next] = current;
            }
        }
    }
}
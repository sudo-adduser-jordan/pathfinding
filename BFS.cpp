//#pragma once
//#include "pch.h"
//#include "BFS.h"
//
//
//template<typename Location, typename Graph>
//std::unordered_map<Location, Location>
//breadth_first_search(Graph graph, Location start) {
//    std::queue<Location> frontier;
//    frontier.push(start);
//
//    std::unordered_map<Location, Location> came_from;
//    came_from[start] = start;
//
//    while (!frontier.empty()) {
//        Location current = frontier.front();
//        frontier.pop();
//
//        for (Location next : graph.neighbors(current)) {
//            if (came_from.find(next) == came_from.end()) {
//                frontier.push(next);
//                came_from[next] = current;
//            }
//        }
//    }
//    return came_from;
//}
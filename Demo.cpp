//#pragma once
#include "pch.h"
#include "Graph.h"
#include "Grid2D.h"
#include "BFS.h"
#include "BFSGoal.h"
#include "Dijkstra.h"
#include "AStar.h"

template<typename Location>
std::vector<Location> reconstruct_path(
	Location start, Location goal,
	std::unordered_map<Location, Location> came_from
) {
	std::vector<Location> path;
	Location current = goal;
	if (came_from.find(goal) == came_from.end()) {
		return path; // no path can be found
	}
	while (current.positionX != start.positionX or current.positionY != start.positionY) {
		path.push_back(current);
		current = came_from[current];
	}
	//path.push_back(start); // optional
	//std::reverse(path.begin(), path.end());
	return path;
}

int main() {
	Node start;
	Node goal;
	Grid2D grid = make_diagram1();
	GridWithWeights weightedGrid = make_diagram4();
	GridWithWeights grid_no_path = make_diagram_nopath();
	std::unordered_map<Node, Node> came_from;
	std::unordered_map<Node, double> cost_so_far;

	std::cout << std::endl;
	std::cout << "GRAPHS" << std::endl;
	draw_grid(grid);
	draw_grid(grid_no_path);
	draw_grid(weightedGrid);

	std::cout << std::endl;
	std::cout << "BREADTH FIRST SEARCH" << std::endl;
	start={ 7, 8 };
	auto parents = breadth_first_search(grid, start);
	draw_grid(grid, nullptr, &parents, nullptr, &start);


	std::cout << std::endl;
	std::cout << "BREADTH FIRST SEARCH W/ GOAL" << std::endl;
	goal={ 17, 2 };
	start = { 8, 7 };
	auto came_from_bfs = breadth_first_search_goal(grid, start, goal);
	draw_grid(grid, nullptr, &came_from_bfs, nullptr, &start, &goal);

	std::cout << std::endl;
	std::cout << "DIJKSTRA SHORTEST PATH" << std::endl;
	start = { 1, 4 };
	goal = { 8, 3 };
	came_from.clear();
	cost_so_far.clear();
	dijkstra_search(weightedGrid, start, goal, came_from, cost_so_far);
	draw_grid(weightedGrid, nullptr, &came_from, nullptr, &start, &goal);
	std::cout << '\n';
	std::vector<Node> path = reconstruct_path(start, goal, came_from);
	draw_grid(weightedGrid, nullptr, nullptr, &path, &start, &goal);

	std::cout << std::endl;
	std::cout << "DIJKSTRA SHORTEST PATH W/ NO AVAIABLE PATH" << std::endl;
	start = { 1, 4 };
	goal = { 8, 3 };
	came_from.clear();
	cost_so_far.clear();
	dijkstra_search(grid_no_path, start, goal, came_from, cost_so_far);
	draw_grid(grid_no_path, nullptr, &came_from, nullptr, &start, &goal);
	// reconstruct_path(start, goal, came_from) returns an empty vector

	std::cout << std::endl;
	std::cout << "DIJKSTRA SHORTEST PATH W/ DISTANCES" << std::endl;
	start = { 1, 4 };
	goal = { -1, -1 };
	came_from.clear();
	cost_so_far.clear();
	dijkstra_search(weightedGrid, start, goal, came_from, cost_so_far);
	draw_grid(weightedGrid, &cost_so_far, nullptr, nullptr, &start, &goal);

	std::cout << std::endl;
	std::cout << "A STAR BEST PATH" << std::endl;
	start = { 1, 4 };
	goal={ 8, 3 };
	came_from.clear();
	cost_so_far.clear();
	a_star_search(weightedGrid, start, goal, came_from, cost_so_far);
	draw_grid(weightedGrid, nullptr, &came_from, nullptr, &start, &goal);
	std::cout << '\n';
	path = reconstruct_path(start, goal, came_from);
	draw_grid(weightedGrid, nullptr, nullptr, &path, &start, &goal);
	std::cout << '\n';
	draw_grid(weightedGrid, &cost_so_far, nullptr, nullptr, &start, &goal);


}
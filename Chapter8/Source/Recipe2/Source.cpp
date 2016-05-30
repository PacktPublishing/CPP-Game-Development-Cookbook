/* A* Heuristic function */

// This just contains the core principle of A* algorithm
// Based on the principle from "Red Blob Games"


#include <iostream>


int heuristic(GameGrid::Location a, GameGrid::Location b) 
{
	int x1, y1, x2, y2;
	return abs(x1 - x2) + abs(y1 - y2);
}

template<typename Graph>
void a_star_search
(const Graph& graph,
typename Graph::Location start,
typename Graph::Location goal,
unordered_map<typename Graph::Location, typename Graph::Location>& came_from,
unordered_map<typename Graph::Location, int>& cost_so_far)
{
	typedef typename Graph::Location Location;
	PriorityQueue<Location> frontier;
	frontier.put(start, 0);

	came_from[start] = start;
	cost_so_far[start] = 0;

	while (!frontier.empty()) {
		auto current = frontier.get();

		if (current == goal) {
			break;
		}

		for (auto next : graph.neighbors(current)) {
			int new_cost = cost_so_far[current] + graph.cost(current, next);
			if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
				cost_so_far[next] = new_cost;
				int priority = new_cost + heuristic(next, goal);
				frontier.put(next, priority);
				came_from[next] = current;
			}
		}
	}
}
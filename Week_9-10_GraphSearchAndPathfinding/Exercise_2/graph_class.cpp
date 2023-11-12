using namespace std;
#include "graph_class.h"
#include <queue>
#include <climits>

void Graph::addEdge(int u, int v) // undirected graph (edge u-v and edge v-u)
{
	adj[u].push_back(v); // add v to u's list
	adj[v].push_back(u); // add u to v's list
}

void Graph::addDirectedEdge(int u, int v) // directed graph (edge u->v)
{
	adj[u].push_back(v); // add v to u's list (u->v)
}

void Graph::dfs(int vertex, vector<int> &path) // dept-first search (DFS)
{
	stack<int> sorting;				  // stack for sorting
	vector<bool> visited(adj.size()); // visited vector

	for (int v = 0; v < adj.size(); ++v) // initialize visited vector
	{
		visited[v] = false; // set all vertices as not visited
	}
	dfs(vertex, visited, path, sorting); // call recursive helper function
}

void Graph::bfs(int s, vector<int> &path, vector<int> &dist) // breadth-first search (BFS)
{
	queue<int> q;
	vector<bool> visited(adj.size()); // size of visited vector is the number of vertices in the graph

	for (int v = 0; v < adj.size(); ++v)
	{
		dist[v] = INT_MAX;	// set all distances to infinity
		visited[v] = false; // set all vertices as not visited
	}
	dist[s] = 0;
	visited[s] = true; // mark the current node as visited and enqueue it
	q.push(s);		   // enqueue source vertex s

	while (!q.empty())
	{
		s = q.front(); // dequeue a vertex from queue and print it
		q.pop();
		for (auto w : adj[s]) // get all adjacent vertices of the dequeued vertex s
		{
			if (!visited[w]) // if a adjacent has not been visited, then mark it visited and enqueue it
			{
				dist[w] = dist[s] + 1; // update distance
				visited[w] = true;
				path[w] = s;
				q.push(w);
			}
		}
	}
}

int Graph::connectedComponents() // count the number of connected components in an undirected graph
{
	int components = 0;
	stack<int> sorting;
	vector<int> path(adj.size());
	vector<bool> visited(adj.size());
	for (int v = 0; v < adj.size(); ++v)
	{
		visited[v] = false;
	}

	for (int v = 0; v < adj.size(); ++v)
	{
		if (!visited[v])
		{
			++components;
			dfs(v, visited, path, sorting);
		}
	}

	return components;
}

void Graph::topologicalSort(int v) // topological sort for a directed acyclic graph (DAG)
{
	stack<int> sorting;
	vector<int> path(adj.size());
	vector<bool> visited(adj.size());

	for (int v = 0; v < adj.size(); ++v)
	{
		visited[v] = false;
	}
	dfs(v, visited, path, sorting);
	while (sorting.empty() == false)
	{
		cout << sorting.top() << " ";
		sorting.pop();
	}
}

void Graph::addWeightedEdge(int u, int v, int w) // add weighted edge u->v with weight w
{
	adj[u].push_back(v);
	weight[u][v] = w;
}

void Graph::dijkstra(int s, vector<int> &path, vector<int> &dist) // Dijkstra's algorithm
{
	struct pair_comp
	{
		constexpr bool operator()(pair<int, int> const &a, pair<int, int> const &b) const noexcept // compare function for priority queue
		{
			return a.first > b.first; // compare first element of pair
		}
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, pair_comp> q; // priority queue for sorting
	vector<bool> visited(adj.size());

	for (int v = 0; v < adj.size(); ++v) // initialize visited vector
	{
		dist[v] = INFINITY; // set all distances to infinity
		visited[v] = false;
		path[v] = -1; // set all vertices as not visited
	}
	dist[s] = 0;
	q.push(make_pair(dist[s], s));

	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		visited[u] = true;
		for (auto v : adj[u])
		{
			if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight[u][v] < dist[v]) // if a adjacent has not been visited, then mark it visited and enqueue it
			{
				dist[v] = dist[u] + weight[u][v];
				path[v] = u;
				q.push(make_pair(dist[v], v));
			}
		}
	}
}

void Graph::dijkstra_early_exit(int s, int target, vector<int> &path, vector<int> &dist) // Dijkstra's algorithm with early exit
{
	struct pair_comp
	{
		constexpr bool operator()(pair<int, int> const &a, pair<int, int> const &b) const noexcept
		{
			return a.first > b.first;
		}
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, pair_comp> q; // priority queue for sorting
	vector<bool> visited(adj.size());

	for (int v = 0; v < adj.size(); ++v)
	{
		dist[v] = INFINITY;
		visited[v] = false;
		path[v] = -1;
	}
	dist[s] = 0;
	q.push(make_pair(dist[s], s));

	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		visited[u] = true;

		if (u == target)
		{
			// Early exit when the target vertex is reached
			break;
		}

		for (auto v : adj[u])
		{
			if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight[u][v] < dist[v])
			{
				dist[v] = dist[u] + weight[u][v];
				path[v] = u;
				q.push(make_pair(dist[v], v));
			}
		}
	}
}

void Graph::dijkstra_nopq(int s, vector<int> &path, vector<int> &dist) // Dijkstra's algorithm without priority queue
{
	priority_queue<int> q;
	vector<bool> visited(adj.size());

	for (int v = 0; v < adj.size(); ++v)
	{
		dist[v] = INFINITY;
		visited[v] = false;
	}
	dist[s] = 0;
	for (int c = 0; c < adj.size(); c++)
	{
		int u, min = INFINITY; // find minimum node
		for (int v = 0; v < adj.size(); v++)
		{
			if (!visited[v] && dist[v] <= min)
			{
				min = dist[v];
				u = v;
			}
		}
		visited[u] = true;
		for (auto v : adj[u])
		{
			if (!visited[v] && weight[u][v] && dist[u] != INT_MAX && dist[u] + weight[u][v] < dist[v])
			{
				dist[v] = dist[u] + weight[u][v];
				path[v] = u;
			}
		}
	}
}

void Graph::allPairs(Matrix<int> &path, Matrix<int> &dist) // Floyd-Warshall algorithm
{
	int n = adj.size();
	// Initialize d and path
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dist[i][j] = weight[i][j];
			path[i][j] = -1;
		}
	}

	for (int k = 0; k < n; ++k)
	{
		// Consider each vertex as an intermediate
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					// Update shortest path
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}

int Graph::kruskalMST() // Kruskal's algorithm
{
	int mst_wt = 0; // Initialize result
	vector<pair<int, pair<int, int>>> edges;

	for (int i = 0; i < adj.size(); i++)
	{
		for (auto j : adj[i])
		{
			edges.push_back({weight[i][j], {i, j}});
		}
	}

	// Sort edges in increasing order on basis of cost
	sort(edges.begin(), edges.end());

	// Create disjoint sets
	DisjSets ds(adj.size());

	// Iterate through all sorted edges
	vector<pair<int, pair<int, int>>>::iterator it;
	for (it = edges.begin(); it != edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		// Check if the selected edge is creating
		// a cycle or not (Cycle is created if u
		// and v belong to same set)
		if (set_u != set_v)
		{
			// Current edge will be in the MST
			cout << u << " - " << v << ", ";

			// Update MST weight
			mst_wt += it->first;

			// Merge two sets
			ds.unionSets(set_u, set_v);
		}
	}

	return mst_wt;
}

int Graph::primMST() // Prim's algorithm
{
	int mst_wt = 0;					  // Initialize result
	vector<int> parent(adj.size());	  // Array to store MST
	vector<int> key(adj.size());	  // Values to pick minimum weight edge in cut
	vector<bool> visited(adj.size()); // To represent set of vertices included

	// Initialize all keys as INFINITE
	for (int i = 0; i < adj.size(); i++)
	{
		key[i] = INFINITY, visited[i] = false;
	}

	// Always include first 1st vertex in MST, make sure it is picked first.
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	// The MST will have V vertices
	for (int count = 0; count < adj.size(); count++)
	{
		// Pick the minimum key vertex not yet included in MST
		int min = INFINITY, u;
		for (int v = 0; v < adj.size(); v++)
		{
			if (visited[v] == false && key[v] < min)
			{
				min = key[v], u = v;
			}
		}
		// Add the picked vertex to the MST Set
		visited[u] = true;
		if (u != 0)
		{
			mst_wt += min;
			cout << u << " - " << parent[u] << ", ";
		}
		// Update key/parent of the adjacent vertices of the picked vertex.
		for (auto v : adj[u])
		{
			if (weight[u][v] && visited[v] == false && weight[u][v] < key[v])
			{
				parent[v] = u, key[v] = weight[u][v];
			}
		}
	}
	return mst_wt;
}

void Graph::bellmanFord(int s, vector<int> &path, vector<int> &dist) // Bellman-Ford algorithm
{
	int n = adj.size(); // number of vertices
	for (int i = 0; i < n; i++)
	{
		dist[i] = INFINITY; // set all distances to infinity
		path[i] = -1;		// set all vertices as not visited
	}
	dist[s] = 0; // set distance from source to 0

	for (int i = 0; i < n - 1; i++) // relax all edges |V| - 1 times
	{
		for (int u = 0; u < n; u++) // update distances
		{
			for (auto v : adj[u])
			{
				if (dist[u] != INFINITY && dist[u] + weight[u][v] < dist[v]) // if a adjacent has not been visited, then mark it visited and enqueue it
				{
					dist[v] = dist[u] + weight[u][v];
					path[v] = u;
				}
			}
		}
	}

	for (int u = 0; u < n; u++)
	{
		for (auto v : adj[u]) // update distances
		{
			if (dist[u] != INFINITY && dist[u] + weight[u][v] < dist[v])
			{
				break;
			}
		}
	}
}

void Graph::print() // print adjacency list representation of graph
{
	for (int v = 0; v < adj.size(); ++v)
	{
		cout << "Adjacency list of vertex " << v;
		for (auto x : adj[v])
			cout << " -> " << x;
		cout << endl;
	}
}

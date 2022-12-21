// C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array. dist[i] will hold the
                 // shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

// driver's code
int main()
{

    /* Let us create the example graph discussed above */
    int graph[V][V];
    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Function call
    dijkstra(graph, 0);

    return 0;
}
// example input:
//  0 4 0 0 0 0 0 8 0
//  4 0 8 0 0 0 0 11 0
//  0 8 0 7 0 4 0 0 2
//  0 0 7 0 9 14 0 0 0
//  0 0 0 9 0 10 0 0 0
//  0 0 4 14 10 0 2 0 0
//  0 0 0 0 0 2 0 1 6
//  8 11 0 0 0 0 1 0 7
//  0 0 2 0 0 0 6 7 0

// example output:
// Vertex   Distance from Source
// 0                0
// 1                4
// 2                12
// 3                19
// 4                21
// 5                11
// 6                9
// 7                8
// 8                14
// Time Complexity: O(V^2). If the input graph is represented using adjacency list, it can be reduced to O(E log V) with the help of binary heap.

// pseudo code:
//  dijkstra(Graph, source):
//      create vertex set Q
//      for each vertex v in Graph:             // Initialization
//          dist[v] ← INFINITY                  // Unknown distance from source to v
//          prev[v] ← UNDEFINED                 // Previous node in optimal path from source
//          add v to Q                          // All nodes initially in Q (unvisited nodes)
//      dist[source] ← 0                        // Distance from source to source
//      while Q is not empty:
//          u ← vertex in Q with min dist[u]    // Source node will be selected first
//          remove u from Q
//          for each neighbor v of u:           // where v is still in Q.
//              alt ← dist[u] + length(u, v)
//              if alt < dist[v]:               // A shorter path to v has been found
//                  dist[v] ← alt
//                  prev[v] ← u
//      return dist[], prev[]

// dijkstra(Graph, source):
// 1. for each vertex V in G //
// 2.     dist[V] ← INFINITY
// 3.     prev[V] ← UNDEFINED
// 4.     add V to Q
// 5. dist[source] ← 0
// 6. while Q is not empty
// 7.     u ← vertex in Q with min dist[u]
// 8.     remove u from Q
// 9.     for each neighbor v of u
// 10.        alt ← dist[u] + length(u, v)
// 11.        if alt < dist[v]
// 12.            dist[v] ← alt
// 13.            prev[v] ← u
// 14. return dist[], prev[]

// dijkstra(Graph, source):
// 1. Initialize all vertices with INFINITY distance and UNDEFINED previous node
// 2. Set distance of source vertex to 0
// 3. Add all vertices to the priority queue
// 4. While priority queue is not empty
// 5.     Get the vertex with the minimum distance from the priority queue
// 6.     For each neighbor of the vertex
// 7.         If the distance to the neighbor is greater than the distance to the vertex + the weight of the edge
// 8.             Update the distance to the neighbor
// 9.             Update the previous node of the neighbor
// 10.            Update the priority queue
// 11. Return the distance and previous node arrays

// 3 Correct Input:
// first:
//   0 4 0 0 0 0 0 8 0
//   4 0 8 0 0 0 0 11 0
//   0 8 0 7 0 4 0 0 2
//   0 0 7 0 9 14 0 0 0
//   0 0 0 9 0 10 0 0 0
//   0 0 4 14 10 0 2 0 0
//   0 0 0 0 0 2 0 1 6
//   8 11 0 0 0 0 1 0 7
//   0 0 2 0 0 0 6 7 0

// second input:
//  0 4 0 0 0 0 0 8 0
//  4 0 8 0 0 0 0 6 0
//  0 8 0 7 0 4 0 0 2

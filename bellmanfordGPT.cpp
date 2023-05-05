#include <iostream>
#include <vector>

using namespace std;

// structure to represent an edge
struct Edge {
    int source, destination, weight;
    Edge(int s, int d, int w) {
        source = s;
        destination = d;
        weight = w;
    }
};

// function to print the distance vector
void printDistances(vector<int>& distances) {
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 1; i <= distances.size(); ++i) {
        cout << i << "\t" << distances[i] << endl;
    }
}

// Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int numVertices, int source, int destination) {
    // initialize the distance vector
    vector<int> distances(numVertices + 1, INT_MAX);
    distances[source] = 0;
    
    // iterate over all vertices
    for (int i = 1; i <= numVertices; ++i) {
        // iterate over all edges
        for (int j=0;j<edges.size();j++) {
        	Edge edge = edges[j];
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
            }
        }
    }
    
    // check for negative-weight cycles
    for (int j=0;j<edges.size();j++) {
    	Edge edge = edges[j];
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;
        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            cout << "Graph contains negative-weight cycle" << endl;
            return;
        }
    }
    
    // print the distance vector
    printDistances(distances);
    
    // print the shortest path from source to destination
    if (distances[destination] == INT_MAX) {
        cout << "There is no path from " << source << " to " << destination << endl;
    } else {
        cout << "Shortest path from " << source << " to " << destination << ": " << distances[destination] << endl;
    }
}

// main function
int main() {
    // create a sample graph
    vector<Edge> edges ;
    edges.push_back(Edge(1, 2, 4));
    edges.push_back(Edge(1, 3, 3));
    edges.push_back(Edge(2, 3, -2));
    edges.push_back(Edge(2, 4, 2));
    edges.push_back(Edge(2, 5, 1));
    edges.push_back(Edge(4, 3, 5));
    edges.push_back(Edge(4, 2, 1));
    edges.push_back(Edge(5, 4, -3));
    int numVertices = 5;
    int source = 1;
    int destination = 5;
    
    // run the Bellman-Ford algorithm
    bellmanFord(edges, numVertices, source, destination);
    
    return 0;
}


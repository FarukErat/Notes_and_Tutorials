#include <iostream>
#include "graph.hpp"

using namespace std;

int main() {
    Graph<int> g(false, false);

    g.addNode("A", 1);
    g.addNode("B", 2);
    g.addNode("C", 3);
    g.addNode("D", 4);

    g.addEdge("A", "B", 1);
    g.addEdge("B", "C", 2);
    g.addEdge("C", "D", 3);
    g.addEdge("D", "A", 4);

    cout << "Number of nodes: " << g.size() << endl;
    cout << "Number of edges: " << g.numEdges() << endl;
    cout << "Is connected: " << g.isConnected() << endl;
    cout << "Density: " << g.density() << endl;
    cout << "Clustering coefficient: " << g.clustering() << endl;

    return 0;
}

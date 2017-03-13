#include <iostream>
#include <vector>

#include "graph.h"
#include "types.h"


using namespace std;


int main() {
    /**
    * Input format:
    *
    * An unigned integer n that represents the number of vertices.
    * Then n lines with the tags/labels for each vertex (String)
    * Following by n^2 unsigned integers that represents the adjacency matrix
    **/
    uint verticesNumber;
    cin >> verticesNumber;

    // Read graph's vertices tags/labels
    Labels labels(verticesNumber);
    for (uint i = 0; i < verticesNumber; i++) {
        cin >> labels[i];
    }

    // Read distances between vertices
    uint distancesNumber = verticesNumber * verticesNumber;
    Distances distances(distancesNumber);
    for (uint i = 0; i < distancesNumber; i++) {
        cin >> distances[i];
    }

    Graph graph(labels, distances);
    cout << "Simple link\n";
    cout << graph.simpleEdgeNewickTree();
    cout << endl << endl;
    cout << "Complete link\n";
    cout << graph.completeEdgeNewickTree();
    cout << endl << endl;
    cout << "Average link\n";
    cout << graph.averageEdgeNewickTree();
    cout << endl << endl;

    return 0;
}

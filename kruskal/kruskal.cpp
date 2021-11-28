/**********
*
* Fernando de Jesús Soto
*
***********/


#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>


/***** TYPES *****/

typedef unsigned int uint;

typedef uint Vertex;
typedef std::vector<Vertex> Vertices;

typedef struct {
    Vertex a;
    Vertex b;
    uint weight;
} Edge;
typedef std::vector<Edge> Edges;

struct compare {
    // > = Minimum spanning tree
    // < = Maximum spanning tree
    bool operator()(const Edge &a, const Edge &b) {
        return a.weight > b.weight;
    }
};

typedef std::priority_queue<Edge, Edges, compare> SortedEdges;

/*****************/


/*****************/

Vertices parents;
Edges spanningTree;

/*****************/


//** DISJOINT SET UNION FIND


Vertex findSet(Vertex vertex) {
    if (parents[vertex] != vertex)
       parents[vertex] = findSet(parents[vertex]);
    return vertex;
}

bool unionSet(Edge edge) {
    Vertex aSet = findSet(edge.a);
    Vertex bSet = findSet(edge.b);

    // Both vertex are in the same set
    if (aSet == bSet) return false;

    // Vertices belongs to different sets, join it
    parents[bSet] = aSet;
    return true;
}


//** HELPER METHODS


void printEdge(Edge edge) {
    std::cout << edge.a << " " << edge.b << " " << edge.weight << std::endl;
}


//** MAIN

int main() {
    uint verticesNumber;
    uint edgesNumber;

    // Read vertices and edges number
    std::cin >> verticesNumber >> edgesNumber;

    // Create parents' vector
    parents.resize(verticesNumber);
    for(uint i = 0; i < verticesNumber; i++) {
        parents[i] = i;
    }

    // Read and sort all of the edges
    SortedEdges sortedEdges;
    for (uint i = 0; i < edgesNumber; i++) {
        Edge edge = Edge();
        std::cin >> edge.a >> edge.b >> edge.weight;
        sortedEdges.push(edge);
    }

    uint spanningTreeWeight = 0;
    while(spanningTree.size() < verticesNumber - 1 && !sortedEdges.empty()) {
        Edge edge = sortedEdges.top();

        if (unionSet(edge)) {
            printEdge(edge);
            spanningTree.push_back(edge);
            spanningTreeWeight += edge.weight;
        }
        sortedEdges.pop();
    }

    std::cout << spanningTreeWeight << std::endl << std::endl;

    return 0;
}

/***** TEST CASE *****/
// 6 8 0 3 1 0 1 4 0 5 4 1 2 4 1 4 8 2 3 4 2 5 7 3 4 4 5 6 4
/*********************/

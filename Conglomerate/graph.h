#include <functional>
#include <string>
#include <tuple>
#include <unordered_map>

#include "types.h"


#ifndef GRAPH_H
#define GRAPH_H


/***** TYPES *****/


// f:Position -> Label
typedef std::unordered_map<uint, std::string> Index;
// (y, x, value)
typedef std::tuple<uint, uint, Distance> Edge;

// f:Distance, Distance -> Distance
typedef std::function<Distance(Distance, Distance)> CompareFunc;


/*****************/


class Graph {
public:

    /**
    * labels is an array of strings with the labels for the vertices of the graph.
    * distances is an adyacency matrix represented as an unidimentional vector of unsigned integers.
    **/
    Graph(Labels labels, Distances distances);
    ~Graph();

    std::string simpleEdgeNewickTree();
    std::string completeEdgeNewickTree();
    std::string averageEdgeNewickTree();


private:
    uint verticesNumber;    // Graph's vertices number
    Index labelIndex;       // Position:Unsigned Int -> Label:String
    Distances distances;    // Adjacency matrix


    //** FUNCTIONS


    std::string newickTree(Distances distances, Index labelIndex, uint verticesNumber, CompareFunc compareFunc);

    void merge(Distances *distances, Index *labelIndex, Edge edge, uint *verticesNumber, CompareFunc compareFunc);
    Edge coordinateToEdge(uint x, uint y);
    Edge minEdge(Edge a, Edge b);
    Edge edgeWithMinimumValue(Distances distances, uint verticesNumber);

    Distance coordinateToDistance(uint x, uint y);
    std::string coordinateToFormatedDistance(uint x, uint y);
    std::string formatDistance(Distance distance);

    std::string distanceToString(Distance distance);

     //** DEBUG

    void printLabelIndex();
    void printMatrix();

};


#endif

#include <algorithm>
#include <iostream>

#include "graph.h"


Graph::Graph() {

}

Graph::Graph(Labels labels, Distances distances) {
    this->verticesNumber = labels.size();

    // Create adjacency matriz
    this->distances = distances;

    // Create label index
    for (uint i = 0; i < verticesNumber; i++) {
        labelIndex[i] = labels[i];
    }
}

Graph::~Graph() {

}


//** PUBLIC


std::string Graph::simpleEdgeNewickTree() {
    return newickTree(this->distances, this->labelIndex, [](Distance a, Distance b) -> Distance {
        return std::min(a, b);
    });
}

std::string Graph::completeEdgeNewickTree() {
    return newickTree(this->distances, this->labelIndex, [](Distance a, Distance b) -> Distance {
        return std::max(a, b);
    });
}

std::string Graph::averageEdgeNewickTree() {
    return newickTree(this->distances, this->labelIndex, [](Distance a, Distance b) -> Distance {
        return (a + b) / 2;
    });
}


//** PRIVATE


Edge Graph::edgeWithMinimumValue() {
    return std::tuple<uint, uint, uint>();
}

std::string Graph::newickTree(Distances distances, Index labelIndex, CompareFunc function) {

    return std::string();
}

Distance Graph::coordinateToDistance(uint y, uint x) {
    return this->distances[y * this->verticesNumber + x];
}

std::string Graph::coordinateToFormatedDistance(uint y, uint x) {
    return formatDistance(coordinateToDistance(y, x));
}

std::string Graph::formatDistance(Distance distance) {
    // Positive integer numbers with format /^[0-9]{3}$/
    return ((distance < 10) ? "00" : (distance < 100) ? "0" : "") + std::to_string(distance);
}


//** DEBUG


void Graph::printLabelIndex() {
    for (auto &label : labelIndex) {
        std::cout << label.first <<": " << label.second << std::endl;
    }
}

void Graph::printMatrix() {
    for(uint i = 0; i < this->verticesNumber; i++) {
        std::cout << "| ";

        for(uint j = 0; j < this->verticesNumber; i++) {
            std::string formatedDistance = coordinateToFormatedDistance(i, j);
            std::cout << formatedDistance << " | ";
        }
        std::cout << std::endl;
    }
}

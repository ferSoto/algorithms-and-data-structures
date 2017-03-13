#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "graph.h"


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
    return newickTree([](Distance a, Distance b) -> Distance {
        return std::min(a, b);
    });
}

std::string Graph::completeEdgeNewickTree() {
    return newickTree([](Distance a, Distance b) -> Distance {
        return std::max(a, b);
    });
}

std::string Graph::averageEdgeNewickTree() {
    return newickTree([](Distance a, Distance b) -> Distance {
        return (a + b) / 2;
    });
}


//** PRIVATE


std::string Graph::newickTree(CompareFunc compareFunc) {
    Distances distancesBackup = this->distances;
    Index labelIndexBackup = this->labelIndex;
    uint verticesNumberBackup = this->verticesNumber;

    while (this->verticesNumber > 1) {
        auto minimumEdge = edgeWithMinimumValue();
        merge(minimumEdge, compareFunc);
    }
    std::string _newickTree = "(" + labelIndex[0] + ")";

    // Reset class properties
    this->distances = distancesBackup;
    this->labelIndex = labelIndexBackup;
    this->verticesNumber = verticesNumberBackup;

    return _newickTree;
}

void Graph::merge(Edge edge, CompareFunc compareFunc) {
    // Get egde's components
    Distance distance = std::get<2>(edge);
    uint firstPosition = std::min(std::get<0>(edge), std::get<1>(edge));
    uint secondPosition = std::max(std::get<0>(edge), std::get<1>(edge));

    uint width = this->verticesNumber - 1;

    // Update label index

    // Create new label and set it on first position
    std::string firstLabel = this->labelIndex.at(firstPosition);
    std::string secondLabel = this->labelIndex.at(secondPosition);
    std::string newLabel = "(" + firstLabel + ", " + secondLabel + "):" + distanceToString(distance);
    this->labelIndex.at(firstPosition) = newLabel;

    // Since all the position who change in the label index are the ones with a bigger index than
    // the position of the second node, just update them
    for (uint i = secondPosition; i < width; i++) {
        this->labelIndex.at(i) = this->labelIndex.at(i + 1);
    }
    // The last position will not exists anymore, delete it
    this->labelIndex.erase(width);

    // Update adjacency matrix

    // Create a new updated adjacency matrix
    Distances newMatrix(width * width, 0);
    for (uint i = 0; i < width - 1; i++) {
        for (uint j = i + 1; j < width; j++) {
            Distance distance;

            if (i < firstPosition && j < firstPosition) {
                // This positions of the matrix dont change
                distance = coordinateToDistance(i, j);

            } else {
                uint x = (j < secondPosition) ? j : j + 1;

                if (i == firstPosition) {
                    Distance distance1 = coordinateToDistance(x, firstPosition);
                    Distance distance2 = coordinateToDistance(x, secondPosition);
                    distance = compareFunc(distance1, distance2);

                } else {
                    uint y = (i < secondPosition) ? i : i + 1;
                    distance = coordinateToDistance(y, x);
                }
            }

            newMatrix[i * width + j] = distance;
            newMatrix[j * width + i] = distance;
        }
    }

    // Replace adjacency matrix and update vertices number
    this->verticesNumber--;
    this->distances = newMatrix;
}

Edge Graph::coordinateToEdge(uint y, uint x) {
    return std::make_tuple(y, x, coordinateToDistance(y, x));
}

Edge Graph::minEdge(Edge a, Edge b) {
    // Compare just the value of the edge
    return (std::get<2>(a) < std::get<2>(b)) ? a : b;
}

Edge Graph::edgeWithMinimumValue() {
    Edge minimumEdge = coordinateToEdge(0, 1);
    for (uint i = 0; i < this->verticesNumber - 1; i++) {
        for (uint j = i + 1; j < this->verticesNumber; j++) {
            minimumEdge = minEdge(minimumEdge, coordinateToEdge(i, j));
        }
    }
    return minimumEdge;
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

std::string Graph::distanceToString(Distance distance) {
    std::ostringstream stringStream;
    stringStream << std::setfill('0') << std::setw(4) << distance;
    return stringStream.str();
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

void Graph::printEdge(Edge e) {
    std::cout << "---------\n";
    std::cout << std::get<0>(e) << " | " << std::get<1>(e) << " | " << std::get<2>(e) << std::endl;
    std::cout << "---------\n\n";
}

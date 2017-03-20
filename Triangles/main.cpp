/****
*
*  Find all the triangles of a graph using DFS.
*
*****
*
*  Authors:
*    Cynthia Alexis Allende Pascual
*    Javier Alonso Chávez Hernández
*    Jorge Carlos González González
*    Fernando de Jesús Soto
*
*****/


#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>


using namespace std;


/***** TYPES ****/

typedef unsigned int uint;
typedef vector<uint> UintVector;
typedef vector<UintVector> IntegerMatrix;

typedef vector<bool> BooleanVector;

typedef tuple<uint, uint, uint> Triangle;
typedef set<Triangle> TriangleSet;

/****************/


/***** GLOBAL *****/

uint verticesNumber;
IntegerMatrix graph;

TriangleSet triangleSet;
BooleanVector visited;

UintVector path(3);

/******************/


IntegerMatrix transformToIntegerMatrix(BooleanVector booleanVector, uint verticesNumber) {
    IntegerMatrix matrix(verticesNumber);

    for (uint i = 0; i < verticesNumber; i++) {
        for (uint j = 0; j < verticesNumber; j++) {
            if (booleanVector[i * verticesNumber + j]) {
                matrix[i].push_back(j);
            }
        }
    }

    return matrix;
}

void saveTriangle() {
    UintVector sortedPath(path);
    sort(sortedPath.begin(), sortedPath.end());

    triangleSet.insert((Triangle){sortedPath[0], sortedPath[1], sortedPath[2]});
}

bool isNeighbor(uint vertex, uint neighbor) {
    for (auto i : graph[vertex]) {
        if (i == neighbor) {
            return true;
        }
    }

    return false;
}

void dfs(uint vertex, uint level, uint initialVertex) {
    visited[vertex] = true;
    path[level] = vertex;

    if (level == 2) {
        if (isNeighbor(vertex, initialVertex)) saveTriangle();

    } else {
        for (auto n : graph[vertex]) {
            if (!visited[n]) dfs(n, level + 1, initialVertex);
        }
    }

    visited[vertex] = false;
}

void findTrianglesForVertex(uint vertex) {
    dfs(vertex, 0, vertex);
}

void printTriangle(Triangle triangle) {
    cout << get<0>(triangle) << " -> ";
    cout << get<1>(triangle) << " -> ";
    cout << get<2>(triangle) << endl;
}


int main() {
    cin >> verticesNumber;

    uint matrixLength = verticesNumber * verticesNumber;
    BooleanVector booleanVector(matrixLength);

    for (uint i = 0; i < matrixLength; i++) {
        bool boolValue;
        cin >> boolValue;
        booleanVector[i] = boolValue;
    }

    graph = transformToIntegerMatrix(booleanVector, verticesNumber);

    // Find triangles
    visited.resize(verticesNumber);
    for (uint i = 0; i < verticesNumber; i++) {
        findTrianglesForVertex(i);
    }

    for (auto triangle : triangleSet) {
        printTriangle(triangle);
    }

    return 0;
}

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


/**
* Transform binary matrix to a vector of neighbors
*
* Example:
*     0 1 0 1       0: 1, 3
*     1 0 1 0  =>   1: 0, 2
*     0 1 0 1       2: 1, 3
*     1 0 1 0       3: 0, 2
**/
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

/**
* Try to insert the sorted vertices into "path" in the set.
**/
void tryAndSaveTriangle() {
    // Create a copy of "path" and sort it.
    UintVector sortedPath(path);
    sort(sortedPath.begin(), sortedPath.end());

    // The set accepts only unique elements
    triangleSet.insert((Triangle){sortedPath[0], sortedPath[1], sortedPath[2]});
}

/**
* Check if two vertices are adjacent
**/
bool isNeighbor(uint vertex, uint neighbor) {
    for (auto i : graph[vertex]) {
        if (i == neighbor) {
            return true;
        }
    }

    return false;
}

/**
* Depth first search to find all the triangules
**/
void dfs(uint vertex, uint level, uint initialVertex) {
    // Mark vertex as visited, temporally. And update "path" variable
    visited[vertex] = true;
    path[level] = vertex;

    if (level == 2) {
        // This is the third vertex visited, check if the three vertices are a triangle
        if (isNeighbor(vertex, initialVertex)) tryAndSaveTriangle();

    } else {
        for (auto n : graph[vertex]) {
            if (!visited[n]) dfs(n, level + 1, initialVertex);
        }
    }

    // Unmark vertex as visited because it may be part of another triangle
    visited[vertex] = false;
}

/**
* Just to make easier the code reading
**/
void findTrianglesForVertex(uint vertex) {
    dfs(vertex, 0, vertex);
}

/**
* Print triangle with format: V1 -> V2 -> V3
**/
void printTriangle(Triangle triangle) {
    cout << get<0>(triangle) << " -> ";
    cout << get<1>(triangle) << " -> ";
    cout << get<2>(triangle) << endl;
}


int main() {

    cin >> verticesNumber;

    uint matrixLength = verticesNumber * verticesNumber;
    // The adjacency matrix is stored as a nxn length vector
    BooleanVector booleanVector(matrixLength);

    // Read matrix
    for (uint i = 0; i < matrixLength; i++) {
        bool boolValue;
        cin >> boolValue;
        booleanVector[i] = boolValue;
    }

    // Tranform the adyacency matrix to a more usable format
    graph = transformToIntegerMatrix(booleanVector, verticesNumber);

    // Find triangles for each vertex
    visited.resize(verticesNumber);
    for (uint i = 0; i < verticesNumber; i++) {
        findTrianglesForVertex(i);
    }

    // Print all found triangles
    for (auto triangle : triangleSet) {
        printTriangle(triangle);
    }

    return 0;
}

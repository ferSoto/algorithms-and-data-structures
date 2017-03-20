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


#include <iostream>
#include <vector>


using namespace std;


/***** TYPES ****/

typedef unsigned int uint;
typedef vector<bool> BooleanMatrix;
typedef vector<vector<uint>> IntegerMatrix;

/****************/


/***** GLOBAL *****/

uint verticesNumber;
IntegerMatrix graph;

/******************/

IntegerMatrix transformToIntegerMatrix(BooleanMatrix booleanMatrix, uint verticesNumber) {
    IntegerMatrix matrix(verticesNumber);

    for (uint i = 0; i < verticesNumber; i++) {
        for (uint j = 0; j < verticesNumber; j++) {
            if (booleanMatrix[i * verticesNumber + j]) {
                matrix[i].push_back(j);
            }
        }
    }

    return matrix;
}


int main() {
    cin >> verticesNumber;

    uint matrixLength = verticesNumber * verticesNumber;
    BooleanMatrix booleanMatrix(matrixLength);

    for (uint i = 0; i < matrixLength; i++) {
        bool boolValue;
        cin >> boolValue;
        booleanMatrix[i] = boolValue;
    }

    graph = transformToIntegerMatrix(booleanMatrix, verticesNumber);


    return 0;
}

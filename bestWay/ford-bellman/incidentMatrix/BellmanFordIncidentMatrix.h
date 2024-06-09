//
// Created by Kuba on 05/06/2024.
//

#ifndef AIZO2_BELLMANFORDINCIDENTMATRIX_H
#define AIZO2_BELLMANFORDINCIDENTMATRIX_H
#include <vector>
#include <iostream>

using namespace std;

class BellmanFordIncidentMatrix {
    vector<vector<int> > matrix;
public:
    BellmanFordIncidentMatrix(vector<vector<int> > matrix){
        this -> matrix = matrix;
    }
    void testBellman();
    void testSimpleBellman(int startNode);
};


#endif //AIZO2_BELLMANFORDINCIDENTMATRIX_H

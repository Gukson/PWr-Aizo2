//
// Created by Kuba on 05/06/2024.
//

#ifndef AIZO2_DJIKSTRAINCIDENTMATRIX_H
#define AIZO2_DJIKSTRAINCIDENTMATRIX_H

#include <vector>
#include <iostream>

using namespace std;

class DjikstraIncidentMatrix {
    vector<vector<int> > matrix;
public:
    DjikstraIncidentMatrix(vector<vector<int> > matrix){
        this -> matrix = matrix;
    }
    void testDjikstra();
    void testSimpleDjikstra(int startNode);

};


#endif //AIZO2_DJIKSTRAINCIDENTMATRIX_H

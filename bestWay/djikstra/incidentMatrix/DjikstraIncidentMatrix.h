//
// Created by Kuba on 05/06/2024.
//

#ifndef AIZO2_DJIKSTRAINCIDENTMATRIX_H
#define AIZO2_DJIKSTRAINCIDENTMATRIX_H

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class DjikstraIncidentMatrix {
    vector<vector<int> > matrix;
public:
    DjikstraIncidentMatrix(vector<vector<int> > matrix){
        this -> matrix = matrix;
    }
    vector<vector<int>> testDjikstra();
    vector<int> testSimpleDjikstra(int startNode);

};


#endif //AIZO2_DJIKSTRAINCIDENTMATRIX_H

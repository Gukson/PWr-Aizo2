//
// Created by Kuba on 01/06/2024.
//

#ifndef AIZO2_KRUSKALNEIGHBORHOODMATRIX_H
#define AIZO2_KRUSKALNEIGHBORHOODMATRIX_H

#include <iostream>
#include <vector>
#include "../kruskal/Kruskal.h"
#include "../../../graf/neighborhoodList/Node/Node.h"

using namespace std;

class KruskalNeighborhoodMatrix: public Kruskal{
    vector<vector<Node> > matrix;
    vector<pair<int,int>> edgesVector;
public:
    KruskalNeighborhoodMatrix(vector<vector<Node> > matrix){
        this -> matrix = std::move(matrix);
        createOrder();
    }
    void createOrder();
    virtual vector<int> getBestEdge(int index);
    virtual int getEdgesAmount();
};


#endif //AIZO2_KRUSKALNEIGHBORHOODMATRIX_H

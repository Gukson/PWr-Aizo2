
#ifndef AIZO2_KRUSKALINCIDENTMATRIX_H
#define AIZO2_KRUSKALINCIDENTMATRIX_H

#include <iostream>
#include <utility>
#include "../kruskal/Kruskal.h"

using namespace std;

class KruskalIncidentMatrix: public Kruskal{
    vector<vector<int> > matrix;
    vector<int> order;
public:
    KruskalIncidentMatrix(vector<vector<int> > matrix){
        this -> matrix = std::move(matrix);
        createOrder();
    }
    void createOrder();
    virtual vector<int> getBestEdge(int index);
    virtual int getEdgesAmount();

};


#endif //AIZO2_KRUSKALINCIDENTMATRIX_H

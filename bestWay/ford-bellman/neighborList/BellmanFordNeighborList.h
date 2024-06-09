//
// Created by Kuba on 05/06/2024.
//

#ifndef AIZO2_BELLMANFORDNEIGHBORLIST_H
#define AIZO2_BELLMANFORDNEIGHBORLIST_H

#include <vector>
#include <iostream>
#include "../../../graf/neighborhoodList/Node/Node.h"

using namespace std;


class BellmanFordNeighborList {
    vector<vector<Node> > matrix;
public:
    BellmanFordNeighborList(vector<vector<Node> > matrix){
        this -> matrix = matrix;
    }
    void testBellman();
    void testSimpleBellman(int startNode);
};


#endif //AIZO2_BELLMANFORDNEIGHBORLIST_H

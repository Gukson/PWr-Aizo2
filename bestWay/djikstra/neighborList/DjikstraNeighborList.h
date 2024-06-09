//
// Created by Kuba on 03/06/2024.
//

#ifndef AIZO2_DJIKSTRANEIGHBORLIST_H
#define AIZO2_DJIKSTRANEIGHBORLIST_H

#include <vector>
#include <iostream>
#include "../../../graf/neighborhoodList/Node/Node.h"

using namespace std;

class DjikstraNeighborList {
    vector<vector<Node> > matrix;
public:
    DjikstraNeighborList(vector<vector<Node> > matrix){
        this -> matrix = matrix;
    }
    void testDjikstra();
    void testSimpleDjikstra(int startNode);
};


#endif //AIZO2_DJIKSTRANEIGHBORLIST_H

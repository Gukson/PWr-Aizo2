//
// Created by Kuba on 31/05/2024.
//

#ifndef AIZO2_MSTNEIGHBORHOODLISTPRIMALGORITHM_H
#define AIZO2_MSTNEIGHBORHOODLISTPRIMALGORITHM_H

#include <vector>
#include <iostream>
#include "../../../graf/neighborhoodList/Node/Node.h"

using namespace std;


class MstNeighborhoodListPrimAlgorithm {
public:
    void findMST(vector<vector<Node> > matrix);
private:
    vector<int> findBestAvailableWay(vector<bool> visited_boolean, vector<vector<Node>> matrix);
};


#endif //AIZO2_MSTNEIGHBORHOODLISTPRIMALGORITHM_H

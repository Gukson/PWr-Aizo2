//
// Created by Kuba on 05/05/2024.
//

#ifndef AIZO2_MSTNEIGHBOURS_H
#define AIZO2_MSTNEIGHBOURS_H
#include <vector>
#include <set>
#include "../Node/Node.h"

using namespace std;


class MSTNeighbours {
public:
    void findMST(vector<vector<Node> > matrix);
private:
    vector<int> findAllAvailableWaysToGO(vector<bool> visited, vector<vector<Node>> matrix);
    bool checkAreAllVisited(vector<bool> visited);
    vector<int> findAllAvailableNodes(vector<bool> visited, vector<vector<Node> > matrix);

};


#endif //AIZO2_MSTNEIGHBOURS_H

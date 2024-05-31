//
// Created by Kuba on 30/04/2024.
//

#ifndef AIZO2_NEIGHBORHOODLIST_H
#define AIZO2_NEIGHBORHOODLIST_H

#include <vector>
#include "./Node/Node.h"

using namespace std;

class NeighborhoodList {

public:
    vector<vector<Node> > matrix;
    vector<vector<Node> > load(string filename,bool directed);
private:
    static vector<int> stringSpliter(string line);
};


#endif //AIZO2_NEIGHBORHOODLIST_H

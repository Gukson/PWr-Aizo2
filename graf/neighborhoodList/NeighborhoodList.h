//
// Created by Kuba on 30/04/2024.
//

#ifndef AIZO2_NEIGHBORHOODLIST_H
#define AIZO2_NEIGHBORHOODLIST_H

#include <vector>
#include "./Node/Node.h"
#include "../../data/generator/Generator.h"

using namespace std;

class NeighborhoodList {

public:
    vector<vector<Node> > matrix;
    vector<vector<Node> > load(string filename,bool directed);
    vector<vector<Node> > loadFromGenerator(Generator generator, bool directed);
private:
    static vector<int> stringSpliter(string line);
    bool containsNode(const vector<Node>& n, int to);
};


#endif //AIZO2_NEIGHBORHOODLIST_H

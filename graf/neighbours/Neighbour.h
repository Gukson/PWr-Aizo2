//
// Created by Kuba on 30/04/2024.
//

#ifndef AIZO2_NEIGHBOUR_H
#define AIZO2_NEIGHBOUR_H

#include <vector>
#include "./Node/Node.h"

using namespace std;

class Neighbour {

public:
    vector<vector<Node> > matrix;
    vector<vector<Node> >  load(string filename);
private:
    vector<int> stringSpliter(string line);
};


#endif //AIZO2_NEIGHBOUR_H

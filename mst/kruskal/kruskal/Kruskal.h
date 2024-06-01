//
// Created by Kuba on 01/06/2024.
//

#ifndef AIZO2_KRUSKAL_H
#define AIZO2_KRUSKAL_H

#include <iostream>
#include <vector>
#include "../unionFind/UnionFind.h"

using namespace std;

class Kruskal {
public:
    virtual ~Kruskal() {}
    virtual vector<int> getBestEdge(int index) = 0;
    virtual int getEdgesAmount() = 0;
    int kruskal(int n);
};


#endif //AIZO2_KRUSKAL_H

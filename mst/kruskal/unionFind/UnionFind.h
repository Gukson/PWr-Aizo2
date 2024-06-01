//
// Created by Kuba on 01/06/2024.
//

#ifndef AIZO2_UNIONFIND_H
#define AIZO2_UNIONFIND_H

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int u);
    void unite(int u, int v);
};


#endif //AIZO2_UNIONFIND_H

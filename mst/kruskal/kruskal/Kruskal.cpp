//
// Created by Kuba on 01/06/2024.
//

#include "Kruskal.h"

int Kruskal::kruskal(int n) {
    UnionFind uf(n);
    int mst_weight = 0;

    int e = 0;
    while(e < getEdgesAmount()){
        vector<int> r = getBestEdge(e);
        if (uf.find(r[0]) != uf.find(r[1])) {
            uf.unite(r[1], r[0]);
            mst_weight += r[2];
//            cout << r[0] << " -> " << r[1] << endl;
        }
        e++;
    }
    return mst_weight;
}

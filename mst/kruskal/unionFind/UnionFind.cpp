//
// Created by Kuba on 01/06/2024.
//

#include "UnionFind.h"

int UnionFind::find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]); // Path compression
    return parent[u];
}

void UnionFind::unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}
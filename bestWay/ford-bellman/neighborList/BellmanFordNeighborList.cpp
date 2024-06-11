//
// Created by Kuba on 05/06/2024.
//

#include "BellmanFordNeighborList.h"

vector<int> BellmanFordNeighborList::testSimpleBellman(int startNode) {
    int numVertices = matrix.size();
    vector<int> distances(numVertices, numeric_limits<int>::max());
    distances[startNode] = 0;

    // Relaksacja krawędzi
    for (int i = 0; i < numVertices - 1; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (Node& neighbor : matrix[u]) {
                int v = neighbor.get_value();
                int weight = neighbor.get_weight();
                if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }
    }
    return distances;
}

vector<vector<int>> BellmanFordNeighborList::testBellman() {
    vector<vector<int> > results = vector<vector<int>>();
    for(int x = 0; x < matrix[0].size(); x++){
        results.push_back(testSimpleBellman(x));
    }
    return results;
}

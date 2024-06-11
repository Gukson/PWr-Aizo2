//
// Created by Kuba on 05/06/2024.
//

#include "BellmanFordIncidentMatrix.h"


vector<int> BellmanFordIncidentMatrix::testSimpleBellman(int startNode) {
    int numVertices = matrix.size();
    int numEdges = matrix[0].size();
    vector<int> distances(numVertices, numeric_limits<int>::max());
    distances[startNode] = 0;

    // Relaksacja krawędzi
    for (int i = 0; i < numVertices - 1; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (int j = 0; j < numEdges; ++j) {
                int v = -1, weight = 0;

                // Znajdź wierzchołki połączone krawędzią j
                for (int k = 0; k < numVertices; ++k) {
                    if (matrix[k][j] != 0) {
                        if (v == -1) {
                            v = k;
                            weight = matrix[k][j];
                        } else {
                            v = -1; // więcej niż 1 krawędź wychodząca z u
                            break;
                        }
                    }
                }

                if (v != -1 && distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }
    }
    return distances;
}

vector<vector<int>> BellmanFordIncidentMatrix::testBellman() {
    vector<vector<int> > results = vector<vector<int>>();
    for(int x = 0; x < matrix[0].size(); x++){
        results.push_back(testSimpleBellman(x));
    }
    return results;
}

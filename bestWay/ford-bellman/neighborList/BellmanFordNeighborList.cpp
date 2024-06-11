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
        bool anyChanges = false;
        for (int u = 0; u < numVertices; ++u) {
            for (Node& neighbor : matrix[u]) {
                int v = neighbor.get_value();
                int weight = neighbor.get_weight();
                if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    anyChanges = true;
                }
            }
        }
        // Jeśli żadna odległość się nie zmieniła, zakończ wcześniej
        if (!anyChanges) {
            break;
        }
    }

    // Sprawdzenie cykli o ujemnej wadze
    for (int u = 0; u < numVertices; ++u) {
        for (Node& neighbor : matrix[u]) {
            int v = neighbor.get_value();
            int weight = neighbor.get_weight();
            if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                // Wykryto cykl ujemny
                cout << "Graph contains a negative-weight cycle" << endl;
                return {};
            }
        }
    }

    return distances;
}

vector<vector<int>> BellmanFordNeighborList::testBellman() {
    vector<vector<int>> results(matrix.size());
    for (int x = 0; x < matrix.size(); x++) {
        results[x] = testSimpleBellman(x);
    }
    return results;
}


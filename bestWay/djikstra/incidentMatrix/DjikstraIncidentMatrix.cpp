//
// Created by Kuba on 05/06/2024.
//

#include "DjikstraIncidentMatrix.h"

vector<int> DjikstraIncidentMatrix::testSimpleDjikstra(int startNode) {
    int numVertices = matrix.size();
    int numEdges = matrix[0].size();
    vector<int> distances(numVertices, numeric_limits<int>::max());
    distances[startNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int currentVertex = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        if (currentDistance > distances[currentVertex]) {
            continue;
        }

        for (int j = 0; j < numEdges; ++j) {
            int u = -1, v = -1;

            // Znajdź wierzchołki połączone krawędzią j
            for (int i = 0; i < numVertices; ++i) {
                if (matrix[i][j] != 0) {
                    if (u == -1) {
                        u = i;
                    } else {
                        v = i;
                    }
                }
            }

            if (u != -1 && v != -1) {
                int weight = abs(matrix[u][j]); // Zakładamy, że waga jest wartością bezwzględną
                if (u == currentVertex || v == currentVertex) {
                    int neighbor = (u == currentVertex) ? v : u;
                    int newDist = currentDistance + weight;
                    if (newDist < distances[neighbor]) {
                        distances[neighbor] = newDist;
                        pq.push({newDist, neighbor});
                    }
                }
            }
        }
    }
    return distances;
}

vector<vector<int>> DjikstraIncidentMatrix::testDjikstra() {
    vector<vector<int> > results = vector<vector<int>>();
    for(int x = 0; x < matrix[0].size(); x++){
        results.push_back(testSimpleDjikstra(x));
    }
    return results;
}

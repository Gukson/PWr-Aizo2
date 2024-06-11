//
// Created by Kuba on 03/06/2024.
//

#include "DjikstraNeighborList.h"

vector<int> DjikstraNeighborList::testSimpleDjikstra(int startNode) {
    int numVertices = matrix.size();
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

        for (Node neighbor : matrix[currentVertex]) {
            int neighborVertex = neighbor.get_value();
            int weight = neighbor.get_weight();
            int newDist = currentDistance + weight;
            if (newDist < distances[neighborVertex]) {
                distances[neighborVertex] = newDist;
                pq.push({newDist, neighborVertex});
            }
        }
    }
    return distances;
}

vector<vector<int>> DjikstraNeighborList::testDjikstra() {
    vector<vector<int> > results = vector<vector<int>>();
    for(int x = 0; x < matrix[0].size(); x++){
        results.push_back(testSimpleDjikstra(x));
    }
    return results;
}

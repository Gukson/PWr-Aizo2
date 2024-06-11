//
// Created by Kuba on 02/05/2024.
//

#include "MstIncidentMatrixPrimAlgorithm.h"

using namespace std;

void MstIncidentMatrixPrimAlgorithm::findMST(vector<vector<int>> matrix) {
    int numVertices = matrix.size();
    int numEdges = matrix[0].size();
    vector<bool> visited(numVertices, false);
    vector<pair<int, int>> mst; // Krawędzie minimalnego drzewa rozpinającego

    // Rozpocznij od pierwszego wierzchołka
    visited[0] = true;

    // Powtarzaj, dopóki wszystkie wierzchołki nie zostaną odwiedzone
    while (mst.size() < numVertices - 1) {
        int minWeight = numeric_limits<int>::max();
        int minSrc, minDest;

        // Przejrzyj wszystkie krawędzie
        for (int j = 0; j < numEdges; ++j) {
            int src = -1, dest = -1;
            bool found = false;

            // Znajdź wierzchołki połączone krawędzią j
            for (int i = 0; i < numVertices; ++i) {
                if (matrix[i][j] != 0) {
                    if (src == -1) {
                        src = i;
                    } else {
                        dest = i;
                        found = true;
                        break;
                    }
                }
            }

            // Sprawdź, czy krawędź należy do minimalnego drzewa rozpinającego i czy ma najmniejszą wagę
            if (found && ((visited[src] && !visited[dest]) || (visited[dest] && !visited[src])) && matrix[dest][j] < minWeight) {
                minWeight = matrix[dest][j];
                minSrc = src;
                minDest = dest;
            }
        }

        // Dodaj krawędź o minimalnej wadze do drzewa rozpinającego
        mst.push_back({minSrc, minDest});
        cout << minSrc << " - " << minDest << endl;
        visited[minSrc] = true;
        visited[minDest] = true;
    }

}







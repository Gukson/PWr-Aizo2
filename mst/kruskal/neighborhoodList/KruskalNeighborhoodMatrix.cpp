//
// Created by Kuba on 01/06/2024.
//

#include "KruskalNeighborhoodMatrix.h"

void KruskalNeighborhoodMatrix::createOrder() {
    for(int x = 0; x < matrix.size(); x++){
        for(int y = 0; y <matrix[x].size(); y++){
            edgesVector.emplace_back(x,y);
        }
    }

    sort(edgesVector.begin(), edgesVector.end(), [this](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        return matrix[p1.first][p1.second].get_weight() < matrix[p2.first][p2.second].get_weight();
    });

    for(int x = 0; x < edgesVector.size();x++){
        for(int y = x; y < edgesVector.size(); y++){
            if(edgesVector[x].first == matrix[edgesVector[y].first][edgesVector[y].second].get_value() && edgesVector[y].first == matrix[edgesVector[x].first][edgesVector[x].second].get_value()){
                edgesVector.erase(edgesVector.begin() + y);
                break;
            }
        }
    }


    //wyświetlanie uzyskanych krawędzi
    for (const auto& p : edgesVector) {
        cout << "Edge (" << p.first << ", " << matrix[p.first][p.second].get_value() << ") - Weight: " << matrix[p.first][p.second].get_weight() << std::endl;
    }

}

int KruskalNeighborhoodMatrix::getEdgesAmount() {
    return edgesVector.size();
}

vector<int> KruskalNeighborhoodMatrix::getBestEdge(int index) {
    vector<int> results = vector<int>();
    results.push_back(edgesVector[index].first);
    results.push_back(matrix[edgesVector[index].first][edgesVector[index].second].get_value());
    results.push_back(matrix[edgesVector[index].first][edgesVector[index].second].get_weight());
    return results;
}
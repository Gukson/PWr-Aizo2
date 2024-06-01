//
// Created by Kuba on 01/06/2024.
//

#include "KruskalIncidentMatrix.h"

int KruskalIncidentMatrix::getEdgesAmount() {
    return matrix.size();
}

vector<int> KruskalIncidentMatrix::getBestEdge(int index) {
    auto t = std::find(order.begin(), order.end(), index);
    int m = distance(order.begin(), t);

    int w = 0;
    vector<int> results = vector<int>();
    for(int x = 0; x < matrix[m].size(); x++){
        if(matrix[m][x]!= 0){
            results.push_back(x);
            w = matrix[m][x];
        }
    }
    results.push_back(w);
    return results;
}

void KruskalIncidentMatrix::createOrder() {
    vector<int> temp = vector<int>();
    for(int x = 0; x < KruskalIncidentMatrix::getEdgesAmount();x++) {
        for(int y = 0; y < matrix[x].size(); y++){
            if(matrix[x][y] != 0){
                temp.push_back(matrix[x][y]);
                break;
            }
        }
    }
    order.resize(matrix.size(),0);
    for(int x = 0; x < temp.size();x++){
        auto min_it = std::min_element(temp.begin(), temp.end());
        int min_index = distance(temp.begin(), min_it);
        order[min_index] = x;
        temp[min_index] = numeric_limits<int>::max();
    }
}

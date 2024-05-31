//
// Created by Kuba on 31/05/2024.
//

#include "MstNeighborhoodListPrimAlgorithm.h"

void MstNeighborhoodListPrimAlgorithm::findMST(vector<vector<Node>> matrix) {
    int cost = 0;

    vector<bool> visited_boolean(matrix.size(), false);
    visited_boolean[0] = true;
    bool flag = true;
    int sum = 0;
    while (flag) {
        vector<int> res = findBestAvailableWay(visited_boolean,matrix);
        if(res[0] == numeric_limits<int>::max() ){
            flag = false;
            return;
        }
        sum += res[1];
        visited_boolean[res[2]] = true;

        cout << res[0] << " -> " << res[2] << endl;

    }
}

vector<int> MstNeighborhoodListPrimAlgorithm::findBestAvailableWay(vector<bool> visited_boolean, vector<vector<Node>> matrix) {
    int start = numeric_limits<int>::max();
    int waga = numeric_limits<int>::max();
    int docelowy = numeric_limits<int>::max();
    for(int x = 0; x < visited_boolean.size(); x++){
        if (visited_boolean[x]){
            for(int y = 0; y < matrix[x].size(); y++){
                if(!visited_boolean[matrix[x][y].get_value()] && matrix[x][y].get_weight() < waga){
                    start = x;
                    waga = matrix[x][y].get_weight();
                    docelowy = matrix[x][y].get_value();
                }
            }
        }
    }


    return vector<int>({start, waga, docelowy});
}

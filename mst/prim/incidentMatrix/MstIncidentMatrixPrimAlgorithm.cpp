//
// Created by Kuba on 02/05/2024.
//

#include "MstIncidentMatrixPrimAlgorithm.h"

using namespace std;

void MstIncidentMatrixPrimAlgorithm::findMST(vector<vector<int>> matrix) {
    int cost = 0;

    vector<bool> visited_boolean(matrix[0].size(), false);
    visited_boolean[0] = true;
    bool flag = true;
    int sum = 0;
    while (flag) {
        vector<int> res = findBestAvailableWay(visited_boolean,matrix);
        if(res[0] ==numeric_limits<int>::max() ){
            flag = false;
            return;
        }
        sum += res[1];
        visited_boolean[res[2]] = true;

        cout << res[0] << " -> " << res[2] << endl;
    }
}

vector<int> MstIncidentMatrixPrimAlgorithm::findBestAvailableWay(vector<bool> visited_boolean, vector<vector<int>> matrix) {
    int start = numeric_limits<int>::max();
    int waga = numeric_limits<int>::max();
    int docelowy = numeric_limits<int>::max();
    for(int x = 0; x < visited_boolean.size(); x++){
        if (visited_boolean[x]){
            for(int y = 0; y < matrix.size(); y++){
                int node = findNodes(matrix,y,x);
                if(matrix[y][x] != 0 && !visited_boolean[node] && matrix[y][x] < waga){
                    start = x;
                    waga = matrix[y][x];
                    docelowy = node;
                }
            }
        }
    }

    return vector<int>({start, waga, docelowy});

}

int MstIncidentMatrixPrimAlgorithm::findNodes(vector<vector<int>> matrix, int edge, int current){
    vector<int> Nodes = vector<int>();
    for(int x = 0; x < matrix[edge].size(); x++){
        if(matrix[edge][x] != 0 && x != current) {
            return x;
        }
    }
    return 0;
}





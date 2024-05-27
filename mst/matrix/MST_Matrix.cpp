//
// Created by Kuba on 02/05/2024.
//

#include "MST_Matrix.h"

using namespace std;

void MST_Matrix::findMST(vector<vector<int>> matrix) {
    int cost = 0;
    //inicjacja listy wierzchołków odwiedzonych
    vector<bool> visited(matrix[0].size(), false);
    set<int> mstWays;
    visited[0] = true;

    set<int> availableWays;
    while (!(availableWays = findAllAvailableWaysToGO(visited, matrix)).empty()) {
        for(int val: mstWays){
            availableWays.erase(val);
        }
        vector<int> results = findBestWay(availableWays,matrix);
        cost += results[1];
        mstWays.insert(results[0]);
        visited[results[2]] = true;
        visited[results[3]] = true;
        cout << results[2] << " -> " << results[3] << endl;
    }
}

set<int> MST_Matrix::findAllAvailableWaysToGO(vector<bool> visited, vector<vector<int> > matrix) {
    set<int> availableWays;
    for(int x = 0; x < visited.size(); x++){
        if(visited[x]){
            for(int y = 0; y < matrix.size(); y++){
                //szukamy każdej drogi gdzie dany wierzchołek jest początkiem albo końcem
                if(matrix[y][x] != 0){
                    auto it = find(matrix[y].begin(),matrix[y].end(),-1);
                    int endIndex = distance(matrix[y].begin(), it);

                    auto it2 = std::find_if(matrix[y].begin(), matrix[y].end(), [](int x) {
                        return x > 0;
                    });
                    int start = distance(matrix[y].begin(), it2);

                    if(!(visited[endIndex] && visited[start])){
                        availableWays.insert(y);
                    }
                }
            }
        }

    }
    return availableWays;
}

vector<int> MST_Matrix::findBestWay(set<int> availableWays,vector<vector<int> > matrix) {
    int bestWayCost = numeric_limits<int>::max();
    int bestWayNumber;
    int unlockedNode;
    for(int way: availableWays){
        auto it = std::find_if(matrix[way].begin(), matrix[way].end(), [](int x) {
            return x > 0;
        });

        if (it != matrix[way].end()) {
            int costIndex = distance(matrix[way].begin(), it);
            if(matrix[way][costIndex] < bestWayCost){
                bestWayCost = matrix[way][costIndex];
                bestWayNumber = way;
            }
        }

    }
    vector<int> results;
    results.push_back(bestWayNumber);
    results.push_back(bestWayCost);
    //tu jest bła∂
    for(int x = 0; x < matrix[bestWayNumber].size();x++){
        if(matrix[bestWayNumber][x] != 0){
            results.push_back(x);
        }
    }
    return results;
}





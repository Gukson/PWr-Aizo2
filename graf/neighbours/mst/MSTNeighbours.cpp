#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-use-anyofallof"
//
// Created by Kuba on 05/05/2024.
//

#include "MSTNeighbours.h"
#include <iostream>

using namespace std;

void MSTNeighbours::findMST(vector<vector<Node> > matrix) {

    vector<bool> visited(matrix.size(), false);
    set<int> mstWays;
    visited[0] = true;
    set<Node> availableWays;
    vector<pair<int,int> > ways;
    int cost = 0;
    while (!checkAreAllVisited(visited)){
        vector<int> results = findAllAvailableWaysToGO(visited,matrix);
        ways.push_back(make_pair(results[0],results[1]));
        cost+=results[2];
        visited[results[1]] = true;
    }
    for(int x = 0; x < ways.size(); x++){
        cout << ways[x].first << "  -> " << ways[x].second << endl;
    }
}



vector<int> MSTNeighbours::findAllAvailableWaysToGO(vector<bool> visited, vector<vector<Node>> matrix) {
    int startNode = 0;
    int endNode = 0;
    int cost = numeric_limits<int>::max();
    vector<int> availableNodes = findAllAvailableNodes(visited,matrix);
    for(int x = 0; x < visited.size(); x++){
        if(visited[x]){
            for(int y = 0; y < matrix[x].size(); y++){
                if(!visited[matrix[x][y].get_value()] && matrix[x][y].get_weight() < cost){
                    startNode = x;
                    endNode = matrix[x][y].get_value();
                    cost = matrix[x][y].get_weight();
                }
            }

            for(int n: availableNodes){
                auto it = find_if(matrix[n].begin(), matrix[n].end(), [&](Node obj) {
                    return obj.get_value() == x;
                });

                if(it != matrix[n].end()){
                    int index = distance(matrix[n].begin(),it);
                    if(matrix[n][index].get_weight() < cost && !visited[matrix[n][index].get_value()]){
                        startNode = matrix[n][index].get_value();
                        endNode = n;
                        cost = matrix[n][index].get_weight();
                    }
                }
            }
        }
    }
    vector<int> results;
    results.push_back(startNode);
    results.push_back(endNode);
    results.push_back(cost);
    return results;
}

bool MSTNeighbours::checkAreAllVisited(vector<bool> visited) {
    for(bool i: visited){
        if(!i){
            return false;
        }
    }
    return true;

}

vector<int> MSTNeighbours::findAllAvailableNodes(vector<bool> visited, vector<vector<Node>> matrix) {
    vector<int> available;
    for(int i = 0 ; i < visited.size(); i++){
        if(visited[i]){
            //dodawanie do dostepnych wsyztskich możliwych wierzchołków wychodzących z danego wierzchołka
            for(int x = 0; x < matrix[i].size(); x++){
                if(!visited[matrix[i][x].get_value()]){
                    available.push_back(matrix[i][x].get_value());
                }
            }
            for(int x = 0; x< matrix.size();x++){
                if(i != x){
                    for(int y = 0 ; y < matrix[x].size(); y++){
                        if(matrix[x][y].get_value() == i){
                            available.push_back(x);
                        }
                    }
                }
            }
        }
    }
    return available;
}

#pragma clang diagnostic pop
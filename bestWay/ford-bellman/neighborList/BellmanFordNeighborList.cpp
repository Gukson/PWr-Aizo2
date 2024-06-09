//
// Created by Kuba on 05/06/2024.
//

#include "BellmanFordNeighborList.h"

void BellmanFordNeighborList::testSimpleBellman(int startNode) {
    vector<pair<int,int>> lista = vector<pair<int,int>>();

    vector<bool> done = vector<bool>();
    done.resize(matrix.size(), false);

    lista.resize(matrix.size(), make_pair(numeric_limits<int>::max(),numeric_limits<int>::max()));

    lista[startNode] = make_pair(0,startNode);


    while (true){
        bool changes = false;
        for(int x = 0; x < matrix.size(); x++){
            if(!done[x] && lista[x].second != numeric_limits<int>::max()){
                for(int y = 0; y < matrix[x].size(); y++){
                    if(matrix[x][y].get_weight() + lista[x].first < lista[matrix[x][y].get_value()].first){
                        lista[matrix[x][y].get_value()].first = matrix[x][y].get_weight() + lista[x].first;
                        lista[matrix[x][y].get_value()].second = x;
                        changes = true;
                    }
                }
                done[x] = true;
            }
        }

        if(!changes) break;
    }
}

void BellmanFordNeighborList::testBellman() {
    for(int x = 0; x < matrix.size(); x++){
        testSimpleBellman(x);
    }
}

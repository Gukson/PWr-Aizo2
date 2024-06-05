//
// Created by Kuba on 05/06/2024.
//

#include "DjikstraIncidentMatrix.h"

void DjikstraIncidentMatrix::testSimpleDjikstra(int startNode) {
    vector<pair<int,int>> lista = vector<pair<int,int>>();

    vector<bool> done = vector<bool>();
    done.resize(matrix.size(), false);

    lista.resize(matrix[0].size(), make_pair(numeric_limits<int>::max(),numeric_limits<int>::max()));

    lista[startNode] = make_pair(0,startNode);

    while(true){
        bool changes = false;
        for(int y = 0; y < matrix[0].size(); y++){
            if(!done[y] && lista[y].first != numeric_limits<int>::max()){
                for(int x = 0; x < matrix.size(); x++){
                    if(matrix[x][y] > 0){
                        auto d = find(matrix[x].begin(), matrix[x].end(), -1);
                        int index = distance(matrix[x].begin(),d);
                        if(matrix[x][y] < lista[index].first){
                            lista[index].first = matrix[x][y];
                            lista[index].second = y;
                            changes = true;
                        }

                    }
                }
                done[y] = true;
            }
        }
        if(!changes) break;
    }
    vector<int> distance = vector<int>();
    distance.resize(matrix.size(),numeric_limits<int>::max());
    cout << "Wierzcholek startowy: " << startNode << endl;
    for(int x = 0; x < matrix.size(); x++){
        int w = 0;
        if(lista[x].first != numeric_limits<int>::max()){
            int temp = x;
            while(temp != startNode){
                w += lista[temp].first;
                cout << temp << " <- ";
                temp = lista[temp].second;
            }
            cout << startNode << " : " << w << endl;
        }

    }

}

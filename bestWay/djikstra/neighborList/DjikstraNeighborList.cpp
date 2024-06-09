//
// Created by Kuba on 03/06/2024.
//

#include "DjikstraNeighborList.h"

void DjikstraNeighborList::testSimpleDjikstra(int startNode) {
    vector<pair<int,int>> lista = vector<pair<int,int>>();

    vector<bool> done = vector<bool>();
    done.resize(matrix.size(), false);

    lista.resize(matrix.size(), make_pair(numeric_limits<int>::max(),numeric_limits<int>::max()));

    lista[startNode] = make_pair(0,startNode);


    while (true){
        bool changes = false;
        for(int x = 0; x < matrix.size(); x++){
            if(!done[x] && lista[x].first != numeric_limits<int>::max()){
                for(int y = 0; y < matrix[x].size(); y++){
                    if(matrix[x][y].get_weight() < lista[matrix[x][y].get_value()].first){
                        lista[matrix[x][y].get_value()].first = matrix[x][y].get_weight();
                        lista[matrix[x][y].get_value()].second = x;
                        changes = true;
                    }
                }
                done[x] = true;
            }
        }

        if(!changes) break;
    }

    vector<int> distance = vector<int>();
    distance.resize(matrix.size(),numeric_limits<int>::max());
//    cout << "Wierzcholek startowy: " << startNode << endl;
    for(int x = 0; x < matrix.size(); x++){
        int w = 0;
        if(lista[x].first != numeric_limits<int>::max()){
            int temp = x;
            while(temp != startNode){
                w += lista[temp].first;
//                cout << temp << " <- ";
                temp = lista[temp].second;
            }
//            cout << startNode << " : " << w << endl;
        }

    }

}

void DjikstraNeighborList::testDjikstra() {
    for(int x = 0; x < matrix.size(); x++){
        cout << x << endl;
        testSimpleDjikstra(x);
//        cout << endl;
    }
}

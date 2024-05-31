//
// Created by Kuba on 30/04/2024.
//

#include "NeighborhoodList.h"
#include <string>
#include <fstream>
#include <iostream>

vector<vector<Node> >  NeighborhoodList::load(string filename, bool directed) {
    ifstream file;
    file.open("data/dataFiles/" + filename);
    string line;
    getline(file,line);
    //najpierw liczba krawędzi, potem liczba wierzchołków
    vector result = stringSpliter(line);

    for(int x = 0; x < result[1]; x++){
        vector<Node> temp;
        matrix.push_back(temp);
    }

    while (getline(file,line)){
        vector<int> temp =  stringSpliter(line);
        if(directed){
            Node n = Node(temp[1],temp[2]);
            matrix[temp[0]].push_back(n);
        } else{
            Node n = Node(temp[1],temp[2]);
            matrix[temp[0]].push_back(n);
            Node n2 = Node(temp[0],temp[2]);
            matrix[temp[1]].push_back(n2);
        }
    }

    //wyświetlanie
    for(int x = 0; x<matrix.size(); x++){
        cout << x << ": ";
        for(auto & y : matrix[x]){
            cout << y.get_value() << " ";
        }
        cout << endl;
    }
    return matrix;
}

vector<int> NeighborhoodList::stringSpliter(string line) {
    vector<int> temp;
    int k = 0;
    string str;
    while(k < line.size()){
        if(line[k] != ' '){
            str+=line[k];
        } else{
            temp.push_back(stoi(str));
            str = "";
        }
        k++;
    }
    if(str.size() != 0){
        temp.push_back(stoi(str));
    }
    return temp;
}
//
// Created by Kuba on 29/04/2024.
//

#include "MatrixGraf.h"
#include <string>
#include <fstream>
#include <iostream>


vector<vector<int> > MatrixGraf::load(string filename) {

    ifstream file;
    file.open("data/dataFiles/" + filename);
    string line;
    getline(file,line);
    //najpierw liczba krawędzi, potem liczba wierzchołków
    vector result = stringSpliter(line);

    while (getline(file,line)){
        vector<int> temp =  stringSpliter(line);
        vector<int> myVector(result[1], 0);
        myVector[temp[0]] = temp[2];
        myVector[temp[1]] = -1;
        matrix.push_back(myVector);
    }

    for(int x = 0; x< result[1]; x++){
        for(int y = 0; y < result[0]; y++){
            cout << matrix[y][x] << " ";
        }
        cout << endl;
    }
    return matrix;

}

vector<int> MatrixGraf::stringSpliter(string line) {
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

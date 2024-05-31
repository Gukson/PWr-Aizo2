//
// Created by Kuba on 29/04/2024.
//

#include "IncidentMatrixGraf.h"
#include <string>
#include <fstream>
#include <iostream>


vector<vector<int> > IncidentMatrixGraf::load_matrix(string filename, bool directed) {
    matrix.clear();
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

        //Jeżeli graf jest skierowany to w miejsce konca wpiszmey -1 (zakladamy ze nie mamy wag ujemnych na ten moment) jeżeli jednak nie bedzie to wpisujemy koszt
        if(!directed){
            myVector[temp[1]] = temp[2];
        } else{
            myVector[temp[1]] = -1;
        }

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


vector<int> IncidentMatrixGraf::stringSpliter(string line) {
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

vector<vector<int> > IncidentMatrixGraf::loadFromGenerator(Generator generator, bool directed){
    matrix.clear();
    for(Edge e: generator.get_edges()){
        vector<int> myVector(generator.get_edges().size(), 0);
        myVector[e.get_from()] = e.get_weight();

        if(!directed){
            myVector[e.get_to()] = e.get_weight();
        } else{
            myVector[e.get_to()] = -1;
        }
        matrix.push_back(myVector);
    }

    for(int x = 0; x< generator.get_nodes(); x++){
        for(int y = 0; y < generator.get_edges().size(); y++){
            cout << matrix[y][x] << " ";
        }
        cout << endl;
    }

    return matrix;
}

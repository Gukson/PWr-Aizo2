//
// Created by Kuba on 31/05/2024.
//

#ifndef AIZO2_GENERATOR_H
#define AIZO2_GENERATOR_H

#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "edge/Edge.h"

using namespace std;

class Generator {
public:
    Generator(int nodes){
        this -> nodes = nodes;
    }
    void generate(int density);
    void saveInFile(string filename);
    int get_nodes();
    vector<Edge> get_edges();

private:
    bool containsEdge(const vector<Edge>& e, int from, int to);
    vector<Edge> edges = vector<Edge>();
    int nodes;
};


#endif //AIZO2_GENERATOR_H

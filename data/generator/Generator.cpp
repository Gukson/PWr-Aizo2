//
// Created by Kuba on 31/05/2024.
//

#include "Generator.h"

void Generator::generate(int density) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 100);

    //tworzenie drzewa spinającego
    for(int x = 0; x < Generator::nodes - 1; x++){
        Generator::edges.emplace_back(x,x+1, distribution(gen));
    }

    //tworzenie pozostałych krawędzi
    // nodes(nodes - 1) /2    to wzor na ilosc grawedzi w grafie pelnym, a od tego odejmujemy nodes-1 bo tyle juz krawedzi użyliśmy do stworzenia drzewa spinajacego
    int n = ((nodes*(nodes-1)/2) * density / 100) - (nodes - 1);

    uniform_int_distribution<int> new_distribution(0, nodes-1);

    for(int x = 0; x < n; x++){
        while (true){
            int f = new_distribution(gen);
            int t = f;
            while(t == f){
                t = new_distribution(gen);
            }

            if(!containsEdge(edges,f,t)){
                Generator::edges.emplace_back(f,t, distribution(gen));
                break;
            }
        }

    }

    for(Edge e: edges){
        cout << e.get_from() << " -> " << e.get_to() << " " << e.get_weight() << endl;
    }
}

bool Generator::containsEdge(const std::vector<Edge>& e, int from, int to) {
    for (Edge edge : e) {
        if (edge.get_from() == from && edge.get_to() == to) {
            return true;
        }
    }
    return false;
}

void Generator::saveInFile(string filename) {
    ofstream file("data/dataFiles/" + filename);

    if(file.is_open()){
        file << edges.size() << " " << nodes << endl;
        for(Edge e: edges){
            file << e.get_from() << " " << e.get_to() << " " << e.get_weight() << endl;
        }
    }

}

int Generator::get_nodes() {return nodes;}

vector<Edge> Generator::get_edges() {return edges;}
//
// Created by Kuba on 31/05/2024.
//

#ifndef AIZO2_EDGE_H
#define AIZO2_EDGE_H


class Edge {
    public:
        Edge(int from, int to, int weight){
            this -> from = from;
            this -> to = to;
            this -> weight = weight;
        }
        int get_from();
        int get_to();
        int get_weight();
    private:
        int from;
        int to;
        int weight;
};


#endif //AIZO2_EDGE_H

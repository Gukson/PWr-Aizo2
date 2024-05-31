//
// Created by Kuba on 30/04/2024.
//

#ifndef AIZO2_NODE_H
#define AIZO2_NODE_H


class Node {
    public:
        Node(int v, int w){
            value = v;
            weight = w;
        }
        int get_value();
        int get_weight();
    private:
        int value;
        int weight;
};


#endif //AIZO2_NODE_H

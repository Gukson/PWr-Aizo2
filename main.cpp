#include <iostream>
#include "./graf/matrix/MatrixGraf.h"
#include "./graf/neighbours/Neighbour.h"
#include "./mst/matrix/MST_Matrix.h"
#include "./graf/neighbours/mst/MSTNeighbours.h"

using namespace std;

int main() {
    MatrixGraf m = MatrixGraf();
    m.load("input1.txt");
    MST_Matrix ms = MST_Matrix();
    ms.findMST(m.matrix);

    Neighbour m2 = Neighbour();
    m2.load("input1.txt");
    MSTNeighbours m22 = MSTNeighbours();
    m22.findMST(m2.matrix);


    return 0;
}

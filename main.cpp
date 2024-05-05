#include <iostream>
#include "./graf/matrix/MatrixGraf.h"
#include "./graf/neighbours/Neighbour.h"
#include "./mst/matrix/MST_Matrix.h"

using namespace std;

int main() {
    MatrixGraf m = MatrixGraf();
    m.load("input1.txt");
    MST_Matrix ms = MST_Matrix();
    ms.findMST(m.matrix);

    return 0;
}

#include "graf/incidentMatrix/IncidentMatrixGraf.h"
#include "mst/prim/incidentMatrix/MstIncidentMatrixPrimAlgorithm.h"
#include "graf/neighborhoodList/NeighborhoodList.h"
#include "mst/prim/neighborhoodList/MstNeighborhoodListPrimAlgorithm.h"

using namespace std;

int main() {
    IncidentMatrixGraf m = IncidentMatrixGraf();
    m.load_matrix("input1.txt", false);
    MstIncidentMatrixPrimAlgorithm i = MstIncidentMatrixPrimAlgorithm();
    i.findMST(m.matrix);

    NeighborhoodList n = NeighborhoodList();
    n.load("input1.txt", false);
    MstNeighborhoodListPrimAlgorithm nn = MstNeighborhoodListPrimAlgorithm();
    nn.findMST(n.matrix);

    return 0;
}

//TODO Delete absolute path in MstNeighborhoodListPrimAlgorithm.h

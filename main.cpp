#include "graf/incidentMatrix/IncidentMatrixGraf.h"
#include "mst/prim/incidentMatrix/MstIncidentMatrixPrimAlgorithm.h"
#include "graf/neighborhoodList/NeighborhoodList.h"
#include "mst/prim/neighborhoodList/MstNeighborhoodListPrimAlgorithm.h"
#include "data/generator/Generator.h"
#include "mst/kruskal/incidentMatrix/KruskalIncidentMatrix.h"
#include "mst/kruskal/kruskal/Kruskal.h"

using namespace std;

int main() {
    Generator g = Generator(5);
    g.generate(100);
    g.saveInFile("test.txt");

    IncidentMatrixGraf m = IncidentMatrixGraf();
//    m.loadFromGenerator(g, false);
    m.load_matrix("input1.txt", false);

    MstIncidentMatrixPrimAlgorithm i = MstIncidentMatrixPrimAlgorithm();
    i.findMST(m.matrix);

    cout << endl;

    Kruskal* k = new KruskalIncidentMatrix(m.matrix);
    k->kruskal(k->getEdgesAmount());

    cout << endl;

    NeighborhoodList n = NeighborhoodList();
    n.loadFromGenerator(g, false);
    MstNeighborhoodListPrimAlgorithm nn = MstNeighborhoodListPrimAlgorithm();
    nn.findMST(n.matrix);

    return 0;
}
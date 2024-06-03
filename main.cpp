#include "graf/incidentMatrix/IncidentMatrixGraf.h"
#include "mst/prim/incidentMatrix/MstIncidentMatrixPrimAlgorithm.h"
#include "graf/neighborhoodList/NeighborhoodList.h"
#include "mst/prim/neighborhoodList/MstNeighborhoodListPrimAlgorithm.h"
#include "data/generator/Generator.h"
#include "mst/kruskal/incidentMatrix/KruskalIncidentMatrix.h"
#include "mst/kruskal/neighborhoodList/KruskalNeighborhoodMatrix.h"
#include "mst/kruskal/kruskal/Kruskal.h"
#include "bestWay/djikstra/neighboorList/DjikstraNeighborList.h"

using namespace std;

int main() {
//    //test generatora
//    Generator g = Generator(5);
//    g.generate(100);
//    g.saveInFile("test.txt");
//
//    //test mst dla incydecji - Prim
//    IncidentMatrixGraf m = IncidentMatrixGraf();
////    m.loadFromGenerator(g, false);
//    m.load_matrix("input1.txt", false);
//
//    MstIncidentMatrixPrimAlgorithm i = MstIncidentMatrixPrimAlgorithm();
//    i.findMST(m.matrix);
//
//    cout << endl;
//
//    Kruskal* k = new KruskalIncidentMatrix(m.matrix);
//    k->kruskal(k->getEdgesAmount());
//
//
//
//    cout << endl;
//
//    NeighborhoodList n = NeighborhoodList();
////    n.loadFromGenerator(g, false);
//    n.load("input1.txt", false);
//    MstNeighborhoodListPrimAlgorithm nn = MstNeighborhoodListPrimAlgorithm();
//    nn.findMST(n.matrix);
//
//    cout << endl;
//
//    Kruskal* k2 = new KruskalNeighborhoodMatrix(n.matrix);
//    k2->kruskal(k2->getEdgesAmount());

NeighborhoodList n3 = NeighborhoodList();
n3.load("input2.txt", true);
DjikstraNeighborList d = DjikstraNeighborList(n3.matrix);
d.testDjikstra();

    return 0;
}
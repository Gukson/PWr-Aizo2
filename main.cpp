#include "graf/incidentMatrix/IncidentMatrixGraf.h"
#include "mst/prim/incidentMatrix/MstIncidentMatrixPrimAlgorithm.h"
#include "graf/neighborhoodList/NeighborhoodList.h"
#include "mst/prim/neighborhoodList/MstNeighborhoodListPrimAlgorithm.h"
#include "data/generator/Generator.h"
#include "mst/kruskal/incidentMatrix/KruskalIncidentMatrix.h"
#include "mst/kruskal/neighborhoodList/KruskalNeighborhoodMatrix.h"
#include "mst/kruskal/kruskal/Kruskal.h"
#include "bestWay/djikstra/neighborList/DjikstraNeighborList.h"
#include "bestWay/djikstra/incidentMatrix/DjikstraIncidentMatrix.h"
#include "bestWay/ford-bellman/neighborList/BellmanFordNeighborList.h"
#include "bestWay/ford-bellman/incidentMatrix//BellmanFordIncidentMatrix.h"


using namespace std;

int main() {

    Generator g = Generator(50);
    g.generate(25);
    NeighborhoodList n = NeighborhoodList();
    n.loadFromGenerator(g, false);

    IncidentMatrixGraf m = IncidentMatrixGraf();
    m.loadFromGenerator(g, false);


    cout << "Lista sąsiedztwa - Prim" << endl;
    MstNeighborhoodListPrimAlgorithm nn = MstNeighborhoodListPrimAlgorithm();
    auto start = std::chrono::high_resolution_clock::now();
    nn.findMST(n.matrix);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    cout << "Czas wykonania: " << duration.count() << " ms" << endl << endl;;

    cout << "Lista sasiedztwa - Kruskal" << endl;
    Kruskal* k2 = new KruskalNeighborhoodMatrix(n.matrix);
    start = std::chrono::high_resolution_clock::now();
    k2->kruskal(k2->getEdgesAmount());
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Czas wykonania: " << duration.count() << " ms" << endl << endl;;

    n.loadFromGenerator(g, true);

    cout << "Lista sąsiedztwa - djikstra" << endl;
    DjikstraNeighborList d = DjikstraNeighborList(n.matrix);
    start = std::chrono::high_resolution_clock::now();
    d.testDjikstra();
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Czas wykonania: " << duration.count() << " ms" << endl << endl;

    cout << "Lista sąsiedztwa - Bellman" << endl;
    BellmanFordNeighborList b = BellmanFordNeighborList(n.matrix);
    start = std::chrono::high_resolution_clock::now();
    b.testBellman();
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Czas wykonania: " << duration.count() << " ms" << endl << endl;

//Incident


    cout << "Lista incydencji - Prim" << endl;
    MstIncidentMatrixPrimAlgorithm nn2 = MstIncidentMatrixPrimAlgorithm();
    start = std::chrono::high_resolution_clock::now();
    nn2.findMST(m.matrix);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Czas wykonania: " << duration.count() << " ms" << endl << endl;;

    cout << "Lista incydencji - Kruskal" << endl;
    Kruskal* k = new KruskalIncidentMatrix(m.matrix);
    start = std::chrono::high_resolution_clock::now();
    k->kruskal(k->getEdgesAmount());
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Czas wykonania: " << duration.count() << " ms" << endl << endl;;

    m.loadFromGenerator(g, true);

    cout << "Lista incydencji - djikstra" << endl;
    DjikstraIncidentMatrix d2 = DjikstraIncidentMatrix(m.matrix);
    start = std::chrono::high_resolution_clock::now();
    d.testDjikstra();
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Czas wykonania: " << duration.count() << " ms" << endl << endl;

    cout << "Lista incydencji - Bellman" << endl;
    BellmanFordIncidentMatrix b2 = BellmanFordIncidentMatrix(m.matrix);
    start = std::chrono::high_resolution_clock::now();
    b.testBellman();
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Czas wykonania: " << duration.count() << " ms" << endl << endl;


    return 0;
}
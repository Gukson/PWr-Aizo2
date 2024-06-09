//
// Created by Kuba on 06/06/2024.
//

#ifndef AIZO2_TESTEVERYTHING_H
#define AIZO2_TESTEVERYTHING_H

#include "../graf/incidentMatrix/IncidentMatrixGraf.h"
#include "../mst/prim/incidentMatrix/MstIncidentMatrixPrimAlgorithm.h"
#include "../graf/neighborhoodList/NeighborhoodList.h"
#include "../mst/prim/neighborhoodList/MstNeighborhoodListPrimAlgorithm.h"
#include "../data/generator/Generator.h"
#include "../mst/kruskal/incidentMatrix/KruskalIncidentMatrix.h"
#include "../mst/kruskal/neighborhoodList/KruskalNeighborhoodMatrix.h"
#include "../mst/kruskal/kruskal/Kruskal.h"
#include "../bestWay/djikstra/neighborList/DjikstraNeighborList.h"
#include "../bestWay/djikstra/incidentMatrix/DjikstraIncidentMatrix.h"
#include "../bestWay/ford-bellman/neighborList/BellmanFordNeighborList.h"
#include "../bestWay/ford-bellman/incidentMatrix//BellmanFordIncidentMatrix.h"

#include <iostream>
#include <vector>

using namespace std;

class TestEverything {
    void testEverything();
};


#endif //AIZO2_TESTEVERYTHING_H

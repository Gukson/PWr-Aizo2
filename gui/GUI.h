//
// Created by Kuba on 29/04/2024.
//

#ifndef AIZO2_GUI_H
#define AIZO2_GUI_H

#include <iostream>
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

using namespace std;

class GUI {
public:
    void gui();
    void mainMenu();
    void testALL();
};


#endif //AIZO2_GUI_H

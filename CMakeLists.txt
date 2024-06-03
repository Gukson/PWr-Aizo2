cmake_minimum_required(VERSION 3.28)
project(AiZO2)

set(CMAKE_CXX_STANDARD 17)


add_executable(AiZO2
        main.cpp
        graf/incidentMatrix/IncidentMatrixGraf.cpp
        graf/incidentMatrix/IncidentMatrixGraf.h
        graf/neighborhoodList/NeighborhoodList.cpp
        graf/neighborhoodList/NeighborhoodList.h
        mst/prim/incidentMatrix/MstIncidentMatrixPrimAlgorithm.cpp
        mst/prim/incidentMatrix/MstIncidentMatrixPrimAlgorithm.h
        mst/prim/neighborhoodList/MstNeighborhoodListPrimAlgorithm.cpp
        mst/prim/neighborhoodList/MstNeighborhoodListPrimAlgorithm.h
        graf/neighborhoodList/Node/Node.cpp
        graf/neighborhoodList/Node/Node.h
        data/generator/Generator.cpp
        data/generator/Generator.h
        data/generator/edge/Edge.cpp
        data/generator/edge/Edge.h
        mst/kruskal/unionFind/UnionFind.cpp
        mst/kruskal/unionFind/UnionFind.h
        mst/kruskal/kruskal/Kruskal.cpp
        mst/kruskal/kruskal/Kruskal.h
        mst/kruskal/kruskal/Kruskal.h
        mst/kruskal/incidentMatrix/KruskalIncidentMatrix.cpp
        mst/kruskal/incidentMatrix/KruskalIncidentMatrix.h
        mst/kruskal/neighborhoodList/KruskalNeighborhoodMatrix.cpp
        mst/kruskal/neighborhoodList/KruskalNeighborhoodMatrix.h
        bestWay/djikstra/neighboorList/DjikstraNeighborList.cpp
        bestWay/djikstra/neighboorList/DjikstraNeighborList.h
)
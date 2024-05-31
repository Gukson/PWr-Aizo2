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
)
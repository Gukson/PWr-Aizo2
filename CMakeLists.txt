cmake_minimum_required(VERSION 3.28)
project(AiZO2)

set(CMAKE_CXX_STANDARD 17)

add_executable(AiZO2 main.cpp
        graf/matrix/MatrixGraf.cpp
        graf/matrix/MatrixGraf.h
        gui/GUI.cpp
        gui/GUI.h
        graf/neighbours/Neighbour.cpp
        graf/neighbours/Neighbour.h
        graf/neighbours/Node/Node.cpp
        graf/neighbours/Node/Node.h
        mst/matrix/MST_Matrix.cpp
        mst/matrix/MST_Matrix.h
        mst/matrix/MST_Matrix.h
        graf/neighbours/mst/MSTNeighbours.cpp
        objects/wektor.cpp
        objects/wektor.cpp)
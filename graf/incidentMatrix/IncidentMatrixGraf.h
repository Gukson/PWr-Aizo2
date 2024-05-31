//
// Created by Kuba on 29/04/2024.
//

#ifndef AIZO2_INCIDENTMATRIXGRAF_H
#define AIZO2_INCIDENTMATRIXGRAF_H

#include <iostream>
#include <vector>
#include <string>
#include "../../data/generator/Generator.h"


using namespace std;

class IncidentMatrixGraf {

    public:
        vector<vector<int> > matrix;
        vector<vector<int> > load_matrix(string filename, bool directed);
        vector<vector<int> > loadFromGenerator(Generator generator, bool directed);
    private:
        vector<int> stringSpliter(string line);
};


#endif //AIZO2_INCIDENTMATRIXGRAF_H

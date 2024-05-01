//
// Created by Kuba on 29/04/2024.
//

#ifndef AIZO2_MATRIXGRAF_H
#define AIZO2_MATRIXGRAF_H
#include <vector>
#include <string>

using namespace std;

class MatrixGraf {

    public:
        vector<vector<int> > matrix;
        vector<vector<int> > load(string filename);
    private:
        vector<int> stringSpliter(string line);
};


#endif //AIZO2_MATRIXGRAF_H

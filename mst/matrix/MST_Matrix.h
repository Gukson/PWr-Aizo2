//
// Created by Kuba on 02/05/2024.
//

#ifndef AIZO2_MST_MATRIX_H
#define AIZO2_MST_MATRIX_H

#include <vector>
#include <iostream>
#include <set>

using namespace std;

class MST_Matrix {
    public:
        void findMST(vector<vector<int> > matrix);
    private:
        set<int> findAllAvailableWaysToGO(vector<bool> visited, vector<vector<int> > matrix);
        vector<int> findBestWay(set<int> availableWays,vector<vector<int> > matrix);

};


#endif //AIZO2_MST_MATRIX_H

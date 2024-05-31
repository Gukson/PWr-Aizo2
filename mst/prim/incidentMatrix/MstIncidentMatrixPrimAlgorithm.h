//
// Created by Kuba on 02/05/2024.
//

#ifndef AIZO2_MSTINCIDENTMATRIXPRIMALGORITHM_H
#define AIZO2_MSTINCIDENTMATRIXPRIMALGORITHM_H

#include <vector>
#include <iostream>

using namespace std;

class MstIncidentMatrixPrimAlgorithm {
    public:
        void findMST(vector<vector<int> > matrix);
    private:
        vector<int> findBestAvailableWay(vector<bool> visited, vector<vector<int>> matrix);
        int findNodes(vector<vector<int>> matrix, int edge,int current);
};


#endif //AIZO2_MSTINCIDENTMATRIXPRIMALGORITHM_H

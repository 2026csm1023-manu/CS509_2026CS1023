#ifndef READER_H
#define READER_H

#include <fstream>
#include <vector>

#include "../src/csr.h"

using namespace std;

bool read_bellman(
    ifstream& file,
    vector<vector<Edge>>& graph,
    int& source
);

bool read_floyd(
    ifstream& file,
    vector<vector<int>>& matrix
);

#endif
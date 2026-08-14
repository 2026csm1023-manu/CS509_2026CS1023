#ifndef PRIMS_H
#define PRIMS_H

#include "csr.h"
#include<vector>

using namespace std;

vector<MSTEdge> prims(const CSR&csr);

#endif
#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include <vector>
#include "csr.h"

using namespace std;

bool bellman_ford(const CSR& csr, int source, vector<int>& distance);

#endif
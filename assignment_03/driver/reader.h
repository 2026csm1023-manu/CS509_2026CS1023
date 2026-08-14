#ifndef READER_H
#define READER_H

#include<fstream>
#include<vector>

#include "../src/csr.h"

using namespace std;

bool read_mst(ifstream&file,vector<vector<Edge>>&graph);

#endif
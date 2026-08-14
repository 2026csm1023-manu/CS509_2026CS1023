#ifndef PRINTER_H
#define PRINTER_H

#include<vector>
#include<string>

#include "../src/kruskal.h"
#include "../src/prims.h"

using namespace std;

void print_mst(vector<MSTEdge>&kruskal_result,double kruskal_time,vector<MSTEdge>&prim_result,double prim_time,int choice,string output_file);

#endif

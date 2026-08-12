#ifndef PRINTER_H
#define PRINTER_H

#include <vector>
#include <string>

using namespace std;

void print_bellman_ford(int source,const vector<int>& distance,bool negative_cycle,double execution_time,string output_file);

void print_floyd_warshall(const vector<vector<int>>& distance,bool negative_cycle,double execution_time,string output_file);

#endif
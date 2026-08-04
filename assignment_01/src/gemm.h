#ifndef GEMM_H
#define GEMM_H

#include <vector>
using namespace std;


void simple_gemm(const vector<vector<int>>& A,const vector<vector<int>>& B,vector<vector<int>>& C,int M,int K,int N);

#endif
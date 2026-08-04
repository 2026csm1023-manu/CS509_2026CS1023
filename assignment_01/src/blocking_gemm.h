#ifndef BLOCKING_GEMM_H
#define BLOCKING_GEMM_H

#include <vector>
using namespace std;

void blocking_gemm(const vector<vector<int>>& A,const vector<vector<int>>& B,vector<vector<int>>& C,int M,int K,int N,int block_size);


#endif
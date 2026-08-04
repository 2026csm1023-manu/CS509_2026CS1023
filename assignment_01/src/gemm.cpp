#include "gemm.h"

void simple_gemm(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int M, int K,int N){

    for (int i=0; i < M; i++)
    {
        for (int j=0; j < N; j++)
        {
            for (int k=0; k < K; k++)
            {
                C[i][j]+= A[i][k]*B[k][j];
            }
            
        }
        
    }
    
}
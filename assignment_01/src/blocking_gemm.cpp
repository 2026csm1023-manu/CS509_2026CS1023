#include <algorithm>
#include "blocking_gemm.h"

using namespace std;

void blocking_gemm(const vector<vector<int>>& A,const vector<vector<int>>& B,vector<vector<int>>& C,int M,int K,int N,int block_size)
{
    for(int ii= 0; ii < M; ii+=block_size)
    {
        for(int jj= 0; jj < N; jj+=block_size)
        {
            for(int kk= 0; kk < K; kk+=block_size)
            {
                for(int i= ii; i < min(ii+block_size, M); i++)
                {
                    for(int j= jj; j < min(jj+block_size, N); j++)
                    {
                        for(int k= kk; k < min(kk+block_size, K); k++)
                        {
                            C[i][j]+=A[i][k]*B[k][j];
                        }
                    }
                }
            }
        }
    }
}
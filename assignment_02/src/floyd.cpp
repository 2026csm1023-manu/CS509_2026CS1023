#include "floyd.h"

using namespace std;

bool floyd_warshall(vector<vector<int>>& distance)
{
    int V=distance.size();

    for(int k=0; k<V; k++)
    {
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(distance[i][k]!=1000000000 && distance[k][j]!=1000000000)
                {
                    int new_distance=distance[i][k] + distance[k][j];

                    if(new_distance<distance[i][j])
                    {
                        distance[i][j]=new_distance;
                    }
                }
            }
        }
    }

    // Check for negative cycle
    for(int i=0; i<V; i++)
    {
        if(distance[i][i]< 0)
        {
            return false;
        }
    }

    return true;
}
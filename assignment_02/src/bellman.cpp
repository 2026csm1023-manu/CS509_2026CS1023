#include "bellman.h"
#include <climits>

using namespace std;

bool bellman_ford(const CSR& csr, int source, vector<int>& distance)
{
    int V=csr.vertices;

    distance.resize(V);

    //Initially all vertices are unreachable
    for(int i=0; i<V; i++)
    {
        distance[i]=INT_MAX;
    }

    distance[source] = 0;

    //Relax all edges V-1 times
    for(int count=0; count<V-1; count++)
    {
        for(int u=0; u<V; u++)
        {
            for(int i=csr.row_ptr[u]; i<csr.row_ptr[u + 1]; i++)
            {
                int v = csr.col_idx[i];
                int weight = csr.values[i];

                if(distance[u] != INT_MAX)
                {
                    if(distance[u] + weight < distance[v])
                    {
                        distance[v] = distance[u] + weight;
                    }
                }
            }
        }
    }

    // Check for negative cycle
    for(int u=0; u<V; u++)
    {
        for(int i=csr.row_ptr[u];
            i<csr.row_ptr[u + 1];
            i++)
        {
            int v=csr.col_idx[i];
            int weight=csr.values[i];

            if(distance[u]!=INT_MAX)
            {
                if(distance[u]+weight<distance[v])
                {
                    return false;
                }
            }
        }
    }

    return true;
}
#include "prims.h"
#include<climits>

using namespace std;

vector<MSTEdge> prims(const CSR&csr)
{
    int V=csr.vertices;

    vector<bool>used(V,false);
    vector<MSTEdge>answer;

    used[0]=true;

    //we need V-1 edges
    for(int count=0;count<V-1;count++)
    {
        int minWeight=INT_MAX;
        int from=-1;
        int to=-1;

        //check vertices already in the tree
        for(int u=0;u<V;u++)
        {
            if(used[u]==false)
                continue;

            //check all neighbours of u
            for(int i=csr.row_ptr[u];i<csr.row_ptr[u+1];i++)
            {
                int v=csr.col_idx[i];
                int weight=csr.values[i];

                //only consider edges going to a new vertex
                if(used[v]==false && weight<minWeight)
                {
                    minWeight=weight;
                    from=u;
                    to=v;
                }
            }
        }

        //take the cheapest edge
        answer.push_back({from,to,minWeight});

        //add the new vertex to the tree
        used[to]=true;
    }

    return answer;
}
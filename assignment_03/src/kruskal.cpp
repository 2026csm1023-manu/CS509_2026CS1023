#include "kruskal.h"
#include<algorithm>

using namespace std;

int findParent(vector<int>&parent,int x)
{
    if(parent[x]==x)
        return x;

    return findParent(parent,parent[x]);
}

void unionSet(vector<int>&parent,int a,int b)
{
    a=findParent(parent,a);
    b=findParent(parent,b);

    parent[a]=b;
}

vector<MSTEdge> kruskal(const CSR&csr)
{
    vector<MSTEdge>edges;
    vector<MSTEdge>answer;

    //get edges from CSR
    for(int u=0;u<csr.vertices;u++)
    {
        for(int i=csr.row_ptr[u];i<csr.row_ptr[u+1];i++)
        {
            int v=csr.col_idx[i];

            if(u<v)
                edges.push_back({u,v,csr.values[i]});
        }
    }

    //sort edges by weight
    sort(edges.begin(),edges.end(),[](MSTEdge a,MSTEdge b)
    {
        return a.weight<b.weight;
    });

    vector<int>parent(csr.vertices);

    for(int i=0;i<csr.vertices;i++)
        parent[i]=i;

    //take cheapest edges
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].u;
        int v=edges[i].v;

        if(findParent(parent,u)!=findParent(parent,v))
        {
            answer.push_back(edges[i]);
            unionSet(parent,u,v);
        }

        if(answer.size()==csr.vertices-1)
            break;
    }

    return answer;
}
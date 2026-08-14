#include "reader.h"

using namespace std;

bool read_mst(ifstream&file,vector<vector<Edge>>&graph)
{
    int V,E;
    file>>V>>E;

    if(file.fail())
        return false;

    graph.resize(V);

    for(int i=0;i<V;i++)
    {
        int vertex,degree;
        file>>vertex>>degree;

        for(int j=0;j<degree;j++)
        {
            int neighbour,weight;
            file>>neighbour>>weight;

            Edge edge;
            edge.neighbour=neighbour;
            edge.weight=weight;

            graph[vertex].push_back(edge);
        }
    }

    return true;
}
#include "reader.h"

using namespace std;

bool read_bellman(ifstream& file,vector<vector<Edge>>& graph,int& source)
{
    int V, E;

    file >> V >> E;

    if(file.fail())
        return false;

    graph.resize(V);

    for(int i=0; i<V; i++)
    {
        int vertex, degree;

        file >> vertex >> degree;

        for(int j=0; j<degree; j++)
        {
            int neighbour, weight;

            file >> neighbour >> weight;

            Edge edge;

            edge.neighbour=neighbour;
            edge.weight=weight;

            graph[vertex].push_back(edge);
        }
    }

    string word;

    file >> word >> source;

    if(word!="SOURCE")
        return false;

    return true;
}


bool read_floyd(ifstream& file,vector<vector<int>>& matrix)
{
    int V;

    file >> V;

    if(file.fail())
        return false;

    matrix.resize(V, vector<int>(V));

    for(int i=0;i<V; i++)
    {
        for(int j=0;j<V; j++)
        {
            string value;

            file>> value;

            if(value== "INF")
            {
                matrix[i][j]= 1000000000;
            }
            else
            {
                matrix[i][j]= stoi(value);
            }
        }
    }

    return true;
}
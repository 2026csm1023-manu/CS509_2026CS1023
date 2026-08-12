#include "printer.h"

#include <fstream>
#include <climits>

using namespace std;

void print_bellman_ford(int source,const vector<int>& distance,bool negative_cycle,double execution_time,string output_file)
{
    ofstream out(output_file);

    out << "Algorithm: Bellman-Ford\n";
    out << "Source: " << source << "\n";

    if(negative_cycle)
    {
        out<<"Negative cycle: true\n";
    }
    else
    {
        out<<"Vertex Distance\n";

        for(int i=0; i<distance.size(); i++)
        {
            out<<i<< " ";

            if(distance[i]==INT_MAX)
                out << "INF\n";
            else
                out << distance[i] << "\n";

        }

        out << "Negative cycle: none\n";
    }

    out << "Execution time: "<< execution_time<< " ms\n";

    out.close();
}


void print_floyd_warshall(const vector<vector<int>>& distance,bool negative_cycle,double execution_time,string output_file)
{
    ofstream out(output_file);

    out << "Algorithm: Floyd-Warshall\n";

    if(negative_cycle)
    {
        out << "Negative cycle: true\n";
    }
    else
    {
        out << "Distance matrix:\n";

        for(int i=0;i< distance.size(); i++)
        {
            for(int j=0; j<distance[i].size(); j++)
            {
                if(distance[i][j]==1000000000)
                    out << "INF";
                else
                    out<<distance[i][j];

                if(j!=distance[i].size()-1)
                    out<< " ";
            }

            out << "\n";
        }

        out << "Negative cycle: none\n";
    }

    out << "Execution time: "<< execution_time<< " ms\n";

    out.close();
}
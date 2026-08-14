#include "printer.h"
#include<fstream>

using namespace std;

void print_edges(ofstream&out,vector<MSTEdge>&edges)
{
    for(int i=0;i<edges.size();i++)
        out<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].weight<<"\n";
}

int get_weight(vector<MSTEdge>&edges)
{
    int total=0;

    for(int i=0;i<edges.size();i++)
        total=total+edges[i].weight;

    return total;
}

void print_mst(vector<MSTEdge>&kruskal_result,double kruskal_time,vector<MSTEdge>&prim_result,double prim_time,int choice,string output_file)
{
    ofstream out(output_file);

    if(choice==1||choice==3)
    {
        out<<"Algorithm: Kruskal's MST\n";
        out<<"MST edges:\n";

        print_edges(out,kruskal_result);

        out<<"Total MST weight: "<<get_weight(kruskal_result)<<"\n";
        out<<"Execution time: "<<kruskal_time<<" ms\n";
    }

    if(choice==3)
        out<<"\n";

    if(choice==2||choice==3)
    {
        out<<"Algorithm: Prim's MST\n";
        out<<"MST edges:\n";

        print_edges(out,prim_result);

        out<<"Total MST weight: "<<get_weight(prim_result)<<"\n";
        out<<"Execution time: "<<prim_time<<" ms\n";
    }

    out.close();
}
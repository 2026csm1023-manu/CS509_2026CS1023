#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>

#include "timer.h"
#include "printer.h"
#include "reader.h"
#include "../src/csr.h"
#include "../src/kruskal.h"
#include "../src/prims.h"

using namespace std;

void run_one_test(int choice);
void run_all_tests(int choice);
void run_test(string filepath,int choice);
string get_name(string filename);

int main()
{
    int choice;
    int run_choice;

    cout<<"1. Kruskal\n";
    cout<<"2. Prim\n";
    cout<<"3. Both\n";
    cout<<"Enter choice: ";
    cin>>choice;

    if(choice<1||choice>3)
    {
        cout<<"Invalid choice\n";
        return 0;
    }

    cout<<"\n1. Run one test\n";
    cout<<"2. Run all tests\n";
    cout<<"Enter choice: ";
    cin>>run_choice;

    if(run_choice==1)
        run_one_test(choice);
    else if(run_choice==2)
        run_all_tests(choice);
    else
        cout<<"Invalid choice\n";

    return 0;
}

void run_one_test(int choice)
{
    string filename;

    cout<<"Enter test filename: ";
    cin>>filename;

    run_test("tests/"+filename,choice);
}

void run_all_tests(int choice)
{
    try
    {
        for(const auto&entry:filesystem::directory_iterator("tests"))
        {
            if(entry.is_regular_file())
            {
                string filename=entry.path().filename().string();

                if(filename.find("mst_")==0)
                    run_test(entry.path().string(),choice);
            }
        }
    }
    catch(...)
    {
        cout<<"Error: Could not open tests directory\n";
    }
}

void run_test(string filepath,int choice)
{
    ifstream file(filepath);

    if(!file)
    {
        cout<<"Error: Could not open test file\n";
        return;
    }

    vector<vector<Edge>>graph;

    if(!read_mst(file,graph))
    {
        cout<<"Error: Invalid MST input\n";
        file.close();
        return;
    }

    CSR csr=make_csr(graph);

    string output_file="outputs/"+get_name(filepath)+"_output.txt";

    vector<MSTEdge>kruskal_result;
    vector<MSTEdge>prim_result;

    double kruskal_time=0;
    double prim_time=0;

    if(choice==1||choice==3)
    {
        start_timer();

        kruskal_result=kruskal(csr);

        kruskal_time=stop_timer();
    }

    if(choice==2||choice==3)
    {
        start_timer();

        prim_result=prims(csr);

        prim_time=stop_timer();
    }

    print_mst(kruskal_result,kruskal_time,prim_result,prim_time,choice,output_file);

    file.close();
}

string get_name(string filename)
{
    size_t slash=filename.find_last_of("\\/");

    if(slash!=string::npos)
        filename=filename.substr(slash+1);

    size_t dot=filename.find_last_of('.');

    if(dot==string::npos)
        return filename;

    return filename.substr(0,dot);
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

#include "timer.h"
#include "printer.h"
#include "reader.h"
#include "../src/csr.h"
#include "../src/bellman.h"
#include "../src/floyd.h"

using namespace std;


void run_one_test(string algorithm);
void run_all_tests(string algorithm);
void run_test(string filepath,string algorithm);

string get_name(string filename);

int main()
{
    int algorithm_choice;
    int run_choice;
    string algorithm;

    cout<<"Select Algorithm\n";
    cout<<"1. Bellman-Ford\n";
    cout<<"2. Floyd-Warshall\n";
    cout<<"Enter choice: ";
    cin>>algorithm_choice;

    //Choosing algorithm
    if(algorithm_choice==1)
    {
        algorithm="bellman";
    }
    else if(algorithm_choice==2)
    {
        algorithm="floyd";
    }
    else
    {
        cout<<"Invalid choice\n";
        return 0;
    }

    cout<<"\n1. Run one test\n";
    cout<<"2. Run all tests\n";
    cout<<"Enter choice: ";
    cin>>run_choice;

    //Run one or all tests
    if(run_choice==1)
    {
        run_one_test(algorithm);
    }
    else if(run_choice==2)
    {
        run_all_tests(algorithm);
    }
    else
    {
        cout<<"Invalid choice\n";
    }

    return 0;
}

void run_one_test(string algorithm)
{
    string filename;

    cout<<"Enter test filename: ";
    cin>>filename;

    run_test("tests/"+filename,algorithm);
}

//Runs all test files in tests folder
void run_all_tests(string algorithm)
{
    try
    {
        for(const auto& entry:filesystem::directory_iterator("tests"))
        {
            if(entry.is_regular_file())
            {
                string filename=entry.path().filename().string();

                if(filename.find(algorithm+"_")==0)
                {
                    run_test(entry.path().string(),algorithm);
                }
            }
        }
    }
    catch(...)
    {
        cout<<"Error: Could not open tests directory\n";
    }
}

void run_test(string filepath,string algorithm)
{
    ifstream file(filepath);

    if(!file)
    {
        cout<<"Error: Could not open test file\n";
        return;
    }

    cout<<"\nRunning: "<<get_name(filepath)<<endl;

    string output_file="outputs/"+get_name(filepath)+"_output.txt";

    //Bellman-Ford
    if(algorithm=="bellman")
    {
        vector<vector<Edge>> graph;
        int source;

        if(!read_bellman(file,graph,source))
        {
            cout<<"Error: Invalid Bellman-Ford input\n";
            file.close();
            return;
        }

        //Convert graph to CSR
        CSR csr=make_csr(graph);

        vector<int> distance;

        start_timer();
        bool result=bellman_ford(csr,source,distance);
        double execution_time=stop_timer();

        print_bellman_ford(source,distance,!result,execution_time,output_file);
    }

    //Floyd-Warshall
    else if(algorithm=="floyd")
    {
        vector<vector<int>> matrix;

        if(!read_floyd(file,matrix))
        {
            cout<<"Error: Invalid Floyd-Warshall input\n";
            file.close();
            return;
        }

        start_timer();
        bool result=floyd_warshall(matrix);
        double execution_time=stop_timer();

        print_floyd_warshall(matrix,!result,execution_time,output_file);
    }

    file.close();
}

string get_name(string filename)
{
    size_t slash=filename.find_last_of("\\/");

    if(slash!=string::npos)
    {
        filename=filename.substr(slash+1);
    }

    size_t dot=filename.find_last_of('.');

    if(dot==string::npos)
    {
        return filename;
    }

    return filename.substr(0,dot);
}
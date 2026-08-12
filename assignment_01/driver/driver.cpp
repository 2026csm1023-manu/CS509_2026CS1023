#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <filesystem>
#include "timer.h"
#include "../src/gemm.h"
#include "../src/blocking_gemm.h"

using namespace std;

//Function declarations
void run_one_test();
void run_all_tests();
void run_test(string filepath);
bool validate(ifstream &file);
void print_result(const vector<vector<int>>& C,int M, int N,double execution_time, string algorithm, string output_file);



int main()
{

    int choice;

    cout << "1. Run one test\n";
    cout << "2. Run all tests\n";
    cout << "Enter choice: ";
    cin >> choice;


    if(choice == 1)
    {
        run_one_test();
    }
    else if(choice == 2)
    {
        run_all_tests();
    }
    else
    {
        cout << "Invalid choice\n";
    }

    return 0;
}


bool validate(ifstream &file){

    int M,N,K;
    
    file >> M >> K >> N;

    if(file.fail()){
        return false;
    }

    if (M <=0 || N<=0 || K<=0){
        return false;
    }

    return true;
    
}


//Run one single test, TEST FILENAME must be provided
void run_one_test()
{
    string filename;

    cout << "Enter test filename: ";
    cin >> filename;

    run_test("tests/gemm_tests/" + filename);
}


//Run all testfiles in test folder
void run_all_tests()
{
    filesystem::directory_iterator files("tests/gemm_tests");

    for(auto file : files)
    {
        run_test(file.path().string());
    }
}


 /*Logic to run a single test
  1.Gets filename through parameters
  2.Validates the test matrix dimensions
  3.Loads both matrices which are to be multiplies in Matrix A and B
  4.Runs GEMM and Blocking GEMM algorithm and records execution time for each
  */

void run_test(string filepath)
{
    ifstream file;
    file.open(filepath);

    if(!file)
    {
        cout << "Error: Could not open test file\n";
        return;
    }


    if(!validate(file))
    {
        cout << "Error: Invalid test file\n";
        return;
    }


    //validate() already read the first line
    //so return to beginning of file
    file.clear();
    file.seekg(0);


    //Read dimensions
    int M, K, N;

    file >> M >> K >> N;


    //Create matrices
    vector<vector<int>> A(M, vector<int>(K));
    vector<vector<int>> B(K, vector<int>(N));
    vector<vector<int>> C(M, vector<int>(N, 0));
    vector<vector<int>> D(M, vector<int>(N, 0));


    //Read matrix A
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<K; j++)
        {
            file >> A[i][j];
        }
    }


    //Read matrix B
    for(int i=0; i<K; i++)
    {
        for(int j=0; j<N; j++)
        {
            file >> B[i][j];
        }
    }


    cout << "\nRunning: " << filesystem::path(filepath).filename() << endl;

    string test_name = filesystem::path(filepath).stem().string();

    /*Execute GEMM, Record time and print results */
    start_timer();
    simple_gemm(A,B,C,M,K,N);
    double time = stop_timer();
    print_result(C, M, N, time, "GEMM Simple","outputs/" + test_name + "_simple.txt");


    /*Execute Blocking GEMM, Record time and print results */
    int block_size = 32;
    start_timer();
    blocking_gemm(A,B,D,M,K,N,block_size);
    double blocking_time = stop_timer();
    print_result(D,M,N,blocking_time,"GEMM Blocking","outputs/" + test_name + "_blocking.txt");

    file.close();
}

//Displays the Output matrix as per the given format
void print_result(const vector<vector<int>>& C,int M,int N,double execution_time,string algorithm, string output_file)
{

    ofstream out(output_file);

    if (!out)
    {
        cout << "Error: Could not create output file\n";
        return;
    }

    out << "Algorithm: " << algorithm << endl;
    out << "Result matrix:" << endl;


    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            out<< C[i][j] << " ";
        }

        out << "\n";
    }

    out << "Execution time: " << execution_time << " ms\n";
    out.close();
}
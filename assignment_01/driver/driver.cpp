#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <filesystem>

using namespace std;

void simple_gemm(/* parameters */);
void blocking_gemm(/* parameters */);
bool validate(ifstream &file);

int main()
{

    int choice;

    cout << "1. Run one test\n";
    cout << "2. Run all tests\n";
    cout << "Enter choice: ";
    cin >> choice;


    if(choice==1){

        string filename;

        cout << "Enter test filename: \n";
        cin >> filename;

        ifstream file;
        file.open("../tests/" + filename);

        if(!file){
            cout << "Could not open testfile\n";
            return 1;
        }

        if (!validate(file)){
            cout << "Invalid test file\n";
            return 1;
        }

        cout << "Executing  " << filename << endl;


        auto start=chrono::high_resolution_clock::now();
        //execute GEMM
        auto stop=chrono::high_resolution_clock::now();
        double execution_time= chrono::duration<double, milli>(stop-start).count();
        
        file.close();

    }
    else if(choice==2){

        filesystem::directory_iterator files("tests");

        for(auto file:files)
        {

            ifstream test;
            test.open(file.path());

            if(!test){
                cout << "Could not open test file \n";
                continue;
            }

            if (!validate(test)){
                cout << "Invalid test file\n";
                continue; 
            }

            cout << "Running " << file.path().filename() <<endl;

            auto start=chrono::high_resolution_clock::now();
            //execute GEMM
            auto stop=chrono::high_resolution_clock::now();
            double execution_time= chrono::duration<double, milli>(stop-start).count();

            test.close();
        }
    }
    else{

        cout << "Invalid Choice\n";
    }

    return 0;
}


bool validate(ifstream &file){

    int M,N,K;
    
    file >> M >> K >> N;

    if(file.fail()){
        return false;
    }

    if (M <=0 || N <=0 || K <=0){
        return false;
    }

    return true;
    
}


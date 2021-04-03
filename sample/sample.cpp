#include<bits/stdc++.h>
#include<fstream>
using namespace std;

ifstream fin;
ofstream fout;
void printVector(vector<int>, string);
void printArray(int*, int, string);
void load_file_io();

int main(){
    // comment this function to use standard I/O and replace fout with fin.
    load_file_io();

    // Use fin and fout instead of cin and cout.
    // Write your code here
    
}


// Common functions
void printVector(vector<int> A, string name = ""){
    fout<<endl<<"Vector "<<name<<" with size "<<A.size()<<" :";
    for(int i=0; i<A.size(); i++){
        fout<<A[i]<<" ";
    }
    fout<<endl<<endl;
}

void printArray(int A[], int n, string name = ""){
    fout<<endl<<"Array "<<name<<" with size "<<n<<" :";
    for(int i=0; i<n; i++){
        fout<<A[i]<<" ";
    }
    fout<<endl<<endl;
}

void load_file_io(){
    fin.open("../input_output/input.txt");
    fout.open("../input_output/output.txt");
}
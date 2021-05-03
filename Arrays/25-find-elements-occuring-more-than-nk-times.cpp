#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

int findElements(int A[], int n, int k){
    map<int, int> M;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(M.find(A[i]) == M.end())
            M[A[i]] = 1;
        else{
            M[A[i]] += 1;
        }
        if(M[A[i]] - 1 <= n/k){
            res += 1;        
        }
    }
    return res;
}

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of cin.
    // Write your code here
    int t;
    fin>>t;
    while(t--){
        int n;
        fin>>n;
        int k;
        fin>>k;
        int A[n];
        inputArray(A, n);
        cout<<findElements(A, n, k)<<endl;
    }
}


// Common functions
void load_file_io(){
    fin.open("../input_output/input.txt");
}

void inputArray(int A[], int n){
    for(int i = 0; i<n; i++){
        fin >> A[i];
    }
}

void inputVector(vector<int>& A, int n){
    for(int i = 0; i<n; i++){
        int c;
        fin >> c;
        A.push_back(c);
    }
}

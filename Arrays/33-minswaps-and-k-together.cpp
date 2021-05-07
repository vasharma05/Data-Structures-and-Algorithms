#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

int minSwap(int *A, int n, int k) {
    // Complet the function
    int cnt = 0, res = INT_MAX, bad = 0;
    for(int i = 0; i< n; i++){
        if(A[i] <= k)
            cnt++;
    }
    for(int i = 0; i< cnt; i++){
        if(A[i] > k)
            bad++;
    }
    if(bad < res)
        res = bad;

    for(int i = 0; i+cnt-1 < n-1; i++){
        if(A[i] > k)
            bad--;
        if(A[i+cnt] > k)
            bad++;
        if(bad < res)
            res = bad;
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
        int n, k;
        fin>>n>>k;
        int A[n];
        inputArray(A, n);
        cout<<minSwap(A, n, k)<<endl;
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

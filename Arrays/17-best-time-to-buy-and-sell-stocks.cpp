#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

int maxProfit(vector<int>& A) {
    
    int n = A.size();

    int mn_left[n];
    int mx_right[n];

    mn_left[0] = A[0];
    mx_right[n-1] = A[n-1];
    
    for(int i = 1; i<n; i++){
        mn_left[i] = min(mn_left[i-1], A[i]);
    }

    for(int i = n-2; i >= 0; i--){
        mx_right[i] = max(mx_right[i+1], A[i]);
    }
    
    int profit = 0;

    for(int i = 0; i<n; i++){
        profit = max(profit, mx_right[i] - mn_left[i]);
    }
    return profit;
    
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
        fin >> n;
        vector<int> A;
        inputVector(A, n);
        printVector(A, "");
        cout<<maxProfit(A)<<endl;
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

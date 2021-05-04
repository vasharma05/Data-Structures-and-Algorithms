#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

int sb(int A[], int n, int x){
    if(A[0] > x)
        return 1;
    int res = n;
    int i = 1, l = 0, sum = A[0];
    while(i < n){
        if(A[i] > x)
            return 1;
        sum += A[i];
        while(sum > x){
            sum -= A[l++];
            res = min(res, i - l + 2);
        }
        i++;
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
        int n, x;
        fin>>n>>x;
        int A[n];
        inputArray(A, n);
        cout<<sb(A, n, x)<<endl;
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

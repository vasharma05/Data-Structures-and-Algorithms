#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        int A[N*N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                A[i*Mat[0].size() + j] = Mat[i][j];
            }
        }
        sort(A, A+N*N);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = A[i*Mat[0].size() + j];
            }
        }
        return Mat;
    }
};

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
        vector<vector<int>> A;
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j = 0; j<n; j++){
                int te;
                fin>>te;
                temp.push_back(te);
            }
            A.push_back(temp);
        }
        Solution ob;
        A = ob.sortedMatrix(n, A);
        for(int i = 0; i<n; i++){
            printVector(A[i], "");
        }
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

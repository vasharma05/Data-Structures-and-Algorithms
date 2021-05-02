#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

void rearrange(int A[], int n){
    for(int i = 0; i < n;){
        bool check = (i%2 == 0 && A[i] < 0) || (i%2 && A[i] > 0);
        if(check){
            i++;
            continue;
        }else if(i%2 == 0){
            int ind = i;
            i++;
            while(i < n){
                if(A[i] < 0){
                    swap(A[i], A[ind]);
                    break;
                }else{
                    i += 2;
                }
            }
        }else{
            int ind = i;
            i++;
            while(i < n){
                if(A[i] > 0){
                    swap(A[i], A[ind]);
                    break;
                }else{
                    i += 2;
                }
            }
        }
    }
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
        int A[n];
        for(int i = 0; i<n; i++){
            fin >> A[i];
        }
        rearrange(A, n);
        printArray(A, n, "Result");
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

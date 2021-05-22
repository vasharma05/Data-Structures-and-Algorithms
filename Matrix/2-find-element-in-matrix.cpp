#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

class Solution {
    bool binSearch(vector<int> A, int k){
        int l = 0, r = A.size()-1;
        while(l <= r){
        int mid = l + (r-l)/2;
        if(A[mid] == k)
            return true;
        else if(A[mid] > k)
            r = mid - 1;
        else
            l = mid + 1;
        }
        return false;
    }
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int r = matrix.size();
        if(r == 0)
            return false;
        int c = matrix[0].size();
        if(c == 0)
            return false;
        if(target > matrix[r-1][c-1])
            return false;
        while(i < matrix.size()){
            if(matrix[i][0] == target)
            return true;
            if(matrix[i][0] > target)
            break;
            i++;
        }
        if(i == 0){
            // cout<<"in"<<endl;
            return false;        
        }
        return binSearch(matrix[i-1], target);
    }
};

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of cin.
    // Write your code here
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

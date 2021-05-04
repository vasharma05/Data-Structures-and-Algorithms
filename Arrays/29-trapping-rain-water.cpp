#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int A[], int n){
        // Code here
        int left[n];
    
        int right[n];
    
        int water = 0;
    
        left[0] = A[0];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], A[i]);
    
        right[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], A[i]);
    
        for (int i = 0; i < n; i++)
            water += min(left[i], right[i]) - A[i];
    
        return water;
        
    }
};


int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of cin.
    // Write your code here
    int t;
    //testcases
    fin >> t;
    
    while(t--){
        int n;
        
        //size of Aay
        fin >> n;
        
        int a[n];
        
        //adding elements to the Aay
        for(int i =0;i<n;i++){
            fin >> a[i];            
        }
        // printAay(a, n, "");
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
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

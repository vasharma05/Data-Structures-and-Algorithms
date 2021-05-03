#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int A[], int n)
    {
      //Your code here
      int cnt = 1;
      int res = 0;
      sort(A, A+n);
      printArray(A, n, "");
      for(int i = 1; i < n; i++ ){
        if(A[i] == A[i-1] + 1)
            cnt++;
        else if(A[i] != A[i-1])
            cnt = 1;
        res = max(res, cnt);
      }
      return res;
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
        int A[n];
        inputArray(A, n);
        Solution ob;
        cout<<ob.findLongestConseqSubseq(A, n)<<endl;
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

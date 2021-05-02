#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> res;
            int i = 0, j = 0, k = 0;
            while(i<n1 && j<n2 && k<n3){

                if(i > 0 && A[i] == A[i-1]){
                    i++;
                    continue;
                }
                
                if(j > 0 && B[j] == B[j-1]){
                    j++;
                    continue;
                }
                if(k > 0 && C[k] == C[k-1]){
                    k++;
                    continue;
                }
                
                int mn = A[i];
                mn = min(mn, B[j]);
                mn = min(C[k], mn);
                
                if(A[i] == mn && B[j] == mn && C[k] == mn)
                    res.push_back(mn);
                if(A[i] == mn)
                    i++;
                if(B[j] == mn)
                    j++;
                if(C[k] == mn)
                    k++;
            }
            return res;
        }

};


int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of cin.
    // Write your code here
    int t; fin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        fin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) fin >> A[i];
        for (int i = 0; i < n2; i++) fin >> B[i];
        for (int i = 0; i < n3; i++) fin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
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

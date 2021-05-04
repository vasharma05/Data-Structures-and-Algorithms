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
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A+n);
        for(int i = 0; i<n; i++){
            if(A[i] == A[i-1])
                continue;
            cout<<A[i]<<endl;
            int diff = X - A[i];
            int j = i+1, k = n-1;
            while(j < k){
                cout<<"\t"<<A[j]<<" "<<A[k]<<endl;
                if(j == i){
                    j++;
                    continue;
                }
                if(k == i){
                    k--;
                    continue;
                }
                if(A[j] + A[k] == diff){
                    return true;
                }else if(A[j] + A[k] < diff){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return false;
    }
};

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of fin.
    // Write your code here
    int T;
	fin>>T;
	while(T--)
	{
		int n,X;
		fin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			fin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
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

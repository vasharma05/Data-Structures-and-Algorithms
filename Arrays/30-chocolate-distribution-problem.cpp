#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

void printVector(vector<long long> A){
    for(long long int i=0; i<A.size(); i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

class Solution{
    public:
    long long findMinDiff(vector<long long> A, long long n, long long m){
    //code
        sort(A.begin(), A.end());
        printVector(A);
        long long int i = 0, j = n-m;
        long long int res = INT_MAX;
        while(i+m-1 < n){
            res = min(res, A[i+m-1] - A[i]);
            i++;
        }
        return res;
    }   
};

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of fin.
    // Write your code here
    long long t;
	fin>>t;
	while(t--)
	{
		long long n;
		fin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			fin>>x;
			a.push_back(x);
		}
		
		long long m;
		fin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
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

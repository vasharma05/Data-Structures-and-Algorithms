#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

class Solution{
    int upperBound(vector<int> A){
        int l = 0, r = A.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(A[mid] <= 0)
                l = mid+1;
            else
                r = mid - 1;
        }
        return l;
    }
public:
	int rowWithMax1s(vector<vector<int> > A, int n, int m) {
	    // code here
	    int row = 0, one = upperBound(A[0]);
	    if(one == 0){
	        return 0;
	    }
	    for(int i = 0; i<n; i++){
	        if(A[i][one-1] == 1){
	            int temp = upperBound(A[i]);
    	        row = i;
    	        if(one == 0){
    	            return i;
    	        }
	        }
	        
	    }
	    if(one == m)
	        return -1;
	    return row;
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
        int r, c;
        fin>>r>>c;
        vector<vector<int>> A;
        for(int i=0; i<r; i++){
            vector<int> temp;
            for(int j = 0; j<c; j++){
                int te;
                fin>>te;
                temp.push_back(te);
            }
            A.push_back(temp);
        }
        Solution ob;
        cout<<ob.rowWithMax1s(A, r, c)<<endl;
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

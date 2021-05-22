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
    int binSearch(vector<int> A, int key){
        int l = 0, r = A.size()-1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(A[mid] <= key)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
    int median(vector<vector<int>> &m, int r, int c){
        // code here          
        int mn = INT_MAX, mx = INT_MIN;
        for (int i=0; i<r; i++)
        {
            mn = min(mn, m[i][0]);
            mx = max(mx, m[i][c-1]);
        }
    
        int desired = (r * c + 1) / 2;
        while (mn < mx)
        {
            int mid = mn + (mx - mn) / 2;
            int place = 0;

    
            // Find count of elements smaller than mid
            for (int i = 0; i < r; ++i){
                place += binSearch(m[i], mid);
            }
                
            if (place < desired)
                mn = mid + 1;
            else
                mx = mid;
        }
        return mn;
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
        cout<<ob.median(A, r, c)<<endl;
        // printVector(A[0], "");
        // cout<<ob.binSearch(A[0], 5)<<endl;
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

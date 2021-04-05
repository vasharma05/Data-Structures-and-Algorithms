#include<bits/stdc++.h>
#include<fstream>
// #include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();

class Solution{
  public:
    void findMinJumps(int A[], int n, int ind, int &ans, int steps){
        if(A[ind] == 0){
            return;
        }
        if(ind + A[ind] >= n-1){
            // cout<<"Returning ind "<<ind<<" & i "<<A[ind]<<endl;
            ans = min(ans, steps);
            return;
        }
        for(int i = (A[ind] + ind <= n-1) ? A[ind] : 0 ; i > 0; i--){
            // cout<<"ind "<<ind<<" & i "<<i<<endl;
            if((ind + i) == n-1){
                // cout<<"Cleared ind "<<ind<<" & i "<<i<<endl;
                ans = min(ans, steps);
                break;
            }
            if(ind + i < n-1){
                findMinJumps(A, n, ind + i, ans, steps + 1);
            }
        }
        
    }
    int minJumps(int A[], int n){
        // Your code here
        // cout<<"Running"<<endl;
        int ans = INT_MAX;
        int steps = 1;
        findMinJumps(A, n, 0, ans, steps);
        return ans;
    }
};

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of fin.
    // Write your code here
    int t;
    fin>>t;
    while(t--)
    {
        int n,i,j;
        fin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            fin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}


// Common functions
void load_file_io(){
    fin.open("../input_output/input.txt");
}
#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();

class Solution{
  public:
    int findDuplicate(int nums[], int n){
        // Your code here
        // cout<<"Running"<<endl;
        for(int i = 0; i<n+1; i++){
            if(nums[abs(nums[i])] < 0)
                return abs(nums[i]);
            else
                nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        return 0;
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
        int arr[n+1];
        for(int i=0; i<n+1; i++)
            fin>>arr[i];
        Solution obj;
        cout<<obj.findDuplicate(arr, n)<<endl;
    }
    return 0;
}


// Common functions
void load_file_io(){
    fin.open("../input_output/input.txt");
}
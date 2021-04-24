#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int A[], int n){
        
        // Your code here
        int sum_so_far = A[0];
        int largest_sum_so_far = A[0];
        for(int i=1; i<n; i++){
            if(sum_so_far < 0)
                sum_so_far = 0;
            sum_so_far += A[i];
            // cout<<"sum_so_far "<<sum_so_far<<endl;
            // cout<<"largest_sum_so_far "<<largest_sum_so_far<<endl;
            if(sum_so_far >= largest_sum_so_far)
                largest_sum_so_far = sum_so_far;
        }
        return largest_sum_so_far;
        
    }
};

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of cin.
    // Write your code here
    int t,n;
    
    fin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        fin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            fin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
    return 0;
}


// Common functions
void load_file_io(){
    fin.open("../input_output/input.txt");
}
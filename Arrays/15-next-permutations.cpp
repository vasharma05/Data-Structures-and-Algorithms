#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)
        return;
    int i = n-2;
    while(i >=0 && nums[i] >= nums[i+1]){
        i--;
    }
    if(i < 0 ){
        int l = 0, r = n-1;
        while(l<r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        return;
    }
    for(int j = n-1; j>i; j--){
        if(nums[j] > nums[i]){
            swap(nums[i], nums[j]);
            break;
        }
    }    
    i++;
    int j = n-1;
    while(i<j){
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
    return;
}

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of cin.
    // Write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums;
        for(int i = 0; i<n; i++){
            int c;
            cin>>c;
            nums.push_back(c);
        }
        nextPermutation(nums);
        printVector(nums, "");

    }
}


// Common functions
void load_file_io(){
    fin.open("../input_output/input.txt");
}
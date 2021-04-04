#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();

class Solution {
  public:
    int getMinDiff(int A[], int n, int k) {
        // code here
        sort(A, A+n);
        int small;
        small = A[0] + k;
        int big = A[n-1] - k;
        if(big < small)
            swap(small, big);
        for(int i=1; i<n-1; i++){
            int subtract = A[i] - k;
            int add = A[i] + k;
            if(add < big || subtract > small)
                continue;
            if(big - subtract <= add - small)
                small = subtract;
            else
                big = add;
        }
        return min(A[n-1] - A[0], big - small);
    }
};

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of cin.
    // Write your code here
    int t;
    fin >> t;
    while (t--) {
        int n, k;
        fin >> k;
        fin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            fin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}


// Common functions
void load_file_io(){
    fin.open("../input_output/input.txt");
}
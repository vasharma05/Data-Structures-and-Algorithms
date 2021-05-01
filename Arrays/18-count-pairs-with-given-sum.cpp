#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

int findPairs(vector<int> A, int i){
    int l = 0, r = A.size();
    while(l<=r){
        int mid = l + (r-l)/2;
        if(A[mid] == i)
            return A.size() - mid - 1;
        else if(A[mid] > i){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return A.size() - l;
}

class Solution{   
public:
    int getPairsCount(int A[], int n, int k) {
        // code here
        // printArray(A, n, "");
        map<int, vector<int>> M;
        int cnt = 0;
        // printArray(A, n, "");
        for(int i = 0; i < n; i++){
            M[A[i]].push_back(i);
        }
        // printArray(A, n, "");
        for(int i = 0; i<n ; i++){
            if((A[i] != INT_MIN) && (M.find(k - A[i]) != M.end())){
                int temp =  max(findPairs(M[k - A[i]], i), 0);
                // cout<<A[i]<<" "<<temp<<endl;
                cnt += temp;
            }
        }
        // printArray(A, n, "");
        return cnt;
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
        fin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            fin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
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

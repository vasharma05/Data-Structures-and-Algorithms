#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

vector<int> findFactorial(int N){
    vector<int> res;
    res.push_back(1);
    int x=2;
    int carry = 0;
    for(; x<=N;x++){
        carry = 0;
        for(int i = 0; i<res.size(); i++){
            int ans = res[i]*x + carry;
            res[i] = ans%10;
            carry = ans/10;
        }
        while(carry){
            res.push_back(carry%10);
            carry /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of cin.
    // Write your code here
    int t;
    fin>>t;
    while(t--){
        int n;
        fin>>n;
        vector<int> res = findFactorial(n);
        for(int i = 0; i<res.size(); i++){
            cout<<res[i];
        }
        cout<<endl<<endl;
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

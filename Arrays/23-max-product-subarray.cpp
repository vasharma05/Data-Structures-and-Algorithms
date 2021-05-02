#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

long long maxProduct(int *A, int n) {
    // code here
    vector<vector<int>> neg_partitions;
    vector<int> temp;
    vector<int> zeros;
    for(int i = 0; i<n; i++){
        if(A[i] < 0)
            temp.push_back(A[i]);
        else if(A[i] == 0){
            neg_partitions.push_back(temp);
            temp.clear();
            zeros.push_back(i);
        }
    }
    neg_partitions.push_back(temp);

    // cout<<"neg_partitions: ["<<endl;
    // for(int i = 0; i < neg_partitions.size(); i++){
    //     cout<<"\t"<<"[ ";
    //     for(int j=0; j<neg_partitions[i].size(); j++){
    //         cout<<neg_partitions[i][j]<<" ";
    //     }
    //     cout<<"],"<<endl;
    // }
    // cout<<"]"<<endl;

    vector<vector<int>> sub_partitions;
    vector<int> sub;
    long long int prod = 1;
    for(int i = 0; i<n; i++){
        if(A[i] == 0){
            sub.push_back(prod);
            sub_partitions.push_back(sub);
            sub.clear();
            prod = 1;
        }else if(A[i] < 0){
            sub.push_back(prod);
            prod = 1;
        }else{
            prod *= A[i];
        }
    }
    sub.push_back(prod);
    sub_partitions.push_back(sub);

    // cout<<"sub_partitions: ["<<endl;
    // for(int i = 0; i < sub_partitions.size(); i++){
    //     cout<<"\t"<<"[ ";
    //     for(int j=0; j<sub_partitions[i].size(); j++){
    //         cout<<sub_partitions[i][j]<<" ";
    //     }
    //     cout<<"],"<<endl;
    // }
    // cout<<"]"<<endl;

    int max_prod = INT_MIN;
    for(int i = 0; i < neg_partitions.size(); i++){
        prod = 1;
        if(neg_partitions[i].size() % 2 == 0){
            int j;
            for(j = 0; j < neg_partitions[i].size(); j++){
                prod *= neg_partitions[i][j] * sub_partitions[i][j];
            }
            prod *= sub_partitions[i][j];
            max_prod = max_prod > prod ? max_prod : prod;
        }else{
            if(neg_partitions[i][0] * sub_partitions[i][0] < neg_partitions[i][neg_partitions[i].size() - 1] * sub_partitions[i][sub_partitions[i].size() - 1])
                prod *= neg_partitions[i][0] * sub_partitions[i][0];
            int j;
            for(j = 1; j < neg_partitions[i].size() - 1; j++){
                prod *= neg_partitions[i][j] * sub_partitions[i][j];
            }
            prod *= sub_partitions[i][j];
            if(neg_partitions[i][0] * sub_partitions[i][0] >= neg_partitions[i][neg_partitions[i].size() - 1] * sub_partitions[i][sub_partitions[i].size() - 1])
                prod *= neg_partitions[i][neg_partitions[i].size() - 1] * sub_partitions[i][sub_partitions[i].size() - 1];
            max_prod = max_prod > prod ? max_prod : prod;
        }
    }
    return neg_partitions.size() > 1 
        ?   max_prod > 0
            ? max_prod
            : 0 
        : max_prod;
}

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of cin.
    // Write your code here
    int t;
    fin >> t;
    while (t--) {
        int n, i;
        fin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            fin >> arr[i];
        }
        auto ans = maxProduct(arr, n);
        cout << ans << "\n";
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

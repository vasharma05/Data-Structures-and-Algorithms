#include<bits/stdc++.h>
#include "common.h"
using namespace std;

void printVector(vector<int> A, string name = ""){
    cout<<endl<<"Vector "<<name<<" with size "<<A.size()<<" :";
    for(int i=0; i<A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl<<endl;
}

void printArray(int A[], int n, string name = ""){
    cout<<endl<<"Array "<<name<<" with size "<<n<<" :";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl<<endl;
}
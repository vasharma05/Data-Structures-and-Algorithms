// link: https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1#
#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();

void swap(int &a, int &b){
    int z = a;
    a = b;
    b = z;
}

void rotate(int A[], int n)
{
    for(int i=1; i<n; i++){
        swap(A[0], A[i]);
    }
}

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of fin.
    // Write your code here 
    int t;
    fin>>t;
    while(t--)
    {
        int n;
        fin>>n;
        int a[n] , i;
        for(i=0;i<n;i++)
        fin>>a[i];
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
} 


// Common functions
void load_file_io(){
    fin.open("../input_output/input.txt");
}
#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();
void inputArray(int* , int);
void inputVector(vector<int>& , int);

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > M, int r, int c) 
    {
        // code here 
        int dir = 0, top = 0, left = 0, right = c, bottom = r;
        vector<int> res;
        while(top < bottom && left < right){
            if(dir == 0){
                int i = left;
                while(i<right){
                    res.push_back(M[top][i]);
                    i++;
                }
                top += 1;
                dir = 1;
            }else if(dir == 1){
                int i = top;
                while(i < bottom){
                    res.push_back(M[i][right-1]);
                    i++;
                }
                right--;
                dir = 2;
            }else if(dir == 2){
                int i = right-1;
                while(i >= left){
                    res.push_back(M[bottom-1][i--]);
                }
                bottom--;
                dir = 3;
            }else if(dir == 3){
                int i = bottom-1;
                while(i >= top){
                    res.push_back(M[i--][left]);
                }
                dir = 0;
                left++;
            }
        }
        return res;
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
        int r,c;
        fin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                fin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
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

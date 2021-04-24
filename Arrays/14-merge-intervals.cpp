#include<bits/stdc++.h>
#include<fstream>
#include "../commons/common.h"
using namespace std;

ifstream fin;
void load_file_io();

bool compareInterval(vector<int> A, vector<int> B){
  return A[0] < B[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if(intervals.size() <= 1)
        return intervals;
      sort(intervals.begin(), intervals.end(), compareInterval);
      vector<vector<int>> res;
      res.push_back(intervals[0]);
      for(int j = 1; j < intervals.size();){
        vector<int> last = res[res.size()-1];
        if(last[1] >= intervals[j][0]){
          res[res.size()-1][0] = min(last[0], intervals[j][0]);
          res[res.size()-1][1] = max(last[1], intervals[j][1]);
        }else{
          res.push_back(intervals[j]);
        }
        j++;
      }
      return res;
    }
};

int main(){
    // comment this function to use standard I/O.
    load_file_io();

    // Use fin instead of cin.
    // Write your code here
}


// Common functions
void load_file_io(){
    fin.open("../input_output/input.txt");
}
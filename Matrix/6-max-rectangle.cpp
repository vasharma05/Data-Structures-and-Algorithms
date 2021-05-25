#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include<fstream>
using namespace std;

#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef unsigned int uint; 
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int ll;
typedef unsigned long long int ull;

ifstream fin;
void load_file_io(){
  // fin.open("../input_output/input.txt");
}
void inputArray(int* , int);
void inputVector(VI& , int);
void printVector(VI, string);
void printArray(int*, int, string);

// Boilerplate ends

class Solution{
    int maxHist(int row[], int m)
{
    // Create an empty stack.
    // The stack holds indexes of
    // hist[] array/ The bars stored
    // in stack are always
    // in increasing order of their heights.
    stack<int> result;
 
    int top_val; // Top of stack
 
    int max_area = 0; // Initialize max area in current
    // row (or histogram)
 
    int area = 0; // Initialize area with current top
 
    // Run through all bars of given histogram (or row)
    int i = 0;
    while (i < m) {
        // If this bar is higher than the bar on top stack,
        // push it to stack
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
 
        else {
            // If this bar is lower than top of stack, then
            // calculate area of rectangle with stack top as
            // the smallest (or minimum height) bar. 'i' is
            // 'right index' for the top and element before
            // top in stack is 'left index'
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
 
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
 
    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
 
        max_area = max(area, max_area);
    }
    return max_area;
}
  public:
    int maxArea(int A[INT16_MAX][INT16_MAX], int R, int C) {
        // Your code here
        int result = maxHist(A[0], C);
 
        // iterate over row to find maximum rectangular area
        // considering each row as histogram
        for (int i = 1; i < R; i++) {
     
            for (int j = 0; j < C; j++)
     
                // if A[i][j] is 1 then add A[i -1][j]
                if (A[i][j])
                    A[i][j] += A[i - 1][j];
     
            // Update result if area with current row (as last
            // row) of rectangle) is more
            result = max(result, maxHist(A[i], C));
        }
     
        return result;
    }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  load_file_io();
  /*
  To use file input:
  -> Add file path to load_file_io in line 67
  -> Use fin everywhere instead of cin
  */
  
  // Write Code here

  int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        int M[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
  
  // Code ends here
  return 0;
}


// Boilerplate code starts

void inputArray(int A[], int n){
  for(int i = 0; i<n; i++){
    cin >> A[i];
  }
}

void inputVector(VI& A, int n){
  for(int i = 0; i<n; i++){
    int c;
    cin >> c;
    A.push_back(c);
  }
}

void printVector(VI A, string name = ""){
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

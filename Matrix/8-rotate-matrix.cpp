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

#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) FOR(i, 0, j, 1)
#define rrep(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
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
void inputVector(vi& , int);
void printVector(vi, string);
void printArray(int*, int, string);

// Boilerplate ends

void solution(vvi &A, int n){
  rep(i, n/2){
    FOR(j, i, n-i-1, 1){
      int temp = A[i][j];
      A[i][j] = A[n - 1 - j][i];
      A[n - 1 - j][i] = A[n - 1 - i][n - 1 - j];
      A[n - 1 - i][n - 1 - j] = A[j][n - 1 - i];
      A[j][n - 1 - i] = temp;
    }
  }
}

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

  int t;
  scd(t);
  while (t){
    int n;
    scd(n);
    vvi A;
    rep(i, n)
      inputVector(A[i], n);
    solution(A, n); 
    rep(i, n)
      printVector(A[i], "");
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

void inputVector(vi& A, int n){
  for(int i = 0; i<n; i++){
    int c;
    cin >> c;
    A.push_back(c);
  }
}

void printVector(vi A, string name = ""){
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

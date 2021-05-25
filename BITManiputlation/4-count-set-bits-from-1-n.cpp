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
typedef long long int int64;
typedef unsigned long long int uint64;

ifstream fin;
void load_file_io(){
	fin.open("../input_output/input.txt");
}
void inputArray(int* , int);
void inputVector(VI& , int);
void printVector(VI, string);
void printArray(int*, int, string);

// Boilerplate ends

int solution(int n){
	n++;
  int i = 1;
  int res = 0;
  while(i < n){
      res += (n/(2*i))*(i);
      if((n/i)%2)
          res += n%i;
      i *= 2;
  }
  return res;
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
	SCD(t);
	while(t--){
		int n;
		SCD(n);
		cout<<solution(n)<<endl;
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

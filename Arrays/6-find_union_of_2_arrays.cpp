// Link: https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int A[], int n, int B[], int m)  {
        //code here
        unordered_map<int, bool> M;
        int i = 0;
        int j = 0;
        int count = 0;
        while(i<n || j<m){
            if(i<n){
                if(M.find(A[i]) == M.end()){
                    // cout<<"A "<<A[i]<<endl;
                    count++;
                    M[A[i]] = true;
                }
            }
            if(j<m){
                if(M.find(B[j]) == M.end()){
                    // cout<<"B "<<B[j]<<endl;
                    count++;
                    M[B[j]] = true;
                }   
            }
            i++;
            j++;
            
        }
        return count;
    }
    int doIntersection(int A[], int n, int B[], int m)  {
        //code here
        unordered_map<int, bool> M;
        int* sorted;
        int* unsorted;
        if(n<m){
            sort(A, A+n);
            sorted = A;
            unsorted = B;
        }else{
            sort(B, B+m);
            sorted = B;
            unsorted = A;
        }
        int count = 0;
        for(int i = 0; i < max(n, m); i++){
            int j = 0, k = min(n,m);
            bool found = false;
            while(j<=k){
                int mid = j + (k-j)/2;
                if(sorted[mid] == unsorted[i]){
                    if(M.find(unsorted[i]) == M.end())
                        found = true;
                    break;
                }else if(sorted[mid] > unsorted[i]){
                    k = mid - 1;
                }else{
                    j = mid + 1;
                }
            }
            if(found){
                M[unsorted[i]] = true;
                // cout<<unsorted[i]<<endl;
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    cout << ob.doIntersection(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
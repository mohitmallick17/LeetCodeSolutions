// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        int curD=0, maxD=0;
        
        for(int i=0;i<N and curD < N-1;i++){
            maxD = max(maxD, i+A[i]);
            if(i==curD)
                curD=maxD;
            if(maxD==i and maxD < N-1)return false;
            // cout << curD << ' ' << maxD << '\n';
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
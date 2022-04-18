// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    // long long mod = 1e9 + 7;
  public:
    long long karyTree(int k, int m) {
        // long long res=1;
        
        // while(m > 0){
        //     if()
        // }
        long long res = 1, k1 = k, mod = 1e9+7;
    while(m) {
        if(m&1) {
            res *= k1;
            res %= mod;
            m--;
        } else {
            k1 = k1*k1;
            k1 %= mod;
            m /= 2;
        }
    }
    return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends
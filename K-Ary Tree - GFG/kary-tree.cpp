// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    long long mod = 1e9 + 7;
  public:
    long long karyTree(int k, int m) {
        long long res=1, kk=k;
        
        while(m > 0){
            if(m%2 == 1){
                res = (res*kk)%mod;
                m--;
            }else{
                kk = (kk*kk)%mod;
                m/=2;
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
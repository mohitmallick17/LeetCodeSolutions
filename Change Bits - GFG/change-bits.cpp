// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
int bits(int N){
        int cnt=0;
        while(N)
            N>>=1,cnt++;
        return cnt;
    }
    vector<int> changeBits(int N) {
        int x = bits(N);
        x=(1<<x)-1;
        return {x-N,x};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends
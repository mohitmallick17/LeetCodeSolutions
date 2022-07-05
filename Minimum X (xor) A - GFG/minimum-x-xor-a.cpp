// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
    int getBitCount(int n){
        int cnt=0;
        for(int i=0;i<32;i++)cnt += ((n>>i)&1);
        return cnt;
    }
  public:
    int minVal(int a, int b) {
        int setBits = getBitCount(b);
        int ans = 0;
        for(int i=31;i>=0 and setBits>0;i--){
            int bit = ((a>>i)&1);
            if(bit==1){
                ans |= (1<<i);
                setBits--;
            }
        }
        for(int i=0;i<32 and setBits>0;i++){
            int bit = ((ans>>i)&1);
            if(bit==0){
                ans |= (1<<i);
                setBits--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends
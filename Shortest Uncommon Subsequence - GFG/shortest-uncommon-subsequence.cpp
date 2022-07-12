// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int dp[501][501];
    int solve(int i, int j, string &s, string &t){
        if(i==s.size())return 501;
        if(j==t.size())return 1;
        if(dp[i][j] != -1)return dp[i][j];
        int k;
        for(k=j;k<t.size();k++){
            if(s[i]==t[k])break;
        }
        if(k==t.size())return dp[i][j]=1;
        return dp[i][j]=min(solve(i+1, j, s, t), 1+solve(i+1,k+1,s,t));
    }
  public:
    int shortestUnSub(string S, string T) {
        memset(dp, -1, sizeof dp);
        int ans = solve(0,0,S,T);
        return ans>500 ? -1:ans; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long mod = 1e9 + 7;
    long long solve(int idx, string &s, vector<long long> &dp){
        if(idx == s.size())return 1LL;
        if(dp[idx] != -1)return dp[idx];
        if(s[idx] == '0')return 0LL;
        long long ans = solve(idx+1, s, dp);
        if(idx+1 < s.size() and (s[idx]=='1' or (s[idx]=='2' and s[idx+1] <= '6')))ans = (ans + solve(idx+2, s, dp))%mod;
        return dp[idx] = ans;
    }
	public:
		int CountWays(string str){
		    vector<long long> dp(str.size(), -1);
		    return solve(0,str, dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
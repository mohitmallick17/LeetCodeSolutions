class Solution {
    int solve(int idx, string &s, vector<int> &dp){
        if(idx>=s.size())return 1;
        if(s[idx]=='0')return 0;
        if(dp[idx] != -1)return dp[idx];
        int ways = solve(idx+1, s,dp);
        if(idx+1 < s.size() && ((s[idx]=='1') or (s[idx]=='2' and s[idx+1]<='6')))
            ways += solve(idx+2, s,dp);
        return dp[idx]=ways;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return solve(0, s, dp);
    }
};
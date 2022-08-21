class Solution {
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i<0 and j<0)return true;
        if(i<0){
            for(int x=j;x>=0;x--){
                if(p[x] != '*')return false;
            }
            return true;
        }
        if(j<0)return false;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if(s[i]==p[j] or p[j]=='?')
            return dp[i][j] = solve(i-1,j-1,s,p,dp);
        else if(p[j]=='*'){
            return dp[i][j] = solve(i-1, j, s, p,dp) or solve(i, j-1, s, p,dp);
        }else
            return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return solve(s.size()-1, p.size()-1, s, p, dp);
    }
};
class Solution {
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i==0 and j==0)return true;
        if(i==0){
            for(int x=j;x>0;x--){
                if(p[x-1] != '*')return false;
            }
            return true;
        }
        if(j==0)return false;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if(s[i-1]==p[j-1] or p[j-1]=='?')
            return dp[i][j] = solve(i-1,j-1,s,p,dp);
        else if(p[j-1]=='*'){
            return dp[i][j] = solve(i-1, j, s, p,dp) or solve(i, j-1, s, p,dp);
        }else
            return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));

        dp[0][0]=true;
        
        for(int i=1;i<=m;i++)dp[i][0]=false;
        
        for(int j=1;j<=n;j++){
            bool ans = true;
            for(int x=j;x>0;x--){
                if(p[x-1] != '*'){
                    ans=false;
                    break;
                }
            }
            dp[0][j] = ans;
            
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] or p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                }else
                    dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};
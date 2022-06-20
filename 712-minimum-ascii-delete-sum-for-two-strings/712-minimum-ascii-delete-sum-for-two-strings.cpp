class Solution {
    
    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(dp[i][j] != -1)return dp[i][j];
        if(i==a.size() or j==b.size()){
            int cost = 0;
            for(int idx=i;idx<a.size();idx++)cost += a[idx];
            for(int idx=j;idx<b.size();idx++)cost += b[idx];
            
            return dp[i][j] = cost;
        }
        if(a[i] == b[j])
            return dp[i][j] = solve(i+1, j+1, a, b, dp);
        else
            return dp[i][j] = min(a[i] + solve(i+1, j, a, b, dp), b[j] + solve(i, j+1, a, b, dp));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solve(0, 0, s1, s2, dp);
    }
};
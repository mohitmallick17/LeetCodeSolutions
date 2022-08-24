class Solution {
    int solve(int idx, vector<int>& v, int d, vector<vector<int>> &dp){
        int n=v.size();
        if(idx==n and d==0)return 0;
        if(idx==n or d==0)return INT_MAX;
        
        if(dp[idx][d] != -1)return dp[idx][d];
        
        int mx = 0;
        int Sum = INT_MAX;
        
        for(int i=idx;i<n;i++){
            mx = max(mx, v[i]);
            int val = solve(i+1, v, d-1, dp);
            if(val != INT_MAX)
                Sum = min(Sum, mx + val);
        }
        return dp[idx][d]=Sum;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n < d)return -1;
        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        
        return solve(0,jobDifficulty,d,dp);
    }
};
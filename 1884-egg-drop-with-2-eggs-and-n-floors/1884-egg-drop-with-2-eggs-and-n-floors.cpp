class Solution {
    int solve(int n, vector<int>& dp){
        if(dp[n] == 0){
            for(int k=1;k<=n;k++){
                dp[n] = min((dp[n]==0 ? n : dp[n]), 1 + max(k-1, solve(n-k, dp)));
            }
        }
        return dp[n];
    }
public:
    int twoEggDrop(int n) {
        vector<int> dp(n+1, 0);
        return solve(n, dp);
    }
};
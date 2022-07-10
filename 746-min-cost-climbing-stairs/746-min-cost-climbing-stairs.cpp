class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1);
        dp[n]=0;
        dp[n-1]=cost.back();
        
        for(int i=n-2;i>=0;i--){
            dp[i] = min(dp[i+1], dp[i+2]) + cost[i];
        }
        return min(dp[0], dp[1]);
    }
};
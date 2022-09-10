class Solution {
    int solve(int idx, bool canBuy, int k, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(idx == prices.size() or k==0)return 0;
        if(dp[idx][k][canBuy] != -1)return dp[idx][k][canBuy];
        int ans;
        if(canBuy){
            int buy = -prices[idx] + solve(idx+1, false, k, prices, dp);
            int notBuy = solve(idx+1, true, k, prices, dp);
            ans = max(buy, notBuy);
        }else{
            int sell = prices[idx] + solve(idx+1, true, k-1, prices, dp);
            int notSell = solve(idx+1, false, k, prices, dp);
            ans = max(sell, notSell);
        }
        return dp[idx][k][canBuy]=ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(0,1,k,prices,dp);    
    }
};
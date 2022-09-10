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
    int maxProfit(int kk, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(kk+1, vector<int>(2, 0)));
        
        for(int idx=n-1;idx>=0;idx--){
            for(int k=1;k<=kk;k++){
                for(int canBuy=0;canBuy<=1;canBuy++){
                    // cout << idx << ' ' << k << ' ' << canBuy << '\n';
                    int ans;
                    if(canBuy){
                        int buy = -prices[idx] + dp[idx+1][k][0];
                        int notBuy = dp[idx+1][k][1];
                        ans = max(buy, notBuy);
                    }else{
                        int sell = prices[idx] + dp[idx+1][k-1][1];
                        int notSell = dp[idx+1][k][0];
                        ans = max(sell, notSell);
                    }
                    dp[idx][k][canBuy]=ans;
                }
            }
        }
        
        return dp[0][kk][1];  
    }
};
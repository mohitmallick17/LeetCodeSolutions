class Solution {
    int solve(int i, vector<vector<int>>& piles, vector<int> &idx, int k, vector<vector<int>> &dp){
        if(i==piles.size())
            return 0;
        if(dp[i][k] != -1)return dp[i][k];
        int res = 0;
                
        // skip coin
        res = solve(i+1, piles, idx, k, dp);
        
        // delete coin
        int coins = 0, tmp_sz=idx[i];
        for(int d=1;d<=k and tmp_sz+d <= piles[i].size();d++){
            coins += piles[i][idx[i]];
            idx[i]++;
            res = max(res, coins + solve(i+1, piles,idx,k-d, dp));
        }
        idx[i]=tmp_sz;
        
        return dp[i][k]=res;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> v(piles.size(), 0);
        vector<vector<int>> dp(piles.size(), vector<int>(k+1, -1));
        return solve(0, piles, v, k, dp);
    }
};
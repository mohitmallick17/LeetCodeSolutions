class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        long long dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        for(auto &p:prices)
            dp[p[0]][p[1]]=p[2];
        
        for(int w=1;w<=m;w++){
            for(int h=1;h<=n;h++){
                for(int a=1;a<=w;a++)
                    dp[w][h] = max(dp[w][h], dp[a][h]+dp[w-a][h]);
                for(int a=1;a<=h;a++)
                    dp[w][h] = max(dp[w][h], dp[w][a]+dp[w][h-a]);
            }
        }
        return dp[m][n];
    }
};
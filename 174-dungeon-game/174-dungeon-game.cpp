class Solution {
    int solve(int r, int c, int m, int n, vector<vector<int>>& v, vector<vector<int>> &dp){
        if(r == m or c == n)return INT_MAX;
        if(dp[r][c] != -1)return dp[r][c];
        int right =  solve(r, c+1, m, n, v, dp);
        int down =  solve(r+1, c, m, n, v, dp);
        if(right==INT_MAX && down==INT_MAX){
            // last cell
            return dp[r][c] = (v[r][c] < 0) ? -v[r][c]+1 : 1;
        }
        int ans=INT_MAX;
        if(right != INT_MAX){
            if(v[r][c] >= 0)
                ans = max(1, right-v[r][c]);
            else
                ans = -v[r][c] + right;
        }
        if(down != INT_MAX){
            int cur;
            if(v[r][c] >= 0)
                cur = max(1, down-v[r][c]);
            else
                cur = -v[r][c] + down;
            ans = min(ans, cur);
        }
        return dp[r][c]=ans;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(), n=dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0,0,m,n,dungeon,dp);
    }
};
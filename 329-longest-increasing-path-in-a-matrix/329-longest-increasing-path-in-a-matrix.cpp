class Solution {
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &g, int prev){
        if(i<0 or j<0 or i>=g.size() or j>=g[0].size() or prev >= g[i][j])return 0;
        // cout << i << ' ' << j << '\n';
        if(dp[i][j] != 0)return dp[i][j];
        
        return dp[i][j] = 1 + max({solve(i-1,j,dp,g,g[i][j]),solve(i+1,j,dp,g,g[i][j]),solve(i,j-1,dp,g,g[i][j]),solve(i,j+1,dp,g,g[i][j])});
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix){
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max(res, solve(i,j,dp,matrix,-1));
            }
        }
        return res;
    }
};
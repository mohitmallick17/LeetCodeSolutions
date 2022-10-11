class Solution {
    long long mod=1e9 + 7;
    long long solve(int i, int j, int k, int sum, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(i == grid.size() or j == grid[i].size())return 0;
        
        
        sum = (sum + grid[i][j])%k;
        
        if(i==grid.size()-1 and j==grid[i].size()-1){
            // last cell: "1" if sum%k==0 else "0"
            return sum==0;
        }
        
        if(dp[i][j][sum] != -1)return dp[i][j][sum];
        
        long long ans = (solve(i+1,j,k,sum,grid,dp) + solve(i,j+1,k,sum,grid,dp))%mod;
        
        return dp[i][j][sum] = ans;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        for(auto &x:grid){
            for(auto &y:x)
                y %= k;
        }
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0,0,k,0,grid,dp);
    }
};
/*
2 2 1
0 0 2
0 1 2

2 1    2
2 1/2  
2

0 0 0
0
0

*/
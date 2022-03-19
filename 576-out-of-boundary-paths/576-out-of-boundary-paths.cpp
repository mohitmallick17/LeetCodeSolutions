class Solution {
    vector<int> dir;
    long long mod = 1e9 + 7;
    int dp[51][51][51];
    
    long long solve(int i, int j, int moves, int m, int n){
        if(i < 0 or j < 0 or i>=m or j >= n)return 1;
        if(moves==0)return 0;
        if(dp[i][j][moves] != -1)return dp[i][j][moves];
        long long ans = 0;
        for(int d=0;d<4;d++){
            ans = (ans + solve(i+dir[d], j+dir[d+1], moves-1,m,n))%mod;
        }
        return dp[i][j][moves]=ans;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dir = {-1,0,1,0,-1};
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, maxMove, m ,n);
    }
};
class Solution {
    int m, n;
    int dfs(int i, int j, vector<vector<int>>& g){
        if(i < 0 or j<0 or i>=m or j>=n or g[i][j]==0)return 0;
        g[i][j]=0;
        return 1 + dfs(i, j+1, g) + dfs(i, j-1, g) + dfs(i-1, j, g) + dfs(i+1, j, g);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 or j==0 or i==m-1 or j==n-1)
                    dfs(i, j, grid);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    res += dfs(i, j, grid);
            }
        }
        return res;
    }
};
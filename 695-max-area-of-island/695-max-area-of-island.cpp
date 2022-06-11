class Solution {
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 or j < 0 or i==grid.size() or j==grid[0].size() or grid[i][j]!=1)return 0;
        int res = 1;
        grid[i][j]=-1;
        res += dfs(i, j-1, grid);
        res += dfs(i, j+1, grid);
        res += dfs(i-1, j, grid);
        res += dfs(i+1, j, grid);
        
        return res;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m=grid.size(), n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int cur = dfs(i, j, grid);
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
};
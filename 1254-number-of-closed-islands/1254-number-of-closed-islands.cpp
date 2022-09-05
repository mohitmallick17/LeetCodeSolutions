class Solution {
    bool dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 or j < 0 or i==grid.size() or j==grid[i].size() or grid[i][j]==1)return true;
        bool isBoundary = !(i==0 or j==0 or i==grid.size()-1 or j==grid[i].size()-1);
        grid[i][j]=1;
        bool a = dfs(i+1, j, grid), b=dfs(i-1, j, grid), c = dfs(i, j+1, grid), d = dfs(i, j-1, grid);
        
        return isBoundary && a && b && c && d;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0)ans += dfs(i,j,grid);
            }
        }
        return ans;
    }
};
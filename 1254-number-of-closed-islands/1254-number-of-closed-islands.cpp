class Solution {
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[i].size() or grid[i][j]==1)return 0; // out of bound / water
        grid[i][j] = 1; // mark it as water (visited)
        
        return 1 + dfs(i+1, j, grid) + dfs(i, j+1, grid) + dfs(i-1, j, grid) + dfs(i, j-1, grid);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i==0 or j==0 or i==grid.size()-1 or j==grid[i].size()-1)
                    dfs(i, j, grid);
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                res += (dfs(i, j, grid) > 0 ? 1 : 0);
            }
        }
        
        return res;
        
    }
};
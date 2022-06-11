class Solution {
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i < 0 or j < 0 or i==grid.size() or j==grid[0].size() or grid[i][j]!='1')return;
        grid[i][j]='.';
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m=grid.size(), n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }
};
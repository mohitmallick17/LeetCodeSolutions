class Solution {
    void dfs(int i, int j, vector<vector<int>>& g1, vector<vector<int>>& g2, bool &valid){
        if(i<0 or j<0 or i>=g2.size() or j>=g2[0].size() or g2[i][j]==0)return;
        
        if(g1[i][j]==0){
            valid=false;
            return;
        }
        g2[i][j]=0;
        
        dfs(i, j+1, g1, g2, valid);
        dfs(i, j-1, g1, g2, valid);
        dfs(i+1, j, g1, g2, valid);
        dfs(i-1, j, g1, g2, valid);

    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt=0;
        
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[i].size();j++){
                if(grid2[i][j]==0)continue;
                bool valid=true;
                dfs(i,j,grid1,grid2,valid);
                if(valid)cnt++;
            }
        }
        return cnt;
    }
};
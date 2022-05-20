class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
            return 0;
        bool flag=1;
        vector<vector<int>> paths(2, vector<int>(n, 0));
        for(int i=0;i<m;++i){
            flag = !flag;
            for(int j=0;j<n;++j){
                if(i==0 and j==0){
                    paths[flag][j] = obstacleGrid[i][j]==0;
                }else if(i==0){
                    paths[flag][j] = obstacleGrid[i][j]==0 ? paths[flag][j-1] : 0;                    
                }else if(j==0){
                    paths[flag][j] = obstacleGrid[i][j]==0 ? paths[1-flag][j] : 0;                    
                }else{
                    paths[flag][j] = obstacleGrid[i][j] ? 0 : paths[flag][j-1] + paths[1-flag][j];     
                }
            }
        }
        return paths[flag][n-1];
    }
};
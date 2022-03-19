class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> grid(n, vector<double>(n, 0.0)), nxt(n, vector<double>(n, 0.0));
        grid[row][column] = 1.0;
        
        vector<vector<int>> dirs {{1,2}, {-1,2}, {2,1}, {-2,1}, {1,-2}, {-1,-2}, {2,-1},{-2,-1}};
        
        for(int c=0;c<k;c++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==0)continue;
                    
                    for(auto d:dirs){
                        int x = i + d[0], y=j + d[1];
                        if(x>=0 and y>=0 and x<n and y<n){
                            nxt[x][y] += grid[i][j]/8.0;
                    ;    }
                    }
                }
            }
            grid=nxt;
            nxt = vector<vector<double>>(n, vector<double>(n));
        }
        double ans = 0.0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                ans += grid[i][j];
        }
        return ans;
    }
};
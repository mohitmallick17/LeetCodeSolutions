class Solution {
    // void swapRow(int r, )
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        long long res = (1 << (n-1))*m;
        
        for(int j=1;j<n;j++){
            int ones=0, zeros=0;
            for(int i=0;i<m;i++){
                if(grid[i][0]==0){
                    if(grid[i][j]==0)ones++;
                    else zeros++;
                    
                }else{
                    if(grid[i][j]==1)ones++;
                    else zeros++;                    
                }
            }
            if(ones < zeros){
                // need to flip this col
                swap(ones,zeros);
            }
            res += (1 << (n-1-j))*ones;
        }
        return res;
    }
};
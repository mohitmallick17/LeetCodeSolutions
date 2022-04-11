class Solution {
    int coordinateToIndex(int r, int c, int m, int n){
        return (n*r) + c;
    }
    pair<int, int> coordinateToIndex(int index, int m, int n){
        return {index/n, index%n};
    }
    
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx = (coordinateToIndex(i, j, m, n) + k)%(m*n);
                pair<int, int> p = coordinateToIndex(idx, m, n);
                int x=p.first, y=p.second;
                res[x][y]=grid[i][j];
            }
        }
        return res;
    }
};
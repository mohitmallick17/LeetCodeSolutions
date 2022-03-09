class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)
                    q.push({i, j});
                else
                    mat[i][j] = -1;
            }
        }
        vector<int> dirs{0, 1, 0, -1, 0};
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int x=dirs[d]+i;
                int y=dirs[d+1]+j;
                if(x>=0 and y>=0 and x<m and y<n and mat[x][y]==-1){
                    mat[x][y] = mat[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
        return mat;
    }
};
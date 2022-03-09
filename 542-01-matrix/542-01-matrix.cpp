class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    visited[i][j]=true;
                }        
            }
        }
        vector<vector<int>> dirs{{0,1}, {0,-1}, {1,0}, {-1, 0}};
        
        int dist = 0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                mat[i][j]=dist;
                for(auto &dir:dirs){
                    int x=dir[0]+i;
                    int y=dir[1]+j;
                    if(x>=0 and y>=0 and x<m and y<n and !visited[x][y]){
                        visited[x][y]=true;
                        q.push({x, y});
                    }
                }
            }
            dist++;
        }
        return mat;
    }
};
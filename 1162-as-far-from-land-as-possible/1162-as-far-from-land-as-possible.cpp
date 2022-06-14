class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<int> dirs{0,1,0,-1,0};
        int n=grid.size();
        queue<pair<int, int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)q.push({i, j});
            }
        }
        if(q.size()==0 or q.size()==n*n)return -1;
        
        int dist = 0;
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    int dx=x+dirs[i], dy=y+dirs[i+1];
                    if(dx < 0 or dy < 0 or dx==n or dy==n or grid[dx][dy]==1)continue;
                    grid[dx][dy]=1;
                    q.push({dx,dy});
                }
            }
            dist++;
        }
        
        return dist-1;
    }
};
class Solution {
    void bfs(vector<vector<int>>& v, queue<pair<int, int>> &q, vector<vector<bool>> &vis){
        vector<int> dirs{0,1,0,-1,0};
        int m=v.size(), n=v[0].size();
        
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            
            for(int d=0;d<4;d++){
                int x=i+dirs[d], y=j+dirs[d+1];
                if(x >=0 and y>=0 and x<m and y<n and !vis[x][y] and v[x][y]>=v[i][j]){
                    q.push({x, y});
                    vis[x][y]=1;
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
        int m=heights.size(), n=heights[0].size();
        queue<pair<int, int>> pq, aq;
        vector<vector<bool>> vis_p(m, vector<bool>(n, false)), vis_a(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++){
            pq.push({i, 0});
            aq.push({i, n-1});
            vis_p[i][0]=1;
            vis_a[i][n-1]=1;
        }
        for(int j=0;j<n;j++){
            pq.push({0, j});
            aq.push({m-1, j});
            vis_p[0][j]=1;
            vis_a[m-1][j]=1;
        }
        
        bfs(heights, pq, vis_p);
        bfs(heights, aq, vis_a);
        
        vector<vector<int>> res;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis_p[i][j] and vis_a[i][j])res.push_back({i, j});
            }
        }
        return res;        
    }
};
struct cmp{
    bool operator()(vector<int> const& a, vector<int> const& b){
        if(a[2] != b[2])
            return a[2] > b[2];
        if(a[0] != b[0])
            return a[0] > b[0];
        return a[1] > b[1];
    }    
};
class Solution {
    vector<int> dirs{0,1,0,-1,0};
public:
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        
        int m=forest.size(), n=forest[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(forest[i][j] > 1)pq.push({i,j,forest[i][j]});
            }
        }
        
        int steps = 0;
        vector<int> start{0,0};
        
        while(!pq.empty()){
            vector<int> cur = pq.top();
            pq.pop();
            
            int dist = solve(forest, start, cur, m, n);
            
            if(dist==-1)return -1;
            steps += dist;
            
            start[0] = cur[0], start[1] = cur[1];
        }
        return steps;
    }
    
    int solve(vector<vector<int>>& forest, const vector<int> &start, const vector<int> &end, int m, int n){
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        vis[start[0]][start[1]]=true;

        int steps = 0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [i,j] = q.front();
                q.pop();
                if(i==end[0] and j==end[1])return steps;
                
                for(int d=0;d<4;d++){
                    int x=i+dirs[d], y=j+dirs[d+1];
                    if(x<0 or y<0 or x>=m or y>=n or vis[x][y] or forest[x][y]==0)continue;
                    q.push({x, y});
                    vis[x][y]=true;
                }
            }
            steps++;
        }
        return -1;
    }
};
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int m=maze.size(), n=maze[0].size();
        queue<pair<int, int>> q;
        
        for(int i=0;i<m;i++){
            if(maze[i][0]=='.' and (e[0]!=i or e[1]!=0)){
                q.push({i, 0});
                maze[i][0] = 'v';
            }
            if(maze[i][n-1]=='.' and (e[0]!=i or e[1]!=n-1)){
                q.push({i, n-1});
                maze[i][n-1] = 'v';
            }
        }
        for(int i=0;i<n;i++){
            if(maze[0][i]=='.' and (e[0]!=0 or e[1]!=i)){
                q.push({0, i});
                maze[0][i] = 'v';
            }
            if(maze[m-1][i]=='.' and (e[0]!=m-1 or e[1]!=i)){
                q.push({m-1, i});
                maze[m-1][i] = 'v';
            }
        }
        int dist = 0;
        int dirs[] = {0,1,0,-1,0};
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [i, j] = q.front();
                if(i==e[0] and j==e[1])return dist;
                q.pop();
                for(int d=0;d<4;d++){
                    int x = i+dirs[d];
                    int y = j+dirs[d+1];
                    if(x<0 or y<0 or x==m or y==n or maze[x][y]!='.')continue;
                    q.push({x, y});
                    maze[x][y]='v';
                }
            }
            dist++;
        }
        return -1;
    }
};
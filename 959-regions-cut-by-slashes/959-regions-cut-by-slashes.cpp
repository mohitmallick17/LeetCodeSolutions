class Solution {
    void dfs(int i, int j, vector<vector<int>> &g){
        if(i<0 or j<0 or i==g.size() or j==g[i].size() or g[i][j]==1)return;
        g[i][j]=1;
        dfs(i+1, j, g);
        dfs(i-1, j, g);
        dfs(i, j+1, g);
        dfs(i, j-1, g);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>> graph(3*n, vector<int>(3*n, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/')
                    graph[3*i][3*j + 2] = graph[3*i + 1][3*j + 1] = graph[3*i + 2][3*j] = 1;
                else if(grid[i][j]=='\\')
                    graph[3*i][3*j] = graph[3*i + 1][3*j + 1] = graph[3*i + 2][3*j + 2] = 1;
            }
        }
        int res = 0;
        
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                if(graph[i][j]==0){
                    res++;
                    dfs(i,j,graph);
                }
            }
        }
        return res;
    }
};
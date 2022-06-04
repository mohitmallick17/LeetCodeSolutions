class Solution {
    vector<vector<int>> res;
    void dfs(int node, int parent, vector<int> adj[], vector<bool>& visited, int &timer, vector<int>& tin, vector<int>& low){
        visited[node]=true;
        tin[node]=low[node]=timer++;
        
        for(auto &nbr:adj[node]){
            if(nbr==parent)continue;
            else if(visited[nbr]){
                // back-edge: ancestor
                low[node] = min(low[node], tin[nbr]);
            }else{
                // forward edge: child
                dfs(nbr, node, adj, visited, timer, tin, low);
                low[node] = min(low[node], low[nbr]);
                if(low[nbr] > tin[node])
                    res.push_back({node, nbr});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // find bridges in a graph
        vector<int> adj[n];
        for(auto &con:connections){
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        
        vector<bool> visited(n, false);
        vector<int> tin(n), low(n);
        int timer=1;
        for(int i=0;i<n;i++){
            if(!visited[i])
                dfs(i, -1, adj, visited, timer, tin, low);
        }
        return res;
    }
};
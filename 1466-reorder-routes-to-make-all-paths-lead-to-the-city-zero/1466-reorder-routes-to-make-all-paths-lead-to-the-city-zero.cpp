class Solution {
    int dfs(int node, vector<bool>& vis, vector<int> adj[]){
        vis[node]=true;
        int count = 0;
        for(auto nbr:adj[node]){
            if(!vis[abs(nbr)]){
                count += dfs(abs(nbr), vis, adj) + (nbr > 0); // we need to find -ve edge. dest to src
                // but inverse is also possible, if d -> s is -ve, then s -> d is +ve. so insetead of finding 
                // if nbr -> node is -ve, just check if node -> nbr is +ve
            }
        }
        return count;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto &c:connections){
            int s = c[0];
            int d = c[1];
            adj[s].push_back(d);
            adj[d].push_back(-s); // mark as negative edge
        }
        vector<bool> vis(n, false);
        return dfs(0, vis, adj);
    }
};
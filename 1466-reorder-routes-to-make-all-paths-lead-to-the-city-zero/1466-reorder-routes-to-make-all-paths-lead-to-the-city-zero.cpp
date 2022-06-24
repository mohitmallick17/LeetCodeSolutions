class Solution {
    void dfs(int node, int par, vector<bool>& vis, vector<int> adj[], vector<unordered_set<int>> &directed, int &res){
        vis[node]=true;
        
        for(auto nbr:adj[node]){
            if(!vis[nbr]){
                if(!directed[nbr].count(node)){
                    // cout << node << " -- " << nbr << '\n';
                    res++;
                }
                dfs(nbr, par, vis, adj, directed, res);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<unordered_set<int>> directed(n, unordered_set<int>());
        for(auto &c:connections){
            int s = c[0];
            int d = c[1];
            adj[s].push_back(d);
            adj[d].push_back(s);
            directed[s].insert(d);
        }
        int count = 0;
        vector<bool> vis(n, false);
        dfs(0, -1, vis, adj, directed, count);
        return count;
    }
};
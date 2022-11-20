
class Solution {
    long long cost = 0;
    long long dfs(int root, int par, vector<int> adj[], int n, int seats){
        long long people = 1;
        
        for(auto &ch:adj[root]){
            if(ch != par)people += dfs(ch, root, adj, n, seats);
        }
        
        if(root != 0)
            cost += (long long)ceil(people/(1.0 * seats));
        
        return people;        
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int  n=roads.size() + 1;
        vector<int> adj[n];
        for(auto &r:roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        dfs(0, -1, adj, n, seats);
        
        return cost;
    }
};
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> degree(n, 0);
        vector<int> adj[n];
        for(auto &x:edges){
            degree[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                q.push(i);
                visited[i]=true;
            }
        }
        
        vector<set<int>> v(n);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node = q.front();
                q.pop();
                
                for(int nbr:adj[node]){
                    v[nbr].insert(node);
                    for(int x:v[node])
                        v[nbr].insert(x);
                    degree[nbr]--;
                    if(degree[nbr]==0 and visited[nbr]==false){
                        visited[nbr]=true;
                        q.push(nbr);
                    }
                }
            }
        }
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++){
            res[i] = vector<int>(v[i].begin(), v[i].end());
        }
        return res;
    }
};
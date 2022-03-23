class Solution {
    bool isIntersecting(vector<int>& a, vector<int>& b){
        long long distsq = 1LL*(a[0] - b[0])*(a[0] - b[0]) + 1LL*(a[1] - b[1])*(a[1] - b[1]);
        long long rdist = 1LL*a[2]*a[2];
        if(distsq > rdist)
            return false;
        return true;
    }
    
    void buildGraph(vector<vector<int>>& bombs, map<int, vector<int>> &graph){
        int n=bombs.size();
        for(int i=0;i<n;i++){
            vector<int> nbrs;    
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(isIntersecting(bombs[i], bombs[j]))
                    nbrs.push_back(j);
            }
            graph[i] = nbrs;
        }
    }
    int bfs(int src, map<int, vector<int>> &graph){
        queue<int> q;
        q.push(src);
        unordered_set<int> vis;
        vis.insert(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr:graph[node]){
                if(vis.find(nbr)==vis.end()){
                    q.push(nbr);
                    vis.insert(nbr);
                }
            }
        }
        return vis.size();
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        map<int, vector<int>> graph;
        buildGraph(bombs, graph);
        int res = 0;
        for(int i=0;i<n;i++){
            int count = bfs(i, graph);
            res = max(res, count);
        }
        return res;
    }
};
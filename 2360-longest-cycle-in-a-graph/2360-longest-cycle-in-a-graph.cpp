class Solution {
    int cycleLen=-1;
    void dfs(int node, vector<int>& edges, vector<bool> &visited, vector<bool> &stackNode, vector<int> &dist, int curDist){
        visited[node]=stackNode[node]=true;
        dist[node]=curDist;
        int neighbor=edges[node];
        if(neighbor!=-1){
            if(!visited[neighbor]){
                dfs(neighbor, edges, visited, stackNode, dist, curDist+1);
            }else if(stackNode[neighbor]){
                cycleLen = max(cycleLen, dist[node]-dist[neighbor]+1);
            }
        }
        stackNode[node]=false;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool> vis(n, false), stackNode(n, false);
        vector<int> dist(n);
        
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i, edges, vis, stackNode, dist, 0);
        }
        return cycleLen;
    }
};
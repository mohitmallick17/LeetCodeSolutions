class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1)return 0;
        
        int finalState = (1 << n) -1;
        vector<vector<int>> visited(n, vector<int>(finalState+1, 0));
        
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            q.push({i, (1 << i)});
        }
        
        int pathLen = 0;
        
        while(!q.empty()){
            pathLen++;
            int size=q.size();
            while(size--){
                int node = q.front().first;
                int node_key = q.front().second;
                q.pop();
                
                for(auto nbr:graph[node]){
                    int nbr_key = node_key | (1 << nbr);
                    if(visited[nbr][nbr_key])continue;
                    visited[nbr][nbr_key]=1;
                    if(nbr_key == finalState)return pathLen;
                    q.push({nbr, nbr_key});
                }
            }
        }
        return -1;
    }
};
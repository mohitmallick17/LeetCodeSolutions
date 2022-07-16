class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, unordered_map<int, int>> adj;
        for(auto &e:edges){
            adj[e[0]][e[1]] = adj[e[1]][e[0]] = e[2];
        }
        priority_queue<pair<int, int>> pq;
        pq.push({maxMoves, 0});
        unordered_map<int, int> seen;
        
        while(!pq.empty()){
            int move = pq.top().first, node = pq.top().second;
            pq.pop();
            
            if(!seen.count(node)){
                seen[node]=move; 
                for(auto &a:adj[node]){
                    int dist = a.second, nbr = a.first;
                    int move2 = move - dist - 1; // cur pos I am in - nodes b/w us - 1 (for nbr)
                    if(!seen.count(nbr) and move2 >= 0)
                        pq.push({move2, nbr});
                }
            }
        }
        int count = seen.size(); // atleast we can see all visited nodes
        
        for(auto &e:edges){
            int a = seen.find(e[0])==seen.end() ? 0 : seen[e[0]];
            int b = seen.find(e[1])==seen.end() ? 0 : seen[e[1]];
            count += min(a+b, e[2]);
        }
        return count;
    }
};
class Solution {
    vector<long long> dijkstra(int src, vector<pair<int, int>> adj[], int v){
        vector<long long> dist(v, LONG_MAX);
        dist[src] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            
            if(cost > dist[u])continue;
            for(auto &e:adj[u]){
                int v = e.first;
                int wt = e.second;
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<pair<int, int>> graph[n];
        vector<pair<int, int>> rev_graph[n];
        
        for(auto &e:edges){
            int s = e[0], d = e[1], w=e[2];
            graph[s].push_back({d, w});
            rev_graph[d].push_back({s, w});
        }
        vector<long long> d1 = dijkstra(src1, graph, n);
        vector<long long> d2 = dijkstra(src2, graph, n);
        vector<long long> d3 = dijkstra(dest, rev_graph, n);
        
        long long ans = LONG_MAX;
        
        for(int i=0;i<n;i++){
            if(d1[i]==LONG_MAX or d2[i]==LONG_MAX or d3[i]==LONG_MAX)continue;
            ans = min(ans, d1[i]+d2[i]+d3[i]);
        }
        
        return (ans == LONG_MAX) ? -1 : ans;
    }
};
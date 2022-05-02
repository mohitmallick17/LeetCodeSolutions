// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node]=1;
        
        int ans = 0;
        for(int nbr:adj[node]){
            if(!vis[nbr]){
                ans = max(ans, 1+dfs(nbr, adj, vis));
            }
        }
        return ans;
    }
public:
    int partyHouse(int N, vector<vector<int>> &adj){
        int dist=INT_MAX;
        for(int i=1;i<=N;i++){
            vector<bool> vis(N+1, false);
            int curD = dfs(i, adj, vis);
            dist = min(dist, curD);
        }
        return dist;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
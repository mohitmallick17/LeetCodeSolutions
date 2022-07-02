// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void dfs(int src, int dest, vector<int> adj[], int &ans){
        if(src==dest){
            ans++;
            return;
        }
        
        for(auto &nbr:adj[src]){
            dfs(nbr, dest, adj, ans);
        }
    }
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<int> adj[n];
	    for(auto &e:edges)
	        adj[e[0]].push_back(e[1]);
	    int ans = 0;
	    dfs(s,d,adj,ans);
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
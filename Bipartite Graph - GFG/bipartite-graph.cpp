// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool dfsCheck(int node, vector<int>adj[], vector<int> &colors, int c){
        colors[node] =  c;
        
        for(auto &nbr:adj[node]){
            if(colors[nbr]==-1){
                colors[nbr] = (c==0) ? 1 : 0;
                if(dfsCheck(nbr, adj, colors, colors[nbr]))return true;
            }else if(colors[nbr]==c)return true;
        }
        return false;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1 and dfsCheck(i, adj, color, 0))return false;
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
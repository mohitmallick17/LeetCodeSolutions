// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool relaxEdges(vector<int> &wt, vector<vector<int>> &edges){
        bool isRelaxed=false;
        
        for(auto &edge:edges){
            // u source, v destinatoin c = cost_of_edge(u,v)
            // check: dist_to_reach_u + cost_of_edge(u,v) < dist_to_reach_v
            int u = edge[0], v = edge[1], c = edge[2];
            if(wt[u] != INT_MAX and wt[u]+c < wt[v]){
                wt[v] = wt[u]+c;
                isRelaxed=true;
            }
        }
        // returns true if any of the edge distance got changed(reduced)
        return isRelaxed;
    }
public:
	int isNegativeWeightCycle(int n, vector<vector<int>> &edges){
	    vector<int> wt(n, INT_MAX);
	    
	    wt[0]=0; // source vertex, all other vertices have distance = INFINTY, initially
	    
	    // relax the edges N-1 times
	    for(int i=0;i<n-1;i++){
	        // if we cannot relax the edges already, there is no negative cycle
	        if(!relaxEdges(wt, edges))
	            return false;
	    }
	    // the fact that we reached here means we relaxed for N-1 times and each time some 
	    // edge's distance got reduced. now if we relax for Nth time & still we see that 
	    // some distance is reduced, we can confirm there is -ve weight cycle
	    return relaxEdges(wt, edges);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
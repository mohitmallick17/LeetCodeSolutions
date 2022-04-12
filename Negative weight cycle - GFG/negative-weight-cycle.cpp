// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool relaxEdges(vector<int> &wt, vector<vector<int>> &edges){
        bool isRelaxed=false;
        
        for(auto &edge:edges){
            int u = edge[0], v = edge[1], c = edge[2];
            if(wt[u] != INT_MAX and wt[u]+c < wt[v]){
                wt[v] = wt[u]+c;
                isRelaxed=true;
            }
        }
        return isRelaxed;
    }
public:
	int isNegativeWeightCycle(int n, vector<vector<int>> &edges){
	    vector<int> wt(n, INT_MAX);
	    wt[0]=0;
	    
	    for(int i=0;i<n-1;i++){
	        if(!relaxEdges(wt, edges))
	            return false;
	    }
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
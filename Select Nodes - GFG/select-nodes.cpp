//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    pair<int, int> solve(int node, int par, vector<int> adj[]){
        // returns ans {include node, dont include node}
        pair<int, int> res = {0,0};
        
        int children_inc = 0, children_exc = 0;
        bool isLeaf=true;
        for(auto &ch:adj[node]){
            if(ch == par)continue;
            auto x = solve(ch, node, adj);
            children_inc += x.first;
            children_exc += x.second;
            isLeaf=false;
        }
        res.first = children_exc + 1;
        res.second = min(children_inc, res.first);
        
        if(par == -1 && isLeaf)res.second=res.first;
        // cout << node << " : " << res.first << ", " << res.second << '\n';
        return res;
    }
  public:
    int countVertex(int N, vector<vector<int>>edges){
        vector<int> adj[N+1];
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        auto x = solve(1, -1, adj);
        return min(x.first, x.second);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
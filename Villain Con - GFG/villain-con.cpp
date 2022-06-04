// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    unordered_map<int, int> dp;
    int dfs(int node, vector<int> adj[]){
        if(dp.find(node)!=dp.end())return dp[node];
        int len = 1;
        
        for(auto nbr:adj[node]){
            len = max(len, 1+dfs(nbr, adj));
        }
        return dp[node]=len;
    }
public:
    int minColour(int N, int M, vector<int> mat[]) {
        // code here
        vector<int> adj[N+1], indegree(N+1, 0);
        
        for(int i=0;i<M;i++){
            adj[mat[i][0]].push_back(mat[i][1]);
            indegree[mat[i][1]]++;
        }
        
        queue<int> q;
        for(int i=1;i<=N;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        int res = 0;
        while(!q.empty()){
            res = max(res, dfs(q.front(), adj));
            q.pop();
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
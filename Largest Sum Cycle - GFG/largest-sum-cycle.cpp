//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  long long largestSumCycle(int n, vector<int> edges){
      vector<int> indegree(n, 0);
      for(auto &e:edges){
          if(e==-1)continue;
          indegree[e]++;
      }
      queue<int> q;
      for(int i=0;i<n;i++){
          if(indegree[i] == 0)q.push(i);
      }
      while(!q.empty()){
          auto node = q.front();
          q.pop();
          int par = edges[node];
          if(par == -1)continue;
          indegree[par]--;
          if(indegree[par] == 0)q.push(par);
      }
      long long res = -1;
      for(int i=0;i<n;i++){
          if(indegree[i]==0)continue;
          long long cur = 0;
          int node = i;
          while(indegree[node] != 0){
            //   cout << node << ' ';
              indegree[node]=0;
              cur += node;
              node = edges[node];
          }
        //   cout << '\n';
          res = max(res, cur);
      }
      return res;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
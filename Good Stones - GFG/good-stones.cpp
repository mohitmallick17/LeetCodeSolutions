//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    unordered_set<int> good;
    bool dfs(int idx, vector<int> &v, vector<bool> &vis, int n){
        if(idx < 0 or idx >= n or good.find(idx)!=good.end()){
            return true;
        }
        if(vis[idx])return false;
        vis[idx]=true;
        if(dfs(idx + v[idx], v, vis, n)){
            good.insert(idx);
            vis[idx]=false;
            return true;
        }
        return false;
        
    }
public:
    int goodStones(int n,vector<int> &arr){
        vector<bool> vis(n, false);
        
        for(int i=0;i<n;i++){
            dfs(i, arr, vis, n);
        }
        return good.size();
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    int findPar(int key, int par[]){
        if(key==par[key])return key;
        return par[key] = findPar(par[key], par);
    }
    public:
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int ranks[]){
        int u = findPar(a, par);
        int v = findPar(b, par);
        if(ranks[u] > ranks[v]){
            par[v]=u;
        }else if(ranks[v] > ranks[u]){
            par[u]=v;
        }else{
            par[v]=u;
            ranks[u]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int ranks[]){
        return findPar(x,par)==findPar(y,par);
    }
};

// { Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends
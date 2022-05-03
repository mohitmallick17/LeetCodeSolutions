// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    unordered_map<int, unordered_map<int, int>> dp;
    int solve(int idx, int x, vector<int> &arr, int N, int K){
        if(idx==N)return 0;
        if(dp.find(idx)!=dp.end() and dp[idx].find(x)!=dp[idx].end())return dp[idx][x];
        int pairs = ((x ^ arr[idx]) == K);
        
        pairs += solve(idx+1, x, arr, N, K) + solve(idx+1, x^arr[idx], arr, N, K);
        
        return dp[idx][x]=pairs;
    }
public:
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        return solve(0, 0, arr, N, K);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends
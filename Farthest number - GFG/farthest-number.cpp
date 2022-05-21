// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> A){
        //code here
        vector <int> v(N), r(N);
        v[N-1] = A[N-1];
        r[N-1] = -1;
        for(int i = N-2; i>=0; i--){
            auto it = 
            upper_bound(v.begin()+i+1, v.end(), A[i]-1);
            if(it == v.begin()+i+1)
                r[i] = -1;
            else
                r[i] = it-v.begin()-1;
            v[i] = min(v[i+1], A[i]);
        }
        return r;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends
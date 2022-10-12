//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){ 
          unordered_map<char, int> mp;
          for(int i=0;i<n;i++)mp[x[i]]=b[i];
          
          int ans=INT_MIN, cur=0;
          string cur_s, res;
          
          for(int i=0;i<w.size();i++){
              int asc = (mp.find(w[i]) != mp.end()) ? mp[w[i]] : (int)w[i];
              cur += asc;
              cur_s += w[i];
              
              if(cur > ans){
                  ans=cur;
                  res=cur_s;
              }
              if(cur < 0){
                  cur=0;
                  cur_s.clear();
              }
          }
          return res;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends
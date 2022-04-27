// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    #define ll long long int

long long int killinSpree(long long int n){
       ll s = 1;
      ll e = min(1e6,sqrt(n));
       ll ans = 1;
       
       while(s <= e){
           ll mid = (s+e)/2;
           
           ll sum = (mid*(mid+1)*(2*mid+1)) / 6;
           
           if(sum <= n){
               ans = mid;
               s = mid + 1;
           }
           else{
               e = mid - 1;
           }
       }
       
       return (ans);
   }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends
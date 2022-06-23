// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N){
	    long long ob=1, os=1, mod=1e9 + 7;
	    
	    for(int i=2;i<=N;i++){
	        long long nb = os;
	        long long ns = (ob + os)%mod;
	        ob=nb;
	        os=ns;
	    }
	    long long ans = (ob+os)%mod;
	    return (ans*ans)%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
    vector<bool> sieve(int n){
        vector<bool> s(n+1, true);
        for(int i=2;i<=n;i++){
            for(int j=i*2;j<=n;j+=i){
                s[j]=false;
            }
        }        
        return s;
    }
public:	
	
	int superPrimes(int n){
	    if(n < 5)return 0;
	    auto s=sieve(n);
	    
	    int res=0;
	    for(int i=5;i<=n;i++){
	        if(s[i] and s[i-2])res++;
	    }
	    return res;
	    
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        long long mod = 1e9+7;
        long long a = 0, b = 0, c = 0 ;
        for(char &ch:s){
            if(ch=='a')
                a = (2*a + 1)%mod;
            else if(ch=='b')
                b = (2*b + a)%mod;
            else
                c=(2*c + b)%mod;
        }
        return c;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends
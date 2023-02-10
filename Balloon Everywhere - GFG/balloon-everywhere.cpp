//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int b=0,a=0,l=0,o=0,n=0;
        for(char &c:s){
            if(c=='b')b++;
            else if(c=='a')a++;
            else if(c=='l')l++;
            else if(c=='o')o++;
            else if(c=='n')n++;
        }
        return min({b,a,l/2,o/2,n});
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
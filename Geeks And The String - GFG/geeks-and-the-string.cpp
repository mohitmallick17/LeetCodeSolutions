//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char> stk;
        for(char &c:s){
            if(stk.empty() or stk.top() != c)stk.push(c);
            else if(stk.top() == c)stk.pop();
        }
        string res;
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return (res.empty() ? "-1":res);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
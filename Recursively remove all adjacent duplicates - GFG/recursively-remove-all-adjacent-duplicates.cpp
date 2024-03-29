// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string remove(string s){
        string res = "";
        int n = s.length();
        
        int i=0;
        while(i<n){
            char c = s[i];
            int freq = 0;
            while(s[i] == c)
                freq++, i++;
            
            if(freq == 1)
                res += c;
        }
        
        if(res == s)
            return res;
        return remove(res);
        // stack<char> stk;
        // for(char &c:s){
        //     bool deleted=false;
        //     while(!stk.empty() and stk.top()==c){
        //         stk.pop();
        //         deleted=true;
        //     }
        //     if(!deleted)stk.push(c);
        // }
        // string res;
        // while(!stk.empty()){
        //     res += stk.top();
        //     stk.pop();
        // }
        // reverse(res.begin(), res.end());
        // return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends
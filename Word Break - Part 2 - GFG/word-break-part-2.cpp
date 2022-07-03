// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<string> res;
    
    void solve(int start, string &s, unordered_set<string>& st, string cur){
        if(start>=s.size()){
            res.push_back(cur);
            return;
        }
        string t;
        for(int i=start;i<s.size();i++){
            t += s[i];
            if(st.find(t) != st.end()){
                string newCur;
                if(!cur.empty())newCur = cur + " " + t;
                else newCur = t;
                solve(i+1, s, st, newCur);
            }
        }
    }
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s){
        unordered_set<string> st(dict.begin(), dict.end());
        solve(0, s, st, "");
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    bool isValid(string &s){
        if(s.size() & 1)return false;
        int n=s.size();
        
        for(int i=0, j=n/2;j<n;i++,j++){
            if(s[i] != s[j])return false;
        }
        return true;
    }                                                                       
  public:
    int minOperation(string s) {
        int cnt=0;
        while(s.size() > 0){
            if(isValid(s))return cnt + (s.size()/2) + 1;
            s.pop_back();
            cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends
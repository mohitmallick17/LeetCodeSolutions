//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        int i=0,j=0;
        int m=s.size(), n=t.size();
        
        while(i < m and j<n){
            if(t[j] == '0'){
                j++;
                continue;
            }
            
            int num=0;
            while(j<n and (t[j] >='0' and t[j]<='9')){
                num = (num*10) + (t[j]-'0');
                j++;
            }
            if(num == 0){
                if(s[i] != t[j])return 0;
                i++, j++;
            }else{
                i+=num;
            }
        }
        return (i==m and j==n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
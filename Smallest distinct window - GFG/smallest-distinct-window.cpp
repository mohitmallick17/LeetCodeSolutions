// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str){
        unordered_map<char, int> cnt;
        for(char &c:str)cnt[c]++;
        int words=cnt.size();
        cnt.clear();
        
        int res=str.size();
        
        for(int start=0, end=0;end<str.size();end++){
            cnt[str[end]]++;
            
            while(start <= end and cnt.size() == words){
                res = min(res, end-start+1);
                if(start==end)break;
                cnt[str[start]]--;
                if(cnt[str[start]]==0)cnt.erase(str[start]);
                start++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends
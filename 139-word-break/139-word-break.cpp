class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> found(n+1, false);
        found[0]=true;
        
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(found[j] and st.find(s.substr(j, i-j)) != st.end()){
                    found[i]=true;
                    break;
                }
            }
        }
        return found[n];
    }
};
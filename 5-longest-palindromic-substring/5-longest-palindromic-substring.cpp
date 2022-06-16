class Solution {
    int maxLen=0;
    string pd;
    void stretchString(int l, int r, const string& s){
        while(l>=0 and r<=s.size()-1 and s[l]==s[r])
            l--, r++;
        if(r-l-1 > maxLen){
            maxLen = r-l-1;
            pd = s.substr(l+1, r-l-1);
        }
    }
public:
    string longestPalindrome(string s) {
        for(int i=0;i<s.size();++i){
            stretchString(i, i, s);
            stretchString(i, i+1, s);
        }
        return pd;
    }
};
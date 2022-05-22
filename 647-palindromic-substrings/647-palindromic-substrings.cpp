class Solution {
    int countPD(string &s, int l, int r){
        int cnt=0;
        while(l>=0 and r<s.size() and s[l]==s[r]){
            l--, r++;
            cnt++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            res += countPD(s, i, i);
            res += countPD(s, i, i+1);
        }
        return res;
    }
};
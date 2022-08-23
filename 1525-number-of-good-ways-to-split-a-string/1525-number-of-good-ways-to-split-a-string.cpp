class Solution {
    bool isValid(vector<int>& a, vector<int> &b){
        int d=0;
        for(int i=0;i<26;i++){
            if(a[i] > 0)d++;
            if(b[i] > 0)d--;
        }
        return d==0;
    }
public:
    int numSplits(string s) {
        vector<int> l(26, 0), r(26,0);
        for(char &c:s)r[c-'a']++;
        int cnt=0;
        for(int i=0;i<s.size()-1;i++){
            l[s[i]-'a']++;
            r[s[i]-'a']--;
            if(isValid(l, r))cnt++;
        }
        return cnt;
    }
};
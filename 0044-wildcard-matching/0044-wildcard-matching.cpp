class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0, m=s.size(), n=p.size();
        int last_star=-1;
        int last_match = -1;
        while(i<m){
            if(j<n && (s[i]==p[j] or p[j]=='?')){
                i++,j++;
            }else if(j<n && p[j] == '*'){
                last_star=j;
                j++;
                last_match=i;
            }else if(last_star != -1){
                j=last_star+1;
                last_match++;
                i=last_match;
            }else
                return false;
        }
        while(j<n && p[j]=='*')j++;
        return j==n;
    }
};
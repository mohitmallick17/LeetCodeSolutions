class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size(), n=t.size();
        if(m > n)return false;
        
        for(int i=0, j=0;i<m;i++){
            while(j < n and t[j] != s[i])j++;
            if(j==n)return false;
            j++;
        }
        return true;
    }
};
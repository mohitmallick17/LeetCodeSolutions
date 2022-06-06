class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> ch_idx(26, vector<int>(2, -1));
        int res = 0;
        int mod = 1e9 + 7;
        int n=s.size();
        for(int i=0;i<n;i++){
            int ch = s[i]-'A';
            res = (res + ((ch_idx[ch][1]-ch_idx[ch][0])%mod)*((i-ch_idx[ch][1])%mod))%mod;
            ch_idx[ch][0]=ch_idx[ch][1];
            ch_idx[ch][1]=i;
        }
        for(int i=0;i<26;i++)
            res = (res + ((ch_idx[i][1]-ch_idx[i][0])%mod)*((n - ch_idx[i][1])%mod))%mod;
        return res;
    }
};
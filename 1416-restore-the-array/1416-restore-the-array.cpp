class Solution {
    long long mod = 1e9 + 7;
    vector<long long> dp;
    int solve(int start, string& s, int k){
        if(start>=s.size())return 1;
        if(s[start]=='0')return 0;
        if(dp[start] != -1LL)return dp[start];
        long long cur = 0;
        
        int i=start;
        long long count=0;
        while(i<s.size() and (cur*10LL) + (s[i]-'0') <= k){
            cur = (cur*10LL) + (s[i]-'0');
            i++;
            count = (count + solve(i, s, k))%mod;
        }
        return dp[start]=count;
    }
public:
    int numberOfArrays(string s, int k) {
        dp.resize(s.size(), -1LL);
        return solve(0, s, k);
    }
};
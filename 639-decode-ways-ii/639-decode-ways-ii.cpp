class Solution {
    vector<long long> dp;
    long long mod = 1e9 + 7;
    long long solve(int i, string& s){
        if(i==s.size())return 1LL;
        if(s[i]=='0')return 0LL;
        if(dp[i] != -1)return dp[i];
        
        long long ans = 0LL;
        
        if(s[i] == '*'){
            ans = (9LL*solve(i+1, s)) % mod;
            
            if(i+1 < s.size()){
                if(s[i+1]=='*')
                    ans = (ans + 15LL*solve(i+2, s)) % mod;
                else if(s[i+1] <= '6')
                    ans = (ans + 2LL*solve(i+2, s)) % mod;
                else if(s[i+1] > '6')
                    ans = (ans + 1LL*solve(i+2, s)) % mod;
            }
        }
        else{
            
            if(i+1 < s.size() and s[i]=='1')
                ans = ((s[i+1]=='*' ? 9LL : 1LL) * solve(i+2, s)) % mod;
            else if(i+1 < s.size() and s[i]=='2' and (s[i+1]=='*' or s[i+1] <= '6'))
                ans = ((s[i+1]=='*' ? 6LL : 1LL) * solve(i+2, s)) % mod;
            ans = (ans + solve(i+1, s)) % mod;
        }
        return dp[i] = ans;
    }
public:
    int numDecodings(string &s) {
        dp.resize(s.size(), -1LL);
        return solve(0, s);
    }
};
class Solution {
    long long mod = 1e9 + 7;
    
    long long solve(int n, int consecLate, bool abs, long long dp[][3][2]){
        if(n==0)return 1LL;
        if(dp[n][consecLate][abs] != -1)return dp[n][consecLate][abs];
        long long ans = 0LL;
        if(consecLate < 2)
            ans = (ans  + solve(n-1, consecLate+1, abs, dp)) % mod;
        if(abs==false)
            ans = (ans  + solve(n-1, 0, true, dp)) % mod;
        ans = (ans  + solve(n-1, 0, abs, dp)) % mod;
        
        return dp[n][consecLate][abs] = ans;
    }
public:
    int checkRecord(int n) {
        long long dp[n+1][3][2];
        memset(dp, -1LL, sizeof(dp));
        return solve(n, 0, 0, dp);
    }
};
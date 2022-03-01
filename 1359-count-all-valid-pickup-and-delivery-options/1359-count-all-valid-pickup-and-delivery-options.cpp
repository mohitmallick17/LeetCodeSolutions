class Solution {
    vector<vector<long long>> dp;
    long long mod = 1e9 + 7;
    long long solve(int p, int d){
        if(p==0 and d==0){
            return 1LL;
        }
        if(dp[p][d] != -1LL)return dp[p][d];
        long long ans = 0LL;
        if(p > 0)
            ans = (((solve(p-1, d+1))%mod)*p)%mod;
        if(d > 0)
            ans = (ans + (((solve(p, d-1)%mod)*d)%mod))%mod;
        
        return dp[p][d] = ans;
    }
public:
    int countOrders(int n) {
        dp.resize(n+1, vector<long long>(n+1, -1LL));
        return solve(n, 0);
    }
};
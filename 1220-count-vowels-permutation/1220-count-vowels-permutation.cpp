class Solution {
    // a=1
    // e=2
    // i=3
    // o=4
    // u=5
    // null=0
    int mod = 1e9 + 7;
    long long solve(int n, int prev, vector<vector<long long>> &dp){
        if(n==0)return 1;
        if(dp[n][prev] != -1LL)return dp[n][prev];
        long long cnt = 0;
        
        // use A for cur char
        if(prev==0 or prev==2){
            cnt = (cnt + solve(n-1, 1, dp))%mod;
        }
        
        // use E for cur char
        if(prev==0 or prev==1 or prev==3){
            cnt = (cnt + solve(n-1, 2, dp))%mod;           
        }
        
        // use I for cur char
        if(prev==0 or prev!=3){
            cnt = (cnt + solve(n-1, 3, dp))%mod;
        }
        
        // use O for cur char
        if(prev==0 or prev==3 or prev==5){
            cnt = (cnt + solve(n-1, 4, dp))%mod;
        }
        
        // use U for cur char
        if(prev==0 or prev==1){
            cnt = (cnt + solve(n-1, 5, dp))%mod;
        }
        
        return dp[n][prev] = cnt;
    }
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n+1, vector<long long>(6, -1LL));
        return solve(n, 0, dp);
    }
};
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int i, j, k;
        int dp[target + 1];
        memset(dp,0,sizeof dp);
        dp[0]=1;
      for (i = 1; i <= d; ++i)
        for (k = target; k >= (i == d ? target : 0); --k)
          for (j = k - 1, dp[k] = 0; j >= max(0, k - f); --j)
            dp[k] = (dp[k] + dp[j]) % 1000000007;
      return dp[target];
}
};
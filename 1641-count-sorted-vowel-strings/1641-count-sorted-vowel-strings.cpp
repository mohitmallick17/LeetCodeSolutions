class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(6, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++){
                if(i==1 or j==1)
                    dp[i][j] = j;
                else{
                    dp[i][j] += dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n][5];
    }
};
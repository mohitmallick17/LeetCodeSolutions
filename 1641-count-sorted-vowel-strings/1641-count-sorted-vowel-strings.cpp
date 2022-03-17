class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(2, vector<int>(6, 0));
        bool flag = true;
        for(int i=1;i<=n;i++){
            flag = !flag;
            for(int j=1;j<=5;j++){
                if(i==1 or j==1)
                    dp[flag][j] = j;
                else{
                    dp[flag][j] = dp[1-flag][j] + dp[flag][j-1];
                }
            }
        }
        return dp[flag][5];
    }
};
class Solution {
public:
    int minDistance(string w1, string w2){
        int m=w1.size(), n=w2.size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        bool flag=1;
        
        for(int i=1;i<=m;i++){
            flag=!flag;
            for(int j=1;j<=n;j++){
                if(w1[i-1] == w2[j-1])
                    dp[flag][j]=dp[1-flag][j-1]+1;
                else
                    dp[flag][j]=max(dp[1-flag][j], dp[flag][j-1]);
            }
        }
        return w1.size() + w2.size() - (2*dp[flag][n]);
    }
};
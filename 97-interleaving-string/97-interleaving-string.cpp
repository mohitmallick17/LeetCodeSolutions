class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())return false;
        vector<vector<bool>> dp(2, vector<bool>(s2.size()+1, false));
        bool flag=true;
        
        for(int i=0;i<=s1.size();i++){
            flag=!flag;
            for(int j=0;j<=s2.size();j++){
                if(i==0 and j==0)dp[flag][j]=true;
                else if(i==0)dp[flag][j] = dp[flag][j-1] and s2[j-1]==s3[i+j-1];
                else if(j==0)dp[flag][j] = dp[1-flag][j] and s1[i-1]==s3[i+j-1];
                else{
                    dp[flag][j] = (dp[flag][j-1] and s2[j-1]==s3[i+j-1]) or (dp[1-flag][j] and s1[i-1]==s3[i+j-1]);
                }
            }
        }
        return dp[flag][s2.size()];
    }
};
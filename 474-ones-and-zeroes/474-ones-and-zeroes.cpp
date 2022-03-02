class Solution {
    pair<int, int> getDigitCount(string &s){
        int z=0, o=0;
        for(char& c:s){
            if(c=='0')z++;
            else o++;
        }
        return {z,o};
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();

        int dp[len+1][m+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1;i<=len;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    pair<int, int> p = getDigitCount(strs[i-1]);
                    int zeros=p.first;
                    int ones=p.second;
                    
                    int res = dp[i-1][j][k];
                    if(zeros <= j and ones <= k)
                        res = max(res, dp[i-1][j-zeros][k-ones] + 1);
                    dp[i][j][k] = res;
                }
            }
        }
        return dp[len][m][n];
    }
};
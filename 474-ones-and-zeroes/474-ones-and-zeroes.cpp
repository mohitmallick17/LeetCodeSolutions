class Solution {
//     int dp[601][101][101];
    pair<int, int> getCnt(string &s){
        int z=0, o=0;
        for(char &c:s){
            if(c=='0')z++;
            else o++;
        }
        return {z, o};
    }
//     int solve(int i, vector<pair<int, int>> &cnt, int m, int n){
//         if(i==cnt.size())return 0;
//         if(dp[i][m][n] != -1)return dp[i][m][n];
//         int res;
        
//         if(m >= cnt[i].first and n >= cnt[i].second){
//             // can include this set, as (m, n) > set(cnt[i])
//             // choice: include, skip
//             res = max(solve(i+1, cnt, m, n), 1+solve(i+1, cnt, m-cnt[i].first, n-cnt[i].second));
//         }else
//             res = solve(i+1, cnt, m, n);
        
//         return dp[i][m][n]=res;
//     }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> cnt(strs.size());
        for(int i=0;i<strs.size();i++)
            cnt[i] = getCnt(strs[i]);
        int dp[2][m+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        bool flag = true;
        
        for(int i=1;i<=cnt.size();i++){
            flag = !flag;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int res;
                    int zeros=cnt[i-1].first, ones=cnt[i-1].second;
                    if(j >= zeros and k >= ones){
                        // can include this set, as (m, n) > set(cnt[i])
                        // choice: include, skip
                        res = max(dp[1-flag][j][k], 1+dp[1-flag][j-zeros][k-ones]);
                    }else
                        res = dp[1-flag][j][k];
                    dp[flag][j][k] = res;
                }
            }
        }
        
        return dp[flag][m][n];
    }
};
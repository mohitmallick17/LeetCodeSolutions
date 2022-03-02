class Solution {
    int dp[601][101][101];
    
    pair<int, int> getDigitCount(string &s){
        int z=0, o=0;
        for(char& c:s){
            if(c=='0')z++;
            else o++;
        }
        return {z,o};
    }
    
    int solve(int i, int m, int n, vector<string>& strs){
        if(i==strs.size() or (m==0 and n==0)){
            return 0;
        }
        if(dp[i][m][n] != -1)return dp[i][m][n];
        pair<int, int> dc = getDigitCount(strs[i]);
        
        int incl_m=m, incl_n=n;
        int excl_m=m, excl_n=n;
        bool flag=false;
        
        if(dc.first <= m and dc.second <= n)
            incl_m -= dc.first, incl_n -= dc.second, flag=true;
        
        if(flag)
            return dp[i][m][n] = max(solve(i+1, excl_m, excl_n, strs), 1 + solve(i+1, incl_m, incl_n, strs));
        else
            return dp[i][m][n] = solve(i+1, excl_m, excl_n, strs);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, m, n, strs);
    }
};
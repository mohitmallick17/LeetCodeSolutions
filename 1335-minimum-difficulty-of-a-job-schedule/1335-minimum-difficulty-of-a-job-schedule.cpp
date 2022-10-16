class Solution {
    int solve(int index, vector<int>& v, int d, vector<vector<int>> &dp){
        if(index==v.size() && d==0){
            return 0;
        }else if(index==v.size() or d==0)
            return -1;
        
        if(dp[index][d] != -1)return dp[index][d];
        
        int jd = v[index];
        int ans = INT_MAX;
        for(int i=index;i<v.size();i++){
            jd = max(jd, v[i]);
            int cur = solve(i+1, v, d-1, dp);
            if(cur != -1)
                ans = min(ans, jd + cur);
        }
        return dp[index][d] = (ans==INT_MAX ? -1 : ans);
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(11, -1));
        return solve(0,jobDifficulty,d,dp);
    }
};
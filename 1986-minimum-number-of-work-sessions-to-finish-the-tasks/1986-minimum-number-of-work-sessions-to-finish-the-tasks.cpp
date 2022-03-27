class Solution {
    int solve(int bits, int remainTime, const int &sessionTime, vector<int>& tasks, const int &n, vector<vector<int>> &dp){
        if(bits == (1<<n)-1)
            return 0;
        if(dp[bits][remainTime] != -1)return dp[bits][remainTime];
        
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            if((bits>>i & 1)==0){
                int newbit = bits | (1<<i);
                if(remainTime >= tasks[i])
                    res = min(res, solve(newbit, remainTime-tasks[i], sessionTime, tasks, n, dp));
                else
                    res = min(res, 1+solve(newbit, sessionTime-tasks[i], sessionTime, tasks, n, dp));                    
            }
        }
        return dp[bits][remainTime] = res;
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();
        vector<vector<int>> dp(1<<n, vector<int>(sessionTime+1, -1));
        return solve(0, 0, sessionTime, tasks, n, dp);    
    }
};
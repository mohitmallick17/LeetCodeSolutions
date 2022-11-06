class Solution {
    long long INF = 1e16;
    
    long long solve(int r_idx, vector<int> &robot, int f_idx, vector<vector<int>> &factory, int repair_cnt, vector<vector<vector<long long>>> &dp){
        if(r_idx == robot.size())return 0;
        if(f_idx == factory.size())return INF;
        
        if(dp[r_idx][f_idx][repair_cnt] != -1)return dp[r_idx][f_idx][repair_cnt];
        
        long long take = INF, not_take = INF;
        not_take = solve(r_idx, robot, f_idx+1, factory, 0, dp);
        if(factory[f_idx][1] > repair_cnt)
            take = abs(robot[r_idx] - factory[f_idx][0]) + solve(r_idx+1, robot, f_idx, factory, repair_cnt+1, dp);
        
        return dp[r_idx][f_idx][repair_cnt] = min(take, not_take);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(factory.begin(), factory.end());
        sort(robot.begin(), robot.end());
vector<vector<vector<long long>>> dp(robot.size(), vector<vector<long long>>(factory.size(), vector<long long>(robot.size()+1, -1)));
        return solve(0, robot, 0, factory, 0, dp);        
    }
};
class Solution {
    unordered_map<int, unordered_map<int, int>> dp;
    int solve(int i, vector<int>& nums, int target){
        if(i == nums.size()){
            if(target==0)return 1;
            return 0;
        }
        if(dp.find(i) != dp.end() and dp[i].find(target) != dp[i].end()) return dp[i][target];
        int ways = 0;
        // num is positive
        ways += solve(i+1, nums, target+nums[i]);
        // num is negative
        ways += solve(i+1, nums, target-nums[i]);
        
        return dp[i][target] = ways;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, nums, target);
    }
};
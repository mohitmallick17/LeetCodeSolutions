class Solution {
    int solve(int i, int limit, vector<int>& nums2, unordered_map<int, vector<int>> &nums1
              ,vector<vector<int>> &dp) {
        if(i >= nums2.size())return 0;
        
        if(dp[i][limit] != -1)return dp[i][limit];
        if(nums1.find(nums2[i]) == nums1.end())
            return dp[i][limit]=solve(i+1, limit, nums2, nums1, dp);
        
        // exclude ith num
        int res = solve(i+1, limit, nums2, nums1, dp);
        
        for(int val:nums1[nums2[i]]){
            if(val >= limit)
                res = max(res, 1 + solve(i+1, val+1, nums2, nums1, dp));
        }
        return dp[i][limit]=res;
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]].push_back(i);
        }
        vector<vector<int>> dp(nums2.size(), vector<int>(nums1.size()+1, -1));
        return solve(0, 0, nums2, mp, dp);
    }
};
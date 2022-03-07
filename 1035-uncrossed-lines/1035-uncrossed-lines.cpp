class Solution {
//     int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp) {
//         if(i == nums1.size() or j == nums2.size())return 0;
        
//         if(dp[i][j] != -1)return dp[i][j];
//         if(nums1[i] == nums2[j])
//             return dp[i][j] = 1 + solve(i+1, j+1, nums1, nums2, dp);
//         else
//             return dp[i][j] = max(solve(i, j+1, nums1, nums2, dp), solve(i+1, j, nums1, nums2, dp));
//     }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        int m=nums1.size(), n=nums2.size();    
        vector<vector<int>> dp(2, vector<int>(n+1, 0));   
        bool row=true;
        for(int i=1;i<=m;i++){
            row = !row;
            for(int j=1;j<=n;j++){
                if(nums1[i-1] == nums2[j-1])
                    dp[row][j] = dp[1-row][j-1] + 1;
                else
                    dp[row][j] = max(dp[1-row][j], dp[row][j-1]);
            }
        }
        
        // return solve(0, 0, nums1, nums2, dp);
        
        return dp[row][n];
    }
};
class Solution {
    int solve(int i, int j, vector<int> &v, vector<vector<int>> &dp){
        if(i > j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            int cost = (v[k] * v[i-1] * v[j+1]) + solve(i, k-1, v, dp) + solve(k+1, j, v, dp);
            ans = max(ans, cost);
        }
        return dp[i][j]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return solve(1, n, nums, dp);
    }
};
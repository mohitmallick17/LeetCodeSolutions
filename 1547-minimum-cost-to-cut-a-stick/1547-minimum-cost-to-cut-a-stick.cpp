class Solution {
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i>j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            int cur = cuts[j+1]-cuts[i-1] + solve(i,k-1,cuts,dp) + solve(k+1, j,cuts,dp);
            ans = min(ans, cur);
        }
        return dp[i][j]=ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>> dp(c+2, vector<int>(c+2, -1));
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return solve(1,c, cuts,dp);
    }
};

// 0 1 3 4 5 7
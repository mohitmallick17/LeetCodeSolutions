class Solution {
    int dp[101][21][101];
    int solve(int i, int prev_house_col, int target, vector<int>& houses, vector<vector<int>>& cost){
        if(i==houses.size()){
            if(target==0)return 0;
            return INT_MAX;
        }else if(target < 0)
            return INT_MAX;
        if(dp[i][prev_house_col][target] != -1)return dp[i][prev_house_col][target];
        // need to paint
        int res = INT_MAX;
        // need to paint
        if(houses[i] == 0){
            for(int j=0;j<cost[i].size();j++){
                int nh = solve(i+1, j+1, target-(prev_house_col != j+1), houses, cost);
                if(nh==INT_MAX)continue;
                res = min(res, nh+cost[i][j]);
            }
        }else
            return solve(i+1, houses[i], target - (prev_house_col != houses[i]), houses, cost);
        return dp[i][prev_house_col][target]=res;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof dp);
        int ans = solve(0,0,target,houses,cost);
        return ans==INT_MAX ? -1:ans;
    }
};
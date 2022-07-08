class Solution {
public:
int dp[101][101][21] = {};
int dfs(vector<int>& houses, vector<vector<int>>& cost, int i, int target, int last_clr) {
    if (i >= houses.size() || target < 0)
        return target == 0 ? target : 1000001;
    if (houses[i] != 0) // painted last year.
        return dfs(houses, cost, i + 1, target - (last_clr != houses[i]), houses[i]);      
    if (dp[i][target][last_clr])
        return dp[i][target][last_clr];
    auto res = 1000001;
    for (auto clr = 1; clr <= cost[i].size(); ++clr) {
        res = min(res, cost[i][clr - 1] 
            + dfs(houses, cost, i + 1, target - (last_clr != clr), clr));
    }            
    return dp[i][target][last_clr] = res;
}
int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    auto res = dfs(houses, cost, 0, target, 0);
    return res > 1000000 ? -1 : res;
}
//     unordered_map<int, int> dp;
//     int solve(int idx, vector<int>& houses, vector<vector<int>>& cost, int target){
//         if(idx==houses.size()){
//             int cur = 1;
//             for(int i=1;i<houses.size();i++){
//                 if(houses[i] != houses[i-1])cur++;
//             }
//             if(cur==target)return 0;
//             return INT_MAX;
//         }
//         if(houses[idx] != 0)return solve(idx+1, houses, cost, target);
        
//         int res = INT_MAX;
//         for(int i=0;i<cost[i].size();i++){
//             houses[idx]=i+1;
//             int s = solve(idx+1, houses, cost, target);
//             if(s==INT_MAX)continue;
//             res = min(res, cost[idx][i] + s);
//         }
//         houses[idx]=0;
//         return res;
//     }
// public:
//     int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
//         int ans = solve(0, houses, cost, target);
//         return ans==INT_MAX?-1:ans;
//     }
};
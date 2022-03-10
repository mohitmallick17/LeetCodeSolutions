class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        unordered_map<int, int> dp;
        dp[0] = 0;
        for(int &x:rods){
            unordered_map<int, int> cur = dp;
            for(auto &[d, y]:cur){
                dp[d+x] = max(dp[d+x], y);
                
                if(d >= x)
                    dp[d-x] = max(dp[d-x], y+x);
                else
                    dp[x-d] = max(dp[x-d], y+d);
            }
        }
        return dp[0];
    }
};
class Solution {
    vector<int> dp;
    
    int solve(int i, int n, vector<int> &v){
        if(i==n)return 0;
        if(dp[i] != -1)return dp[i];        
        int ans = v[i] - solve(i+1, n, v);
        if(i+1 < n)
           ans = max(ans,  v[i]+v[i+1]-solve(i+2, n, v));
        if(i+2 < n)
        ans = max(ans, v[i]+v[i+1]+v[i+2]-solve(i+3, n, v));

        return dp[i]=ans;

    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size(), -1);
        int res = solve(0, stoneValue.size(), stoneValue);
        if(res==0)return "Tie";
        return (res > 0) ? "Alice" : "Bob";
    }
};
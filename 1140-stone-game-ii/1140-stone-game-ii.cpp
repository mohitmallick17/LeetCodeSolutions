class Solution {
    vector<vector<int>> dp;
    int solve(int i, int M, vector<int>& piles){
        if(i >= piles.size())return 0;
        if(dp[i][M] != -1)return dp[i][M];
        int coins = 0;
        int ans = INT_MIN;
        for(int j=1;j<=2*M;j++){
            if(i+j <= piles.size())
                coins += piles[i+j-1];
            ans = max(ans, coins - solve(i+j, max(M, j), piles)); 
        }
        return dp[i][M]=ans;
    }
public:
    int stoneGameII(vector<int>& piles){
        dp.resize(piles.size(), vector<int>(piles.size() + 1, -1));
        int a_plus_b = 0;
        for(int &x:piles)
            a_plus_b+=x;
        int a_minus_b = solve(0, 1, piles);
        
        // task: find A
        // ( (a+b) + (a-b) )/2
        
        return (a_plus_b + a_minus_b)/2;
    }
};
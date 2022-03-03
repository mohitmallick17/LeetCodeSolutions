class Solution {
    int INF = (1 << 30);
    vector<vector<int>> dp;
    set<pair<int, int>> vis;
    int solve(int screen, int clipboard, int n){
        if(screen == n)
            return 0;
        if(screen > n or vis.find({screen, clipboard})!=vis.end())
            return INF;
        vis.insert({screen, clipboard});
        if(dp[screen][clipboard] != -1)return dp[screen][clipboard];
        int copy = 1 + solve(screen, screen, n);
        int paste = (clipboard > 0 ) ? 1 + solve(screen + clipboard, clipboard, n) : INF; // paste
        
        return dp[screen][clipboard] = min(copy, paste);
    }
public:
    int minSteps(int n) {
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(1, 0, n);
    }
};
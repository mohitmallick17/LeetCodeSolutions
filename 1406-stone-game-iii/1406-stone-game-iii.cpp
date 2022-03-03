class Solution {
public:
    string stoneGameIII(vector<int>& v) {
        int n=v.size();
        vector<int> dp(n+1,0);
        int i=n-1;
        
        while(i>=0){
            int ans = v[i] - dp[i+1];
            if(i+1 < n)
               ans = max(ans,  v[i]+v[i+1]-dp[i+2]);
            if(i+2 < n)
            ans = max(ans, v[i]+v[i+1]+v[i+2]-dp[i+3]);

            dp[i]=ans;
            i--;
        }
        
        int res = dp[0];
        if(res==0)return "Tie";
        return (res > 0) ? "Alice" : "Bob";
    }
};
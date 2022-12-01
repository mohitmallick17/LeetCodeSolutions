class Solution {
    bool isMatch(char &a, char &b){
        return (a=='.' or a==b);
    }
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i==s.size() and j==p.size())
            return true;
        if(j==p.size())
            return false;
        if(i==s.size()){
            // cout << "here";
            int c = 0;
            while(j < p.size()){
                if(p[j]=='*')c--;
                else c++;
                if(c > 1)return false;
                j++;
            }
            return c==0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        bool ans = false;
        if(j+1 < p.size() && p[j+1]=='*'){
            ans = solve(i, j+2, s, p, dp); // skip this char
            for(int k=i;k<s.size();k++){
                if(isMatch(p[j], s[k]))
                    ans |= solve(k+1, j+2, s, p, dp);
                else
                    break;
            }
        }else
            ans = isMatch(p[j], s[i]) and solve(i+1, j+1, s, p, dp);
        return dp[i][j]=ans;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return solve(0,0,s,p,dp);
    }
};
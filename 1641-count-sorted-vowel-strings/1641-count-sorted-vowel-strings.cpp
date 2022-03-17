class Solution {
    vector<int> v;
    vector<vector<int>> dp;
    
    int count(int n, int ci){
        if(n==0)return 1;
        vector<int> key{n, ci};
        if(dp[n][ci] != -1)
            return dp[n][ci];
        int res = 0;
        for(int i=ci;i<5;i++){
            res += count(n-1, i);
        }
        return dp[n][ci]=res;
    }
public:
    int countVowelStrings(int n) {
        v = {'a', 'e', 'i', 'o', 'u'};
        dp.resize(n+1, vector<int>(5, -1));
        return count(n, 0);
    }
};
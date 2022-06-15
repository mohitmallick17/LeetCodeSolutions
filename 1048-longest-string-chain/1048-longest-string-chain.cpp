class Solution {
    static bool cmp(string& a, string& b){
        return a.size() < b.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> dp;
        
        int res = 0;
        
        for(auto &w:words){
            for(int i=0;i<w.size();i++){
                // del char i
                string nw = w.substr(0, i) + w.substr(i+1);
                dp[w] = max(dp[w], (dp.find(nw) == dp.end()) ? 1 : dp[nw]+1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(auto &x:tasks)mp[x]++;
        
        int ans = 0;
        for(auto [k,v]:mp){
            if(v==1)return -1;
            ans += ceil(v/3.0);
        }
        return ans;
    }
};
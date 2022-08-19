class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &x:nums)mp[x]++;
        
        int ans=0;
        for(auto &x:nums){
            if(mp.find(x+1) != mp.end())
                ans = max(ans, mp[x] + mp[x+1]);
        }
        return ans;
    }
};
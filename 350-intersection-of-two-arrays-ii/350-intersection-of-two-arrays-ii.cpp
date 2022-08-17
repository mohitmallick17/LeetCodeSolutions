class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(auto &x:nums1)mp[x]++;
        
        vector<int> res;
        for(auto& x:nums2){
            if(mp[x]>0){
                res.push_back(x);
                mp[x]--;
            }
        }
        return res;
    }
};
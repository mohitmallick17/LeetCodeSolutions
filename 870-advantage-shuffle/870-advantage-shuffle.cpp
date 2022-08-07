class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s;
        
        for(auto &x:nums1)s.insert(x);
        
        vector<int> res;
        
        for(auto &n:nums2){
            auto it = s.upper_bound(n);
            if(it == s.end())
                it = s.begin();
            res.push_back(*it);
            s.erase(it);
        }
        return res;
    }
};

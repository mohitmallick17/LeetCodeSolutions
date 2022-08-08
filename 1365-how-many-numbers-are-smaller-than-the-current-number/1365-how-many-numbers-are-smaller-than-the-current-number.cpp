class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v=nums;
        sort(v.begin(), v.end());
        vector<int> res;
        for(int &i:nums){
            int idx = lower_bound(v.begin(), v.end(), i) - v.begin();
            res.push_back(idx);
        }
        return res;
    }
};
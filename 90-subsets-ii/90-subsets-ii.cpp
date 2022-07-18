class Solution {
    vector<vector<int>> res;
    
    void solve(int idx, vector<int>& nums, vector<int> &cur){
        res.push_back(cur);
        
        for(int i=idx;i<nums.size();i++){
            if(i > idx and nums[i]==nums[i-1])continue;
            cur.push_back(nums[i]);
            solve(i+1, nums, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        solve(0, nums, cur);
        return res;
    }
};
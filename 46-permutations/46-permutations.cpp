class Solution {
    vector<vector<int>> res;
    void solve(int idx, vector<int>& nums){
        if(idx == nums.size()){
            res.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i], nums[idx]);
            solve(idx+1, nums);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0, nums);
        return res;
    }
};
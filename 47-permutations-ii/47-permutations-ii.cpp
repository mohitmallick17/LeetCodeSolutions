class Solution {
    vector<vector<int>> res;
    
    void solve(vector<int>& nums, vector<bool>& used, vector<int>& cur){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(used[i])continue;
            if(i>0 and nums[i]==nums[i-1] and !used[i-1])continue;
            used[i]=true;
            cur.push_back(nums[i]);
            solve(nums, used, cur);
            used[i]=false;
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        
        solve(nums, used, cur);
        return res;
    }
};
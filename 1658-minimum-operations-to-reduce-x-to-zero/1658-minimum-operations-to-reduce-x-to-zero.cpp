class Solution {
    int lcs_sum(vector<int>& nums, int x){
        unordered_map<int, int> mp; // map: sum, index
        int sum = 0;
        mp[0]=-1;
        
        int res = -1;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(mp.find(sum-x) != mp.end()){
                // mp[sum-x]...i = subsequence with sum = x
                // cout << "found " << x << " at " << mp[sum-x] << ", " << i << '\n'; 
                res = max(res, i-mp[sum-x]);
            }
            if(mp.find(sum) == mp.end())
                mp[sum]=i;
        }
        return (res == -1) ? -1 : nums.size()-res;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        int sm=-x;
        for(int &n:nums)sm+=n;
        if (sm == 0) return nums.size();
        return lcs_sum(nums, sm);
    }
};
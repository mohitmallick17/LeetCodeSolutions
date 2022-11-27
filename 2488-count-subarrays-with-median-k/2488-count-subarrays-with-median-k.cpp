class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int idx = find(nums.begin(), nums.end(), k) - nums.begin();
        
        unordered_map<int, int> mp;
        
        for(int i=idx, bal=0;i<n;i++){
            if(nums[i] != k)
                bal += (nums[i] < k) ? -1:1;
            mp[bal]++;
        }
        int res = 0;
        for(int i=idx, bal=0;i>=0;i--){
            if(nums[i] != k)
                bal += (nums[i] < k) ? -1:1;
            res += mp[-bal] + mp[-bal + 1];    
        }
        return res;
    }
};
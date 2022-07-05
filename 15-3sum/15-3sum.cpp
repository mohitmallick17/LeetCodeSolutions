class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            // pruning
            if(nums[i] > 0)break;
            if(i>0 and nums[i-1]==nums[i])continue;
            int lo=i+1, hi=n-1;
            int search = 0 - nums[i];
            
            while(lo < hi){
                int sum = nums[lo] + nums[hi];
                if(sum == search){
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    while(lo < hi and nums[lo]==nums[lo+1])lo++;
                    while(lo < hi and nums[hi-1]==nums[hi])hi--;
                    lo++, hi--;
                }else if(sum < search)lo++;
                else hi--;
            }
        }
        return res;
    }
};
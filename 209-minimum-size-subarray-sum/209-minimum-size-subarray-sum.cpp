class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = nums.size()+1;
        int Sum=0;
        for(int s=0,e=0;e<nums.size();e++){
            Sum+=nums[e];
            while(Sum>=target){
                res = min(res, e-s+1);
                Sum-=nums[s];
                s++;
            }
        }
        return res>nums.size() ? 0:res;
        
    }
};
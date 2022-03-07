class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0], minP = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();++i){
            int prevMax = maxP;
            maxP = max({maxP*nums[i], nums[i], minP*nums[i]});    
            minP = min({minP*nums[i], nums[i], prevMax*nums[i]});
            
            res = max(res, maxP);
        }
        return res;
    }
};
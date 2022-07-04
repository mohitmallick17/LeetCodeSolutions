class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minE = nums[0]+1;
        
        int count = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] <= minE){
                count += minE - nums[i];
                nums[i] = minE;
            }
            minE = nums[i]+1;
        }
        return count;
    }
};
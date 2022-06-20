class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int inc=1, dec=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] - nums[i-1] > 0){
                // increasing subsequence
                // this is increasing pair, so we append it after the last decreasing slope
                inc = dec+1;
            }else if(nums[i] - nums[i-1] < 0){
                // decreasing subsequence
                // decreasing slope, we will append it after the last increasing slope to make it wiggle subseq.
                dec = inc+1;
            }
        }
        return max(inc, dec);
    }
};
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        int prev = 0, cur;
        int ans=0;
        for(int i=2;i<n;++i){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2])
                cur = prev + 1;
            else
                cur = 0;
            ans += cur;
            prev=cur;
        }
        return ans;
    }
};
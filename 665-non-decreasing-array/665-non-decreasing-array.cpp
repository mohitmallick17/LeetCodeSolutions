class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int n=nums.size();
        for(int i=1;i<n and count <= 1;i++){
            if(nums[i-1] <= nums[i])continue;
            count++;
            if(i-2<0 or nums[i-2]<=nums[i])
                nums[i-1]=nums[i];
            else
                nums[i]=nums[i-1];
            
        }
        return count<=1;
    }
};
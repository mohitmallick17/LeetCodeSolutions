class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int p1,p2;
        p2=nums[0];
        p1=max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            int cur = max(p2 + nums[i], p1);
            p2=p1;
            p1=cur;
        }
        return p1;
    }
};
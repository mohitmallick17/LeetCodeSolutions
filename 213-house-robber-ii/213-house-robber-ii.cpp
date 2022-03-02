class Solution {
    int robLinear(int start, int end, vector<int>& nums) {
        int n=end-start;
        if(n==1)return nums[start];
        int p1,p2;
        p2=nums[start];
        p1=max(nums[start], nums[start+1]);
        for(int i=start+2;i<end;i++){
            int cur = max(p2 + nums[i], p1);
            p2=p1;
            p1=cur;
        }
        return p1;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0], nums[1]);
        
        return max(robLinear(0,n-1, nums), robLinear(1, n, nums));
    }
};
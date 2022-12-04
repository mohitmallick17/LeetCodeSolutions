class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = 0;
        for(auto &x:nums)sum += x;
        
        long long l=0, r=sum;
        
        long long mn = LLONG_MAX;
        int ans = -1;
        for(int i=0;i<nums.size();i++){
            l += nums[i];
            r -= nums[i];
            
            int lden = (i+1);
            int rden = (nums.size() - 1 - i);
            long long cur = labs((l / lden) - (rden==0 ? 0 : (r / rden)));
            
            if(cur < mn){
                mn = cur;
                ans = i;
            }
        }
        return ans;
    }
};
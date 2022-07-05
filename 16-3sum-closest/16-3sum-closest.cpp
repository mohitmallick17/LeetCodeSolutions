class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 and nums[i-1]==nums[i])continue;
            int lo=i+1, hi=n-1;
            
            while(lo < hi){
                int Sum = nums[lo] + nums[hi] + nums[i];
                if(target==Sum)return target; // Sum = target. Exact Match
                else if(target>Sum)
                    lo++;
                else
                    hi--;
                if(abs(target-ans) > abs(target-Sum))
                    ans = Sum;
            }
        }
        return ans;
    }
};
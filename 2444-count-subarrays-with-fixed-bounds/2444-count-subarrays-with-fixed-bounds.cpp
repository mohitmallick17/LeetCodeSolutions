class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res=0, j=0, jmin=-1, jmax=-1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] < minK or nums[i] > maxK){
                j=i+1;
                jmin=jmax=-1;
                continue;
            }
            if(nums[i]==minK)jmin=i;
            if(nums[i]==maxK)jmax=i;
            res += max(0LL, min(jmin, jmax)-j+1);
        }
        return res;
    }
};
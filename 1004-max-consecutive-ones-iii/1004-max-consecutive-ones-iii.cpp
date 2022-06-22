class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res=0, ok=k;
        for(int s=0,e=0;e<nums.size();e++){
            if(nums[e]==0)k--;
            
            while(s<=e and k<0){
                if(nums[s]==0)k++;
                s++;
            }
            if(s<=e and k>=0)res=max(res, e-s+1);
            
        }
        return res;
    }
};
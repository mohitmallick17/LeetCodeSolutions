class Solution {
    int atMaxK(vector<int>& v, int sum){
        if(sum<0)return 0;
        int res=0;
        for(int s=0, e=0;e<v.size();e++){
            sum-=v[e];
            while(s<=e and sum<0){
                sum+=v[s];
                s++;
            }
            res += (e-s+1);
        }
        return res;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMaxK(nums, goal) - atMaxK(nums, goal-1);
    }
};
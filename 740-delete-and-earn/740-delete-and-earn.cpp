class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ub = *max_element(nums.begin(), nums.end());
        vector<int> hash(ub+2, 0);
        
        for(int num:nums){
            hash[num]++;
        }
        int p2=0, p1=0;
        
        for(int i=1;i<=ub;++i){
            int cur = max(p2 + (hash[i]*i), p1);
            p2=p1;
            p1=cur;
        }
        return p1;
    }
};
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> pre;
        pre[0] = -1;
        long long total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            long long rem = total % k;
            if(pre.find(rem) != pre.end()){
                if(i - pre[rem] >= 2)
                    return true;
            }
            else
                pre[rem] = i;
        }
        return false;
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp; // num:count
        for(int end=0, start=0, Sum = 0;end<nums.size();end++){
            mp[nums[end]]++;
            Sum += nums[end];
            while(start < end and mp[nums[end]] > 1){
                mp[nums[start]]--;
                Sum -= nums[start];
                if(mp[nums[start]] == 0)
                    mp.erase(nums[start]);
                start++;
            }
            res = max(res, Sum);
        }
        return res;
    }
};
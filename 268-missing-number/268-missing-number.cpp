class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long Sum = 0, n = nums.size();
        for(auto &x:nums)
            Sum += x;
        return ((n)*(n+1)/2) - Sum;
    }
};
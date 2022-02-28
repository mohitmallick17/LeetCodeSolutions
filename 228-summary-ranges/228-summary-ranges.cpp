class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i=0, n=nums.size();
        while(i < n){
            int j=i;
            while(j < n-1 and (long long)nums[j+1]-(long long)nums[j]==1)
                j++;
            if(j > i)
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            else
                res.push_back(to_string(nums[i]));
            i = j+1;
        }
        return res;
    }
};
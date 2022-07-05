class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(0, 4, target, nums);
    }
    
    vector<vector<int>> kSum(int start, int k, int target, vector<int>& nums){
        vector<vector<int>> res;
        if(nums.size() < k)return res;
        
        if(k==2){
            int lo=start, hi=nums.size()-1;
            while(lo < hi){
                long long Sum = (long long)nums[lo] + nums[hi];
                if(Sum == (long long)target){
                    res.push_back({nums[lo], nums[hi]});
                    while(lo<hi and nums[lo]==nums[lo+1])lo++;
                    while(lo<hi and nums[hi]==nums[hi-1])hi--;
                    lo++, hi--;
                }else if(Sum < target)lo++;
                else hi--;
            }
        }else{
            long long max = nums.back();
            for(int i=start;i<nums.size()-k+1;i++){
                if(i > start and nums[i]==nums[i-1])continue; // duplicate
                if((long long)nums[i]*k > (long long)target)break;
                if(nums[i] + max*(k-1) < (long long)target)continue;
                auto child = kSum(i+1, k-1, target-nums[i], nums);
                for(auto c:child){
                    c.insert(c.begin(), nums[i]);
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};
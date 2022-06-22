class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minQ, maxQ;
        int ans = 0;
        for(int s=0, e=0;e<nums.size();e++){
            int num = nums[e];
            while(!maxQ.empty() and nums[maxQ.back()] < num)maxQ.pop_back();
            while(!minQ.empty() and nums[minQ.back()] > num)minQ.pop_back();
            maxQ.push_back(e);
            minQ.push_back(e);
            
            while(!maxQ.empty() and !minQ.empty() and nums[maxQ.front()] - nums[minQ.front()] > limit){
                s++;
                if(minQ.front() < s)minQ.pop_front();
                if(maxQ.front() < s)maxQ.pop_front();
            }
            ans = max(ans, e-s+1);
        }
        return ans;
    }
};
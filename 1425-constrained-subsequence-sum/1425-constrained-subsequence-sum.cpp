class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> dq; // front-> max element, back->min element. decreasing queue
        
        int res = nums[0];
        
        for(int i=0;i<nums.size();i++){
            nums[i] += (dq.empty() ? 0 : dq.front());
            res = max(res, nums[i]);
            
            while(!dq.empty() and dq.back() < nums[i])dq.pop_back(); // ensure queue is decreasing
            if(nums[i] > 0)dq.push_back(nums[i]);
            
            //delete element expiring on next window
            if(i>=k and !dq.empty() and dq.front() == nums[i-k])dq.pop_front(); 
        }
        return res;
    }
};
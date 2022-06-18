class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> stk;
        for(int i=0;i<n;i++){
            int num=nums[i];
            // while valid && smaller
            // valid: after ith element there must be sufficient elements
            // required_elements = K - stack.size()
            // have_elements = n - (i + 1)
            // valid = have_elements >= required_elements
            // smaller = stack.top() > num
            while(!stk.empty() and (n-i-1) >= k-stk.size() and stk.back() > num)
                stk.pop_back();
            if(stk.size() < k)
                stk.push_back(num);
        }
        return stk;
    }
};
class Solution {
    vector<int> NGR(vector<int> &v){
        int n=v.size();
        vector<int> a(n);
        stack<int> stk;
        
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() and stk.top()<=v[i])
                stk.pop();
            a[i] = (stk.empty()) ? -1 : stk.top();
            stk.push(v[i]);
        }
        return a;
    }
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        auto v = NGR(nums);
        v.resize(n);
        return v;
    }
};
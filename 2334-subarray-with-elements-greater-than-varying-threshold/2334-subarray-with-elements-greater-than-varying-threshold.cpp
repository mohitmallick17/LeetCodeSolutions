class Solution {
    vector<int> NSL(vector<int> &a){
        int n=a.size();
        vector<int> v(n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() and a[stk.top()] >= a[i])stk.pop();
            
            if(stk.empty())
                v[i] = -1;
            else
                v[i] = stk.top();
            stk.push(i);
        }
        return v;
    }
    vector<int> NSR(vector<int> &a){
        int n=a.size();
        vector<int> v(n);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() and a[stk.top()] >= a[i])stk.pop();
            
            if(stk.empty())
                v[i] = n;
            else
                v[i] = stk.top();
            stk.push(i);
        }
        return v;
    }
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int> left = NSL(nums);
        vector<int> right = NSR(nums);
        
        for(int i=0;i<nums.size();i++){
            int len = right[i] - left[i] - 1;
            if(1.0*nums[i] > 1.0*threshold/len)
                return len;
        }
        return -1;
    }
};
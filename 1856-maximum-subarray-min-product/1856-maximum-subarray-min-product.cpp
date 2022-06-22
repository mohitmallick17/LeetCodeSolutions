class Solution {
    vector<int> NSL(vector<int> &v){
        int n=v.size();
        vector<int> res(n);
        stack<int> stk;
        
        for(int i=0;i<n;i++){
            while(!stk.empty() and v[stk.top()] >= v[i])stk.pop();
            res[i] = (stk.empty()) ? -1 : stk.top();
            stk.push(i);
        }
        return res;
    }
    vector<int> NSR(vector<int> &v){
        int n=v.size();
        vector<int> res(n);
        stack<int> stk;
        
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() and v[stk.top()] >= v[i])stk.pop();
            res[i] = (stk.empty()) ? n : stk.top();
            stk.push(i);
        }
        return res;
    }
public:
    int maxSumMinProduct(vector<int>& nums) {
        int64_t sm=0;
        vector<int64_t> Sum(nums.size());
        Sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            Sum[i]=Sum[i-1]+nums[i];
        
        auto nsl = NSL(nums);
        auto nsr = NSR(nums);
        
        int64_t res = 0, mod=1e9+7;
        
        for(int i=0;i<nums.size();i++){
            // int64_t cur_range = nsr[i] - nsl[i] - 1; // i'th number is minimum in cur_range
            int64_t total = ((Sum[nsr[i]-1] - (nsl[i]==-1 ? 0 : Sum[nsl[i]]))*nums[i]);
            
            res = max(res, total);
        }
        return res%mod;
    }
};
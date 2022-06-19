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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ngr=NGR(nums2);
        for(int i=0;i<nums2.size();i++)
            mp[nums2[i]]=i;
        
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            res.push_back(ngr[mp[nums1[i]]]);
        }
        return res;
    }
};
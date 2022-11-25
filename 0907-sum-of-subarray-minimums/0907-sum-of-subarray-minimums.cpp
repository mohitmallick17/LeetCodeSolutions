class Solution {
    vector<int> NSR(vector<int> &v){
        int n=v.size();
        vector<int> res(n);
        
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && v[stk.top()] >= v[i]){
                stk.pop();
            }
            res[i] = (stk.empty()) ? n : stk.top();
            stk.push(i);
        }
        return res;
    }
    vector<int> NSL(vector<int> &v){
        int n=v.size();
        vector<int> res(n);
        
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && v[stk.top()] > v[i]){
                stk.pop();
            }
            res[i] = (stk.empty()) ? -1 : stk.top();
            stk.push(i);
        }
        return res;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        auto nsl = NSL(arr);
        auto nsr = NSR(arr);
        
        // for(auto &x:nsl)cout << x << ' ';
        // cout << '\n';
        // for(auto &x:nsr)cout << x << ' ';
        // cout << '\n';
        
        long long res=0, mod=1e9 + 7;
        for(int i=0;i<arr.size();i++){
            // int cnt = nsr[i] - nsl[i] - 1;
            long long left_cnt = i - nsl[i];
            long long right_cnt = nsr[i] - i;
            // cout << left_cnt << ' ' << right_cnt << '\n';
            res =  (res + (arr[i]*(left_cnt * right_cnt)%mod)%mod)%mod;
        }
        return res;
    }
};
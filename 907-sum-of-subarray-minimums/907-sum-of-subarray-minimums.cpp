class Solution {
    long long mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sums = 0;
        stack<int> stk;
        int n=arr.size();
        
        for(int i=0;i<=n;i++){
            while(!stk.empty() and (i==n or arr[stk.top()] > arr[i])){
                int j = stk.top();
                stk.pop();
                long long right = i-j;
                
                int prevTop = (stk.empty()) ? -1 : stk.top();
                long long left = j-prevTop;
                sums = (sums + (arr[j]*left*right)%mod)%mod;
            }
            stk.push(i);
        }
        return sums;
    }
};
class Solution {
    vector<vector<double>> dp;
    double getSum(vector<int> &presum, int from, int to){
        double ans = 0.0;
        int prev = (from==0) ? 0 : presum[from-1];
        int cur = presum[to];
        ans = 1.0*(cur-prev)/(to-from+1);
        
        return ans;
    }
    double solve(int i, int k, vector<int> &presum, int n){
        if(i==n){
            return 0.0;
        }
        if(k==1){
            int prev = (i>0) ? presum[i-1] : 0;
            return (double)(presum[n-1]-prev)/(n-i);
        }
        if(dp[i][k] != -1)return dp[i][k];
        double ans = 0.0;
        
        for(int idx = i;idx<n;idx++){
            double cur = getSum(presum, i, idx);
            cur += solve(idx+1, k-1, presum, n);
            
            ans = max(ans, cur);
        }
        return dp[i][k]=ans;
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        dp.resize(n, vector<double>(k+1, -1));
        vector<int> presum(n);
        presum[0]=nums[0];
        for(int i=1;i<n;i++)
            presum[i]=presum[i-1]+nums[i];
        return solve(0, k, presum,n);
    }
};